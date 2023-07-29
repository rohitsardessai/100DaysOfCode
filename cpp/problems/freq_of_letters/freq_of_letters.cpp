#include <cctype>
#include <iostream>
#include <map>
#include <string>

void countLetterFrequency(const std::string &str)
{
    std::map<char, int> letterFrequency;

    for (char ch : str) {
        ch = std::tolower(ch);

        letterFrequency[ch]++;
    }

    for (const auto &entry : letterFrequency) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}

int main()
{
    std::cout << "Enter a string: ";
    std::string input;
    std::getline(std::cin, input);

    countLetterFrequency(input);

    return 0;
}
