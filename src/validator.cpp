#include "validator.h"

// Assigns trust badge based on Baseline support
std::string validateFeature(const std::string& feature, const std::map<std::string, bool>& baselineData) {
    auto it = baselineData.find(feature);
    if (it == baselineData.end()) {
        return "⚠️ Unknown";
    }
    return it->second ? "✅ Supported" : "❌ Unsupported";
}
