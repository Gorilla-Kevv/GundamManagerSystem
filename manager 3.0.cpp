#include "manager.h"
#include <iostream>
#include<sstream>
#include <limits>
#include"utils.h"
#include"Simulater.h"

using namespace std;


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
    std::cout << "\n������\n";
	showProgressBar(1);
    std::cout << "�����ѱ����� " << DATA_FILE << std::endl;
}


void GundamManager::loadFromFile() {

	units.clear(); 
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
        showProgressBar(1);
        std::cout << "��ȡ��: " << line << std::endl; 

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

string formatDecimal(double value, int precision) {
    std::ostringstream oss;
    oss.precision(precision);
    oss << std::fixed << value;
    return oss.str();
}


void GundamManager::showAll() const {

    std::cout << "\n������\n";
    showProgressBar(3);
    std::cout << "\n�������\n";

    const int BOX_WIDTH = 64;
    printBorder(BOX_WIDTH);
    printLine(" �����б� [�� " + std::to_string(units.size()) + " ̨] ", BOX_WIDTH);


    for (const auto& unit : units) {
        printBorder(BOX_WIDTH);

        auto formatLine = [&](const std::string& content) {
            int padding = BOX_WIDTH - content.size() - 4; // �������ո�����
            return "�U " + content + std::string(padding, ' ') + " �U";
            };


        std::cout << formatLine(" ����: " + unit->getModel()) << std::endl;
        std::cout << formatLine(" ����: " + unit->getName()) << std::endl;

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << formatLine(" ����: " + gm->getTypeName()) << std::endl;
        }
        else {
            std::cout << formatLine(" ����: " + unit->getTypeName()) << std::endl;
        }
        
        
        std::cout << formatLine(" ��ʻԱ: " + unit->getPilot()) << std::endl;
        std::cout << formatLine(" �߶�: " + formatDecimal(unit->getHeight(),1) + "m") << std::endl;
        std::cout << formatLine(" ����: " + formatDecimal(unit->getWeight(),1) + "��") << std::endl;
        std::cout << formatLine(" �������: " + unit->getBuildYear()) << std::endl;

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << formatLine(" ��������ID: " + gm->getGroupID()) << std::endl;
            std::cout << formatLine(" �������κ�: " + gm->getProduceSerial()) << std::endl;
        }
    }
    printBorder(BOX_WIDTH);
    endBorder(BOX_WIDTH);
}


