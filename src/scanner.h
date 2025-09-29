#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>

// Extracts web features from HTML/CSS/JS content
std::vector<std::string> scanFeatures(const std::string& content);

#endif
