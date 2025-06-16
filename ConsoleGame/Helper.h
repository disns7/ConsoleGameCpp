#pragma once

#include <string>
#include <vector>

class StringHelper {
public:
    static std::string toLower(const std::string& str);
    static std::string capitalizeOnlyFirst(const std::string& str);
    static std::vector<std::string> splitWords(const std::string& input);
};


