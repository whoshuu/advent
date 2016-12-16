#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>


int get_escaped_length(std::string s) {
    return s.length();
}

int main() {
    std::ifstream file("8.txt");
    std::string input;

    int l = 0;
    int e = 0;
    while (std::getline(file, input)) {
        l += input.length();
        e += get_escaped_length(input);
    }
    std::cout << "Characters: " << l << std::endl;
    std::cout << "Escaped characters: " << e << std::endl;
    std::cout << "Difference: " << l - e<< std::endl;
}
