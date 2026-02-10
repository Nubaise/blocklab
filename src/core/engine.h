#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class Engine
{
public:
    Engine();
    void execute(const std::string &cmd);

private:
    void load();
    void persist(const std::string &cmd);

    // stage 4
    void loadTables();
    void createTable(const std::string &cmd);

    std::string classify(const std::string &cmd);

    // tableName -> list of columns
    std::unordered_map<std::string, std::vector<std::string>> tables;
};
