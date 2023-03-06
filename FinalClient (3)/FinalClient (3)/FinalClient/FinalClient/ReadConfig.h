#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::ifstream file("config.ini");
std::string line;
std::string key, value;
int returnTimer()
{
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::getline(iss, key, '=');
        std::getline(iss, value);
    }
    file.close();
    return stoi(value);
}