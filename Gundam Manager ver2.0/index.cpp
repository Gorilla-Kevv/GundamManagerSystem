#include "manager.h"
#include <iostream>
#include <limits>


void printMenu() {
    std::cout << "\n=== Mobile Suit 管理系统 v2.0 ==="
        << "\n1. 添加高达机体"
        << "\n2. 添加吉姆系列"
        << "\n3. 显示所有机体"
        << "\n4. 保存数据"
        << "\n5. 加载数据"
        << "\n6. 退出系统"
        << "\n请选择操作：";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void addGundam(GundamManager& manager) {
    string model, name, pilot;
    int type;
    double height, weight;
    string buildYear;


    cout << "\n-- 添加新机体 --" << endl;
    cout << "机型编号（RX/MSZ/MSN/MSA/MSK-XX): ";
    getline(cin, model);
    cout << "名称: ";
    getline(cin, name);
    cout << "驾驶员: ";
    getline(cin, pilot);
    
    do {
        std::cout << "类型 (1.陆地 2.空战 3.宇宙 4.泛用): ";
        std::cin >> type;
    } while (type < 1 || type > 4);

    cout << "高度(m): ";
    cin >> height;
    cout << "重量(ton): ";
    cin >> weight;
    clearInputBuffer();
    
    cout << "生产年份: ";
	cin >> buildYear;

    clearInputBuffer();

    manager.addUnit(
        make_unique<InfoAddition>(model, 
            name, 
            pilot,
            static_cast<GundamType>(type - 1),
            height, weight, 
            buildYear
        )
    );
    std::cout << "机体添加成功！" << std::endl;
}

void addGM(GundamManager& manager) {
    string model, name, pilot;

    double height, weight;
    string buildYear;
    int type;
    string serial;
    string groupID;


    cout << "\n-- 添加新机体 --" << endl;
    cout << "机型编号(RGM/GM/RMS/RGS): ";
    getline(cin, model);
    cout << "名称: ";
    getline(cin, name);
    cout << "驾驶员: ";
    getline(cin, pilot);

    do {
        std::cout << "类型 (1.陆地 2.空战 3.宇宙 4.泛用): ";
        std::cin >> type;
    } while (type < 1 || type > 4);

    cout << "高度(m): ";
    cin >> height;
    cout << "重量(ton): ";
    cin >> weight;
    cout << "生产年份: ";
	cin >> buildYear;

    clearInputBuffer();
    cout << "隶属部队ID: ";
	cin >> groupID;
    clearInputBuffer();
    cout << "生产批次号(格式:XXX-XXXX): ";
	cin >> serial;

    clearInputBuffer();

    manager.addUnit(
        make_unique<GM>(model, 
            name, 
            pilot,
            static_cast<GundamType>(type - 1),
            height, weight, 
            buildYear, 
            groupID, 
            serial
        )
    );
    std::cout << "机体添加成功！" << std::endl;
}


int main() {
    GundamManager manager;
    int choice = 0;
    


    manager.addUnit(make_unique<InfoAddition>("78-2", "高达", "阿姆罗·雷", GundamType::陆地型, 18.0, 43.0, "0079"));
    manager.addUnit(make_unique<InfoAddition>("MSZ-006", "Z高达", "卡缪·维丹", GundamType::宇宙型, 19.0, 45.0, "0087"));


    while (true) {
        printMenu();
        std::cin >> choice;
        clearInputBuffer();
        switch (choice) {
        case 1:
            addGundam(manager);
            break;
        case 2:
            addGM(manager);
            break;
        case 3:
            manager.showAll();
            break;
        case 4:
            manager.saveToFile();
            break;
        case 5:
            manager.loadFromFile();
            break;
        case 6:
            std::cout << "系统已退出" << std::endl;
            return 0;
        default:
            std::cout << "输入错误，请重新输入！" << std::endl;
        }
    }
}