#include "engine.h"
#include <iostream>

void Engine::execute(const std::string &cmd)
{
    std::cout << "[engine] " << cmd << std::endl;
}
