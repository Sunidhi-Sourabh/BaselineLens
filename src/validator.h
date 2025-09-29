#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <string>
#include <map>

// Returns trust badge for a given feature
std::string validateFeature(const std::string& feature, const std::map<std::string, bool>& baselineData);

#endif
