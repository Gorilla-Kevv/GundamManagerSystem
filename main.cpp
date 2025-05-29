#include "manager.h"
#include <iostream>
#include <limits>
#include"utils.h"
#include"Simulater.h"
void printMenu() {
    system("cls");
    printBorder();
    printLine(" MobileSuit ManagementSystem v3.0 ");
    printBorder();
    printLine(" 1. 添加高达机体");
    printLine(" 2. 添加吉姆系列");
    printLine(" 3. 显示所有机体");
    printLine(" 4. 保存数据");
    printLine(" 5. 加载数据");
    printLine(" 6. 模拟启动");
    printLine(" 7. 退出系统");
    endBorder();
    std::cout << "请输入选项：";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void addGundam(GundamManager& manager) {
    std::cout << "\n加载中\n";
	showProgressBar(1);
    std::cout << "\n加载完毕\n";
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
    std::cout << "\n添加中\n";
    showProgressBar(3);
    std::cout << "机体添加成功！" << std::endl;
}

void addGM(GundamManager& manager) {
    std::cout << "\n加载中\n";
    showProgressBar(1);
    std::cout << "\n加载完毕\n";
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
    std::cout << "\n添加中\n";
    showProgressBar(3);
    std::cout << "机体添加成功！" << std::endl;
}


int main() {
    GundamManager manager;
    int choice = 0;
    std::cout << "\n管理系统启动中\n";
	showProgressBar(1);
    std::cout << "\n启动完毕\n";
	system("cls");

    manager.addUnit(make_unique<InfoAddition>("RX-78-2", "高达", "阿姆罗_雷", GundamType::泛用型, 18.0, 43.0, "0079"));
    manager.addUnit(make_unique<GM>("RGM-79G", "陆战型吉姆", "特拉维斯_卡库兰德", GundamType::陆地型, 18.0, 53.8, "0080","08-MS","GMG-0801"));


    
    while (true) {
        printMenu();
        std::cin >> choice;
        clearInputBuffer();
        switch (choice) {
        case 1: addGundam(manager); break;
        case 2: addGM(manager); break;
        case 3: manager.showAll(); break;
        case 4: manager.saveToFile(); break;
        case 5: manager.loadFromFile(); break;
        case 6: startGundam(manager); break; 
        case 7: std::cout << "系统已退出\n"; return 0;
        default: std::cout << "无效输入！\n";
        }
        std::cout << "\n按回车键继续...";
        std::cin.ignore();
    }
}