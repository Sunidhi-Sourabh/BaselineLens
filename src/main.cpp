#include <iostream>
#include <fstream>
#include <string>
#include "scanner.h"
#include "json_loader.h"
#include "validator.h"
#include "fallback.h"

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
    std::map<std::string, bool> baselineData = loadBaselineData("src/baseline_features.json");

    std::cout << "\n🔍 Scanned Features:\n";
    for (const auto& feature : features) {
        std::string badge = validateFeature(feature, baselineData);
        std::cout << "• " << feature << " → " << badge << "\n";

        if (badge != "✅ Supported") {
            std::string fallback = suggestFallback(feature);
            std::cout << "  ↪ Fallback: " << fallback << "\n";
        }
    }

    std::cout << "\n✅ Validation complete.\n";
    return 0;
}
