
#include "CLICommands.h"
#include "CommandRegistry.h"
#include <iostream>
#include <string>
#include <algorithm>

void printHeader() {
    std::cout << "    _______      .-'''-.     ,-----.    .-------.     .-''-.     .-'''-.    ____     __  " << std::endl;
    std::cout << "   /   __  \\    / _     \\  .'  .-,  '.  \\  _(`)_ \\  .'_ _   \\   / _     \\   \\   \\   /  / " << std::endl;
    std::cout << "  | ,_/  \\__)  (`' )/`--' / ,-.|  \\ _ \\ | (_ o._)| / ( ` )   ' (`' )/`--'    \\  _. /  '  " << std::endl;
    std::cout << " ,-./  )       (_ o _).   ;  \\  '_ /  | :|  (_,_) /. (_ o _)  |(_ o _).        _( )_ .'   " << std::endl;
    std::cout << " \\  '_ '`)      (_,_). '. |  _`,/ \\ _/  ||   '-.-' |  (_,_)___| (_,_). '.  ___(_ o _)'    " << std::endl;
    std::cout << "  > (_)  )  __ .---.  \\  :: (  '\\_/ \\   ;|   |     '  \\   .---..---.  \\  :|   |(_,_)'     " << std::endl;
    std::cout << " (  .  .-'_/  )\\    `-'  | \\ `\"/  \\  ) / |   |      \\  `-'    /\\    `-'  ||   `-'  /      " << std::endl;
    std::cout << "  `-'`-'     /  \\       /   '. \\_/``\".'  /   )       \\       /  \\       /  \\      /       " << std::endl;
    std::cout << "    `._____.'    `-...-'      '-----'    `---'        `'-..-'    `-...-'    `-..-'          " << std::endl;
    std::cout << "\nWelcome to the CSOPESY Command Line!" << std::endl;
    std::cout << "Type 'exit' to quit , 'clear' to clear the screen" << std::endl;
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
