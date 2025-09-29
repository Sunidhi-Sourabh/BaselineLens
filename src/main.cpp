#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"
#include "json_loader.h"
#include "validator.h"

int main(int argc, char* argv[]) {
    if (argc != 3 || std::string(argv[1]) != "validate") {
        std::cerr << "Usage: baselinelens validate <filename>\n";
        return 1;
    }

    std::string filename = argv[2];
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    file.close();

    std::vector<std::string> features = scanFeatures(content);
    std::map<std::string, bool> baselineData = loadBaselineData("data/baseline_features.json");

    for (const auto& feature : features) {
        std::string badge = validateFeature(feature, baselineData);
        std::cout << "Feature: " << feature << " → " << badge << "\n";
    }

    return 0;
}
