#include "engine.h"
#include <iostream>

void Engine::execute(const std::string &cmd)
{
    std::cout << "[engine] received command: " << cmd << std::endl;
}
