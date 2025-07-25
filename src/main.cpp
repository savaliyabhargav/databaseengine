#include "db/db_engine.h"
#include <iostream>

int main() {
    DatabaseEngine engine;
    std::string command;

    std::cout << "Welcome to CustomDB CLI\n";

    while (true) {
        std::cout << ">> ";
        std::getline(std::cin, command);
        if (command == "exit" || command == "quit")
            break;
        engine.execute(command);
    }

    return 0;
}
