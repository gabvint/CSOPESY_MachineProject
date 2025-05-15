
#include "CLICommands.h"
#include "CommandRegistry.h"
#include <iostream>
#include <string>
#include <algorithm>

void printHeader() {
    std::cout << "   _,.----.    ,-,--.    _,.---._        _ __       ,----.    ,-,--.                 \n";
    std::cout << " .' .' -   \\ ,-.'-  _\\ ,-.' , -  `.   .-`.' ,`.  ,-.--` , \\ ,-.'-  _\\ ,--.-.  .-,--. \n";
    std::cout << "/==/  ,  ,-'/==/_ ,_.'/==/_,  ,  - \\ /==/, -   \\|==|-  _.-`/==/_ ,_.'/==/- / /=/_ /  \n";
    std::cout << "|==|-   |  .\\==\\  \\  |==|   .=.     |==| _ .=. ||==|   `.-.\\==\\  \\   \\==\\, \\/=/. /   \n";
    std::cout << "|==|_   `-' \\\\==\\ -\\ |==|_ : ;=:  - |==| , '=',/==/_ ,    / \\==\\ -\\   \\==\\  \\/ -/    \n";
    std::cout << "|==|   _  , |_\\==\\ ,\\|==| , '='     |==|-  '..'|==|    .-'  _\\==\\ ,\\   |==|  ,_/      \n";
    std::cout << "\\==\\.       /==/\\/ _ |\\==\\ -    ,_ /|==|,  |   |==|_  ,`-._/==/\\/ _ |  \\==\\-, /       \n";
    std::cout << " `-.`.___.-'\\==\\ - , / '.='. -   .' /==/ - |   /==/ ,     /\\==\\ - , /  /==/._/        \n";
    std::cout << "             `--`---'    `--`--''   `--`---'   `--`-----``  `--`---'   `--`-`         \n";
    std::cout << "\nWelcome to the CSOPESY Command Line!" << std::endl;
    std::cout << "Type 'exit' to quit, 'clear' to clear the screen." << std::endl;
}


void mainMenu() {
    auto commands = getCommandMap();
    std::string command;

    while (true) {
        std::cout << "\nEnter a command: ";
        std::getline(std::cin, command);

        // Normalize to lowercase
        std::transform(command.begin(), command.end(), command.begin(), ::tolower);

        // Look up and run command
        auto it = commands.find(command);
        if (it != commands.end()) {
            it->second(); // Call the function
        }
        else {
            std::cout << "Unknown command: " << command << ". Please try again." << std::endl;
        }
    }
}
