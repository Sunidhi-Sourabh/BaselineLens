#include "fallback.h"
#include <unordered_map>

// Hardcoded fallback suggestions for demo clarity
std::string suggestFallback(const std::string& feature) {
    static std::unordered_map<std::string, std::string> fallbackMap = {
        {"grid", "Use flexbox for layout"},
        {"fetch", "Use XMLHttpRequest or axios"},
        {":has(", "Avoid complex selectors; restructure DOM"},
        {"async", "Use defer or inline scripts"},
        {"defer", "Use async or inline scripts"},
        {"let", "Use var for older browser support"},
        {"const", "Use var if immutability isn’t critical"}
    };

    auto it = fallbackMap.find(feature);
    if (it != fallbackMap.end()) {
        return it->second;
    }
    return "No fallback available";
}
