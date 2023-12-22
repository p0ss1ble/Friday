#include <iostream>
#include <fstream>
#include <map>
#include <cctype>

int main() {
    std::string filename;
    std::cout << "Enter the name of the file: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return 1;
    }

    std::map<char, int> letterCount;

    char c;
    while (file.get(c)) {
        if (isalpha(c)) {
            char uppercaseC = toupper(c);  // Convert to uppercase for case-insensitivity
            letterCount[uppercaseC]++;
        }
    }

    file.close();

    std::cout << "Letter counts:\n";
    for (char c = 'A'; c <= 'Z'; ++c) {
        std::cout << c << ": " << letterCount[c] << " letters\n";
    }

    return 0;
}
