#include "CommandRegistry.h"
#include "CLICommands.h" // for printHeader
#include <iostream>
#include <cstdlib>



void handleExit() {
    std::cout << "Exit command recognized. Closing the program." << std::endl;
    exit(0);
}

void handleClear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printHeader();
}

void handleInitialize() {
    std::cout << "initialize command recognized. Doing something." << std::endl;
}

void handleScreen() {
    std::cout << "screen command recognized. Doing something." << std::endl;
}

void handleSchedulerTest() {
    std::cout << "scheduler-test command recognized. Doing something." << std::endl;
}

void handleSchedulerStop() {
    std::cout << "scheduler-stop command recognized. Doing something." << std::endl;
}

void handleReportUtil() {
    std::cout << "report-util command recognized. Doing something." << std::endl;
}

// Create and return the command map
std::unordered_map<std::string, CommandFunction> getCommandMap() {
    return {
        {"exit", handleExit},
        {"clear", handleClear},
        {"initialize", handleInitialize},
        {"screen", handleScreen},
        {"scheduler-test", handleSchedulerTest},
        {"scheduler-stop", handleSchedulerStop},
        {"report-util", handleReportUtil}
    };
}
