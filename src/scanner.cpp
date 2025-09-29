#include "scanner.h"
#include <regex>
#include <set>

// Simple regex-based feature extraction
std::vector<std::string> scanFeatures(const std::string& content) {
    std::set<std::string> features;
    std::regex featureRegex(R"(\b(grid|fetch|flex|:has\(|async|defer|let|const)\b)");
    auto wordsBegin = std::sregex_iterator(content.begin(), content.end(), featureRegex);
    auto wordsEnd = std::sregex_iterator();

    for (std::sregex_iterator i = wordsBegin; i != wordsEnd; ++i) {
        features.insert(i->str());
    }

    return std::vector<std::string>(features.begin(), features.end());
}
