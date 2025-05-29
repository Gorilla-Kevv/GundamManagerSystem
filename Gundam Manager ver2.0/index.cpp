#include "manager.h"
#include <iostream>
#include <limits>


void printMenu() {
    std::cout << "\n=== Mobile Suit ����ϵͳ v2.0 ==="
        << "\n1. ��Ӹߴ����"
        << "\n2. ��Ӽ�ķϵ��"
        << "\n3. ��ʾ���л���"
        << "\n4. ��������"
        << "\n5. ��������"
        << "\n6. �˳�ϵͳ"
        << "\n��ѡ�������";
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
    std::cout << "������ӳɹ���" << std::endl;
}

void addGM(GundamManager& manager) {
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
    std::cout << "������ӳɹ���" << std::endl;
}


int main() {
    GundamManager manager;
    int choice = 0;
    


    manager.addUnit(make_unique<InfoAddition>("78-2", "�ߴ�", "��ķ�ޡ���", GundamType::½����, 18.0, 43.0, "0079"));
    manager.addUnit(make_unique<InfoAddition>("MSZ-006", "Z�ߴ�", "���ѡ�ά��", GundamType::������, 19.0, 45.0, "0087"));


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
            std::cout << "ϵͳ���˳�" << std::endl;
            return 0;
        default:
            std::cout << "����������������룡" << std::endl;
        }
    }
}