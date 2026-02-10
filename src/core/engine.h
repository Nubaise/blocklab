#pragma once
#include <string>
#include <vector>

class Engine
{
public:
    Engine();
    void execute(const std::string &cmd);

private:
    void load();
    void persist(const std::string &cmd);

    std::vector<std::string> history;
};
