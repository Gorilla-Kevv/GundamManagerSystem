#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "utils.h"

// ������
void showProgressBar(int seconds) {
    
    for (int i = 0; i <= 100; i += 2) {
        std::cout << "[";
        for (int j = 0; j < 50; j++) {
            if (j < i / 2) std::cout << "��";
            else std::cout << " ";
        }
        std::cout << "] " << i << "%\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 10));
    }
	
    std::cout << "\n\n";
}

// �߿�
void printBorder(int width) {
    std::cout << "�X";
    for (int i = 0; i < width - 2; ++i) std::cout << "�T";
    std::cout << "�[\n";
}

// �ı�biankuang
void printLine(const std::string& text, int width) {
    std::cout << "�U " << std::left << std::setw(width - 4) << text << " �U\n";
}

void endBorder(int width) {
    std::cout << "�^";
    for (int i = 0; i < width - 2; ++i) std::cout << "�T";
    std::cout << "�a\n";
}
