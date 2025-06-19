#include <iostream>
#include <string>

std::string findLongestSeries(const std::string& str) {
    if (str.empty()) {
        return "";
    }

    char currentChar = str[0];
    char maxChar = str[0];
    int currentCount = 1;
    int maxCount = 1;

    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == currentChar) {
            currentCount++;
        }
        else {
            currentChar = str[i];
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxChar = currentChar;
            maxCount = currentCount;
        }
    }

    return std::string(maxCount, maxChar);
}

int main() {
    std::string str = "aaabbbbcccccdd";
    std::string longestSeries = findLongestSeries(str);
    std::cout << "Longest series of letters: " << longestSeries << std::endl;

    return 0;
}