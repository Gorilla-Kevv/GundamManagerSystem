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
    printLine(" 1. ��Ӹߴ����");
    printLine(" 2. ��Ӽ�ķϵ��");
    printLine(" 3. ��ʾ���л���");
    printLine(" 4. ��������");
    printLine(" 5. ��������");
    printLine(" 6. ģ������");
    printLine(" 7. �˳�ϵͳ");
    endBorder();
    std::cout << "������ѡ�";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void addGundam(GundamManager& manager) {
    std::cout << "\n������\n";
	showProgressBar(1);
    std::cout << "\n�������\n";
    string model, name, pilot;
    int type;
    double height, weight;
    string buildYear;


    cout << "\n-- ����»��� --" << endl;
    cout << "���ͱ�ţ�RX/MSZ/MSN/MSA/MSK-XX): ";
    getline(cin, model);
    cout << "����: ";
    getline(cin, name);
    cout << "��ʻԱ: ";
    getline(cin, pilot);
    
    do {
        std::cout << "���� (1.½�� 2.��ս 3.���� 4.����): ";
        std::cin >> type;
    } while (type < 1 || type > 4);

    cout << "�߶�(m): ";
    cin >> height;
    cout << "����(ton): ";
    cin >> weight;
    clearInputBuffer();
    
    cout << "�������: ";
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
    std::cout << "\n�����\n";
    showProgressBar(3);
    std::cout << "������ӳɹ���" << std::endl;
}

void addGM(GundamManager& manager) {
    std::cout << "\n������\n";
    showProgressBar(1);
    std::cout << "\n�������\n";
    string model, name, pilot;

    double height, weight;
    string buildYear;
    int type;
    string serial;
    string groupID;


    cout << "\n-- ����»��� --" << endl;
    cout << "���ͱ��(RGM/GM/RMS/RGS): ";
    getline(cin, model);
    cout << "����: ";
    getline(cin, name);
    cout << "��ʻԱ: ";
    getline(cin, pilot);

    do {
        std::cout << "���� (1.½�� 2.��ս 3.���� 4.����): ";
        std::cin >> type;
    } while (type < 1 || type > 4);

    cout << "�߶�(m): ";
    cin >> height;
    cout << "����(ton): ";
    cin >> weight;
    cout << "�������: ";
	cin >> buildYear;

    clearInputBuffer();
    cout << "��������ID: ";
	cin >> groupID;
    clearInputBuffer();
    cout << "�������κ�(��ʽ:XXX-XXXX): ";
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
    std::cout << "\n�����\n";
    showProgressBar(3);
    std::cout << "������ӳɹ���" << std::endl;
}


int main() {
    GundamManager manager;
    int choice = 0;
    std::cout << "\n����ϵͳ������\n";
	showProgressBar(1);
    std::cout << "\n�������\n";
	system("cls");

    manager.addUnit(make_unique<InfoAddition>("RX-78-2", "�ߴ�", "��ķ��_��", GundamType::������, 18.0, 43.0, "0079"));
    manager.addUnit(make_unique<GM>("RGM-79G", "½ս�ͼ�ķ", "����ά˹_��������", GundamType::½����, 18.0, 53.8, "0080","08-MS","GMG-0801"));


    
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
        case 7: std::cout << "ϵͳ���˳�\n"; return 0;
        default: std::cout << "��Ч���룡\n";
        }
        std::cout << "\n���س�������...";
        std::cin.ignore();
    }
}