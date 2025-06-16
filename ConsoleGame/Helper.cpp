#include "Helper.h"

std::string StringHelper::toLower(const std::string& str) {
    std::string result = str;
    for (char& ch : result) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
        }
    }
    return result;
}

std::string StringHelper::capitalizeOnlyFirst(const std::string& str) {
    if (str.empty()) return str;

    std::string result = str;

    if (result[0] >= 'a' && result[0] <= 'z') {
        result[0] -= 32;
    }

    for (size_t i = 1; i < result.length(); ++i) {
        if (result[i] >= 'A' && result[i] <= 'Z') {
            result[i] += 32;
        }
    }

    return result;
}


std::vector<std::string> StringHelper::splitWords(const std::string& input) {
    std::vector<std::string> words;
    size_t start = 0;

    while (start < input.length()) {
        while (start < input.length() && input[start] == ' ') {
            ++start;
        }

        size_t end = start;
        while (end < input.length() && input[end] != ' ') {
            ++end;
        }

        if (start < end) {
            words.push_back(input.substr(start, end - start));
        }

        start = end;
    }

    return words;
}
