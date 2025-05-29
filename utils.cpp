#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "utils.h"

// 进度条
void showProgressBar(int seconds) {
    
    for (int i = 0; i <= 100; i += 2) {
        std::cout << "[";
        for (int j = 0; j < 50; j++) {
            if (j < i / 2) std::cout << "█";
            else std::cout << " ";
        }
        std::cout << "] " << i << "%\r";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(seconds * 10));
    }
	
    std::cout << "\n\n";
}

// 边框
void printBorder(int width) {
    std::cout << "╔";
    for (int i = 0; i < width - 2; ++i) std::cout << "═";
    std::cout << "╗\n";
}

// 文本biankuang
void printLine(const std::string& text, int width) {
    std::cout << "║ " << std::left << std::setw(width - 4) << text << " ║\n";
}

void endBorder(int width) {
    std::cout << "╚";
    for (int i = 0; i < width - 2; ++i) std::cout << "═";
    std::cout << "╝\n";
}
