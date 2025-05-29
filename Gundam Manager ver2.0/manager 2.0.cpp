
#include "manager.h"
#include <iostream>
#include<sstream>
#include <limits>
using namespace std;

const int TERMINAL_WIDTH = 80;


void GundamManager::addUnit(unique_ptr<InfoAddition> unit) {
    units.push_back(std::move(unit));
}

void GundamManager::saveToFile() {
    std::ofstream file(DATA_FILE);
    if (!file) {
        std::cerr << "�޷����������ļ���" << std::endl;
        return;
    }
    for (const auto& unit : units) {
        file << (unit->isGM() ? "GM," : "GUNDAM,");
        unit->save(file);
        file << "\n";
    }
    std::cout << "�����ѱ����� " << DATA_FILE << std::endl;
}


void GundamManager::loadFromFile() {
    std::ifstream file(DATA_FILE);
    if (!file) {
        std::cerr << "�޷��������ļ���" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // ��������
        }

        std::istringstream iss(line);
        std::string type;
        std::getline(iss, type, ',');

        if (type == "GM") {
            createFromStream(iss, "GM");
        }
        else if (type == "GUNDAM") {
            createFromStream(iss, "GUNDAM");
        }
        else {
            std::cerr << "δ֪�Ļ������ͣ�" << type << std::endl;
        }
    }

    std::cout << "�����Ѽ��ء�" << std::endl;
}


void GundamManager::createFromStream(istream& is, const string& type) {
    if (type == "GM") {
        auto gm = make_unique<GM>("", "", "", GundamType::½����, 0, 0,"", "", "");
        gm->load(is);
        units.push_back(move(gm));
    }
    else {
        auto gundam = make_unique<InfoAddition>("", "", "", GundamType::½����, 0, 0,"");
        gundam->load(is);
        units.push_back(move(gundam));
    }
}

void GundamManager::showAll() const {
    std::cout << "\n=== �����б��� " << units.size() << " ̨��====" << std::endl;
    for (const auto& unit : units) {
        std::cout << "����: " << unit->getModel()
            << "\n����: " << unit->getName()
            << "\n����: " << unit->getTypeName()
            << "\n��ʻԱ: " << unit->getPilot()
            << "\n�߶�: " << unit->getHeight() << "m"
            << "\n����: " << unit->getWeight() << "��"
            << "\n�������: " << unit->getBuildYear()<<"��";

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << "\n��������ID: " << gm->getGroupID()
                << "\n�������κ�: " << gm->getProduceSerial();
			         
        }
        std::cout << "\n------------------------\n";
    }
}


