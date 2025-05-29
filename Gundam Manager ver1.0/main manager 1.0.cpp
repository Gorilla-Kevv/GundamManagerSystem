#include "gundam.h"
#include "manager.h"
#include <iostream>
#include <limits>
using namespace std;
void printMenu() {
    cout << "\n=== GUNDAM 管理系统 v1.0 ===" << endl;
    cout << "1. 添加新机体" << endl;
    cout << "2. 显示所有机体" << endl;
    cout << "3. 退出系统" << endl;
    cout << "请选择操作：";
}
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void addGundamInteraction(GundamManager& manager) {
    string model, name, pilot;

    cout << "\n-- 添加新机体 --" << endl;

    cout << "输入机型编号（格式RX-xx）: ";
    getline(cin, model);

    cout << "输入机体名称: ";
    getline(cin, name);

    cout << "输入驾驶员姓名: ";
    getline(cin, pilot);

    manager.addGundam(GundamList(model, name, pilot));
    cout << "机体 " << model << " 添加成功！" << endl;
}
void listGundams(const GundamManager& manager) {
    const auto& list = manager.getList();

    cout << "\n-- 已注册机体列表（共 " << list.size() << " 台）--" << endl;
    for (const auto& g : list) {
        cout << "机型: RX-" << g.getModel() << endl;
        cout << "名称: " << g.getName() << endl;
        cout << "驾驶员: " << g.getPilot() << endl;
        cout << "------------------------" << endl;
    }
}
void GundamManager::addGundam(const GundamList& g) {
    gundams.push_back(g);
}
const vector<GundamList>& GundamManager::getList() const {
    return gundams;
}
int main() {
    GundamManager manager;
    int choice = 0;
    // 初始化演示数据
    manager.addGundam(GundamList("78-2", "高达", "阿姆罗·雷"));
    manager.addGundam(GundamList("Z3", "Zeta高达", "卡缪·维丹"));
    do {
        printMenu();

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "输入错误，请重新输入数字选项！" << endl;
            continue;
        }
        clearInputBuffer();
        switch (choice) {
        case 1:
            addGundamInteraction(manager);
            break;
        case 2:
            listGundams(manager);
            break;
        case 3:
            cout << "系统已退出" << endl;
            break;
        default:
            cout << "无效选项，请重新选择！" << endl;
        }
    } while (choice != 3);
    return 0;
}