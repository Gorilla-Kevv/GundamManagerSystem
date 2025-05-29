#include "gundam.h"
#include "manager.h"
#include <iostream>
#include <limits>
using namespace std;
void printMenu() {
    cout << "\n=== GUNDAM ����ϵͳ v1.0 ===" << endl;
    cout << "1. ����»���" << endl;
    cout << "2. ��ʾ���л���" << endl;
    cout << "3. �˳�ϵͳ" << endl;
    cout << "��ѡ�������";
}
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void addGundamInteraction(GundamManager& manager) {
    string model, name, pilot;

    cout << "\n-- ����»��� --" << endl;

    cout << "������ͱ�ţ���ʽRX-xx��: ";
    getline(cin, model);

    cout << "�����������: ";
    getline(cin, name);

    cout << "�����ʻԱ����: ";
    getline(cin, pilot);

    manager.addGundam(GundamList(model, name, pilot));
    cout << "���� " << model << " ��ӳɹ���" << endl;
}
void listGundams(const GundamManager& manager) {
    const auto& list = manager.getList();

    cout << "\n-- ��ע������б��� " << list.size() << " ̨��--" << endl;
    for (const auto& g : list) {
        cout << "����: RX-" << g.getModel() << endl;
        cout << "����: " << g.getName() << endl;
        cout << "��ʻԱ: " << g.getPilot() << endl;
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
    // ��ʼ����ʾ����
    manager.addGundam(GundamList("78-2", "�ߴ�", "��ķ�ޡ���"));
    manager.addGundam(GundamList("Z3", "Zeta�ߴ�", "���ѡ�ά��"));
    do {
        printMenu();

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "���������������������ѡ�" << endl;
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
            cout << "ϵͳ���˳�" << endl;
            break;
        default:
            cout << "��Чѡ�������ѡ��" << endl;
        }
    } while (choice != 3);
    return 0;
}