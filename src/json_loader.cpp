#include "json_loader.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp> // Include this if you're using the popular JSON lib

using json = nlohmann::json;

std::map<std::string, bool> loadBaselineData(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open baseline JSON file\n";
        return {};
    }

    json j;
    file >> j;
    file.close();

    std::map<std::string, bool> baselineMap;
    for (auto& [key, value] : j.items()) {
        baselineMap[key] = value.get<bool>();
    }

    return baselineMap;
}
