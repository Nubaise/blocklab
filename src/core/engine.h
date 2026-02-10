#pragma once
#include <string>

class Engine
{
public:
    Engine();
    void execute(const std::string &cmd);

private:
    void load();
    void persist(const std::string &cmd);
    std::string classify(const std::string &cmd);
};
