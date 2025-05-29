#include "simulater.h"
void simulateOperation(const InfoAddition& unit) {
    system("cls");
    printBorder(64); 
    printLine(" " + unit.getName() + " 控制台已连接", 64); 

    const std::vector<std::string> gundamText = {
        "G ------------ Generalpurpose",
        "U ------------ Utility",
        "N ------------ Non",
        "D ------------ Discontinuty",
        "A ------------ Augmentation",
        "M ------------ Mannuenvering Weapon System"
    };

    for (const auto& line : gundamText) {
        std::cout << "║ "; // 左边框
        for (const char& ch : line) {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20)); // 每个字符延迟20毫秒
        }
        std::cout << std::string(64 - line.size() - 3, ' ') << "║" << std::endl; // 右边框和填充空格
    }

    endBorder(64);

	printLine(" 模拟操作系统已启动",64);
    printBorder(64);
    printLine(" 操作指令列表:",64);
    printLine("  engine [start/stop] - 动力系统控制",64);
    printLine("  weapon [load/fire]  - 武器系统操作",64);
    printLine("  sensor [scan]       - 环境侦测",64);
    printLine("  exit                - 关闭系统",64);
    printBorder(64);


    std::string cmd;
    while (true) {
        std::cout << "\n>>> 输入指令: ";
        std::getline(std::cin, cmd);

        if (cmd == "exit") break;

        else if (cmd.find("engine") != std::string::npos) {
            if (cmd.find("start") != std::string::npos) {
                std::cout << "核融合引擎启动 >>>>>> 出力120%！\n";
            }
            else if (cmd.find("stop") != std::string::npos) {
                std::cout << "引擎关闭 ▼▼▼ 进入待机状态\n";
            }
        }
        else if (cmd.find("weapon") != std::string::npos) {
            if (cmd.find("fire") != std::string::npos) {
                std::cout << "███ 光束步枪发射！ ███\n";
            }
            else if (cmd.find("load") != std::string::npos) {
                std::cout << "装填弹药... 剩余能量85%\n";
            }
        }
        else if (cmd.find("sensor") != std::string::npos) {
            std::cout << "扫描周围环境... 未发现敌对目标\n";
        }
        else {
            std::cout << "未知指令，请输入有效命令\n";
        }
    }
}

void startGundam(GundamManager& mgr) {

    std::cout << "\n机体模拟列表启动中\n";
    showProgressBar(3);
    std::cout << "\n启动完毕\n";

    const auto& units = mgr.getUnits();
    if (units.empty()) {
        std::cout << "错误：无可用机体！\n";
        return;
    }
    system("cls");
    printBorder();
    printLine(" 可用机体列表:");
    for (size_t i = 0; i < units.size(); ++i) {
        printLine(" " + std::to_string(i + 1) + ". "
            + units[i]->getModel() + " - "
            + units[i]->getName());
    }
    endBorder();
    int choice;
    std::cout << "请选择要启动的机体编号：";
    std::cin >> choice;
    std::cin.ignore();

    if (choice < 1 || choice > units.size()) {
        std::cout << "无效选择！\n";
        return;
    }
    system("cls");
    std::cout << "\n模拟系统启动中\n";
    showProgressBar(4);
    simulateOperation(*units[choice - 1]);
}
