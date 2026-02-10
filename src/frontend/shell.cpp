#include "shell.h"
#include <iostream>
#include <string>

void Shell::run()
{
    std::string input;

    std::cout << "blocklab> ";
    while (std::getline(std::cin, input))
    {
        if (input == ".exit")
            break;

        std::cout << "echo: " << input << std::endl;
        std::cout << "blocklab> ";
    }

    std::cout << "bye\n";
}
