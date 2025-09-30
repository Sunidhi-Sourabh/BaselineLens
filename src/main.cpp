#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>
#include <cstdlib> // for system()
#include "scanner.h"
#include "json_loader.h"
#include "validator.h"
#include "fallback.h"

using json = nlohmann::json;

int main(int argc, char* argv[]) {
    std::string filename;
    bool exportMarkdown = false;
    bool exportHTML = false;
    bool quietMode = false;
    bool jsonMode = false;
    bool demoMode = false;
    bool scoreMode = false;

    if (argc < 3 || std::string(argv[1]) != "validate") {
        std::cerr << "Usage: baselinelens validate <filename> [--export] [--html] [--quiet] [--json] [--demo] [--score]\n";
        return 1;
    }

    filename = argv[2];
    for (int i = 3; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--export") exportMarkdown = true;
        else if (arg == "--html") exportHTML = true;
        else if (arg == "--quiet") quietMode = true;
        else if (arg == "--json") jsonMode = true;
        else if (arg == "--demo") demoMode = true;
        else if (arg == "--score") scoreMode = true;
    }

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Error: Cannot open file " << filename << "\n";
        return 1;
    }

    std::string content((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    file.close();

    std::vector<std::string> features = scanFeatures(content);
    std::map<std::string, bool> baselineData = loadBaselineData("baseline_features.json");

    json output;
    std::ofstream md, html;
    int supportedCount = 0;

    if (exportMarkdown) {
        md.open("report.md");
        md << "# BaselineLens Report\n\n";
    }

    if (exportHTML) {
        html.open("report.html");
        html << "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>BaselineLens Report</title></head><body>";
        html << "<h1>BaselineLens Report</h1><ul>";
    }

    if (!quietMode && !jsonMode) std::cout << "\n🔍 Scanned Features:\n";

    for (const auto& feature : features) {
        std::string badge = validateFeature(feature, baselineData);
        std::string fallback = (badge != "✅ Supported") ? suggestFallback(feature) : "";
        bool isSupported = (badge == "✅ Supported");
        if (isSupported) supportedCount++;

        std::string emoji = isSupported ? "🟢" : "🔴";
        std::string line = "• " + feature + " → " + badge;
        if (demoMode) line = emoji + " **" + feature + "** → " + badge;

        if (!quietMode && !jsonMode) {
            std::cout << line << "\n";
            if (!fallback.empty()) std::cout << "  ↪ Fallback: " << fallback << "\n";
        }

        if (exportMarkdown) {
            md << "- " << line << "\n";
            if (!fallback.empty()) md << "  ↪ _Fallback_: " << fallback << "\n";
        }

        if (exportHTML) {
            html << "<li><strong>" << feature << "</strong> → " << badge;
            if (!fallback.empty()) html << "<br><em>Fallback:</em> " << fallback;
            html << "</li>";
        }

        if (jsonMode) {
            output[feature]["supported"] = isSupported;
            if (!fallback.empty()) output[feature]["fallback"] = fallback;
        }
    }

    if (scoreMode && !quietMode && !jsonMode) {
        int total = features.size();
        int percent = total > 0 ? (supportedCount * 100 / total) : 0;
        std::cout << "\n📊 Score: " << supportedCount << "/" << total << " features supported (" << percent << "%)\n";
    }

    if (exportMarkdown) {
        md << "\n_Validation complete._\n";
        if (scoreMode) {
            int total = features.size();
            int percent = total > 0 ? (supportedCount * 100 / total) : 0;
            md << "\n**Score:** " << supportedCount << "/" << total << " (" << percent << "% supported)\n";
        }
        md.close();
#ifdef _WIN32
        system("notepad report.md");
#endif
    }

    if (exportHTML) {
        html << "</ul><p><em>Validation complete.</em></p>";
        if (scoreMode) {
            int total = features.size();
            int percent = total > 0 ? (supportedCount * 100 / total) : 0;
            html << "<p><strong>Score:</strong> " << supportedCount << "/" << total << " (" << percent << "% supported)</p>";
        }
        html << "</body></html>";
        html.close();
#ifdef _WIN32
        system("start report.html");
#endif
    }

    if (jsonMode) {
        std::cout << output.dump(2) << std::endl;
    }

    if (!quietMode && !jsonMode) std::cout << "\n✅ Validation complete.\n";
    return 0;
}
