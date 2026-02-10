#include "engine.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cctype>

static const char *DATA_FILE = "data.log";
static const char *TABLE_FILE = "tables.meta";

Engine::Engine()
{
    load();
    loadTables();
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
        std::cout << line << std::endl;
    }
    std::cout << std::endl;
}

void Engine::persist(const std::string &cmd)
{
    std::ofstream out(DATA_FILE, std::ios::app);
    out << cmd << "\n";
}

std::string Engine::classify(const std::string &cmd)
{
    std::istringstream iss(cmd);
    std::string first;
    iss >> first;

    for (char &c : first)
        c = std::toupper(c);

    if (first == "CREATE")
        return "CREATE";
    if (first == "INSERT")
        return "INSERT";
    if (first == "SELECT")
        return "SELECT";
    if (first == "DELETE")
        return "DELETE";
    if (first == "DROP")
        return "DROP";

    return "UNKNOWN";
}

void Engine::execute(const std::string &cmd)
{
    std::string type = classify(cmd);

    if (type == "CREATE")
    {
        createTable(cmd);
    }
    else
    {
        std::cout << "[engine] command type: " << type << std::endl;
    }
}

void Engine::loadTables()
{
    std::ifstream in(TABLE_FILE);
    std::string line;

    if (!in.is_open())
        return;

    while (std::getline(in, line))
    {
        std::istringstream iss(line);
        std::string table;
        std::getline(iss, table, ':');

        std::string cols;
        std::getline(iss, cols);

        std::vector<std::string> columns;
        std::istringstream cstream(cols);
        std::string col;

        while (std::getline(cstream, col, ','))
        {
            columns.push_back(col);
        }

        tables[table] = columns;
    }
}

void Engine::createTable(const std::string &cmd)
{
    // Expected: CREATE TABLE name (a,b,c)
    std::istringstream iss(cmd);
    std::string tmp, table;

    iss >> tmp; // CREATE
    iss >> tmp; // TABLE
    iss >> table;

    std::string rest;
    std::getline(iss, rest);

    auto l = rest.find('(');
    auto r = rest.find(')');

    if (l == std::string::npos || r == std::string::npos)
    {
        std::cout << "[engine] syntax error\n";
        return;
    }

    std::string cols = rest.substr(l + 1, r - l - 1);

    std::vector<std::string> columns;
    std::istringstream cstream(cols);
    std::string col;

    while (std::getline(cstream, col, ','))
    {
        columns.push_back(col);
    }

    tables[table] = columns;

    std::ofstream out(TABLE_FILE, std::ios::app);
    out << table << ":" << cols << "\n";

    std::cout << "[engine] table created: " << table << std::endl;
}
