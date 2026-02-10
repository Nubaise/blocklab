#include "shell.h"
#include <iostream>
#include <string>

Shell::Shell() {}

void Shell::run()
{
    std::string input;

    std::cout << "blocklab> ";
    while (std::getline(std::cin, input))
    {

        if (input == ".exit")
        {
            break;
        }

        if (input == ".help")
        {
            std::cout << "Commands:\n";
            std::cout << "  .help     Show help\n";
            std::cout << "  .exit     Exit shell\n";
            std::cout << "  SQL-like commands are forwarded to engine\n";
            std::cout << std::endl;
        }
        else
        {
            engine.execute(input);
        }

        std::cout << "blocklab> ";
    }

    std::cout << "bye\n";
}
