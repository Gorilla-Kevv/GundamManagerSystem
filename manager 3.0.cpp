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
        std::cerr << "无法创建数据文件！" << std::endl;
        return;
    }
    
    for (const auto& unit : units) {
        file << (unit->isGM() ? "GM," : "GUNDAM,");
        unit->save(file);
        file << "\n";
    }
    std::cout << "\n保存中\n";
	showProgressBar(1);
    std::cout << "数据已保存至 " << DATA_FILE << std::endl;
}


void GundamManager::loadFromFile() {

	units.clear(); 
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
        showProgressBar(1);
        std::cout << "读取行: " << line << std::endl; 

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

string formatDecimal(double value, int precision) {
    std::ostringstream oss;
    oss.precision(precision);
    oss << std::fixed << value;
    return oss.str();
}


void GundamManager::showAll() const {

    std::cout << "\n加载中\n";
    showProgressBar(3);
    std::cout << "\n加载完毕\n";

    const int BOX_WIDTH = 64;
    printBorder(BOX_WIDTH);
    printLine(" 机体列表 [共 " + std::to_string(units.size()) + " 台] ", BOX_WIDTH);


    for (const auto& unit : units) {
        printBorder(BOX_WIDTH);

        auto formatLine = [&](const std::string& content) {
            int padding = BOX_WIDTH - content.size() - 4; // 计算填充空格数量
            return "║ " + content + std::string(padding, ' ') + " ║";
            };


        std::cout << formatLine(" 机型: " + unit->getModel()) << std::endl;
        std::cout << formatLine(" 名称: " + unit->getName()) << std::endl;

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << formatLine(" 类型: " + gm->getTypeName()) << std::endl;
        }
        else {
            std::cout << formatLine(" 类型: " + unit->getTypeName()) << std::endl;
        }
        
        
        std::cout << formatLine(" 驾驶员: " + unit->getPilot()) << std::endl;
        std::cout << formatLine(" 高度: " + formatDecimal(unit->getHeight(),1) + "m") << std::endl;
        std::cout << formatLine(" 重量: " + formatDecimal(unit->getWeight(),1) + "吨") << std::endl;
        std::cout << formatLine(" 生产年份: " + unit->getBuildYear()) << std::endl;

        if (unit->isGM()) {
            const GM* gm = dynamic_cast<const GM*>(unit.get());
            std::cout << formatLine(" 隶属部队ID: " + gm->getGroupID()) << std::endl;
            std::cout << formatLine(" 生产批次号: " + gm->getProduceSerial()) << std::endl;
        }
    }
    printBorder(BOX_WIDTH);
    endBorder(BOX_WIDTH);
}


