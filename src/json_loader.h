#ifndef JSON_LOADER_H
#define JSON_LOADER_H

#include <string>
#include <map>

// Loads Baseline feature support from JSON file
std::map<std::string, bool> loadBaselineData(const std::string& filepath);

#endif
