
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
        std::cerr << "无法创建数据文件！" << std::endl;
        return;
    }
    for (const auto& unit : units) {
        file << (unit->isGM() ? "GM," : "GUNDAM,");
        unit->save(file);
        file << "\n";
    }
    std::cout << "数据已保存至 " << DATA_FILE << std::endl;
}


void GundamManager::loadFromFile() {
    std::ifstream file(DATA_FILE);
    if (!file) {
        std::cerr << "无法打开数据文件！" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue; // 跳过空行
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
            std::cerr << "未知的机体类型：" << type << std::endl;
        }
    }

    std::cout << "数据已加载。" << std::endl;
}


void GundamManager::createFromStream(istream& is, const string& type) {
    if (type == "GM") {
        auto gm = make_unique<GM>("", "", "", GundamType::陆地型, 0, 0,"", "", "");
        gm->load(is);
        units.push_back(move(gm));
    }
    else {
        auto gundam = make_unique<InfoAddition>("", "", "", GundamType::陆地型, 0, 0,"");
        gundam->load(is);
        units.push_back(move(gundam));
    }
}

void GundamManager::showAll() const {
    std::cout << "\n=== 机体列表（共 " << units.size() << " 台）====" << std::endl;
    for (const auto& unit : units) {
        std::cout << "机型: " << unit->getModel()
            << "\n名称: " << unit->getName()
            << "\n类型: " << unit->getTypeName()
            << "\n驾驶员: " << unit->getPilot()
            << "\n高度: " << unit->getHeight() << "m"
            << "\n重量: " << unit->getWeight() << "吨"
            << "\n生产年份: " << unit->getBuildYear()<<"年";

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << "\n隶属部队ID: " << gm->getGroupID()
                << "\n生产批次号: " << gm->getProduceSerial();
			         
        }
        std::cout << "\n------------------------\n";
    }
}


