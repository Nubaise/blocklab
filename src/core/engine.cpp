#include "engine.h"
#include <fstream>
#include <iostream>

static const char *DATA_FILE = "data.log";

Engine::Engine()
{
    load();
}

void Engine::load()
{
    std::ifstream in(DATA_FILE);
    std::string line;

    if (!in.is_open())
        return;

    std::cout << "[engine] loaded previous data:\n";

    while (std::getline(in, line))
    {
        history.push_back(line);
        std::cout << line << std::endl;
    }

    std::cout << std::endl;
}

void Engine::persist(const std::string &cmd)
{
    std::ofstream out(DATA_FILE, std::ios::app);
    out << cmd << "\n";
}

void Engine::execute(const std::string &cmd)
{
    history.push_back(cmd);
    persist(cmd);

    std::cout << "[engine] stored: " << cmd << std::endl;
}
