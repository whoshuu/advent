#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

bool is_nice2(std::string in) {
    bool repeat = false;
    for (int i = 0; i < in.length() - 3; ++i) {
        for (int j = i + 2; j < in.length() - 1; ++j) {
            if (in.at(i) == in.at(j) && in.at(i + 1) == in.at(j + 1)) {
                repeat = true;
                break;
            }
        }
        
        if (repeat) {
            break;
        }
    }

    bool sandwich = false;
    for (int i = 0; i < in.length() - 2; ++i) {
        if (in.at(i) == in.at(i + 2)) {
            sandwich = true;
            break;
        }
    }

    return repeat && sandwich;
}

bool is_nice(std::string in) {
    int vowels = 0;
    vowels += std::count(in.begin(), in.end(), 'a');
    vowels += std::count(in.begin(), in.end(), 'e');
    vowels += std::count(in.begin(), in.end(), 'i');
    vowels += std::count(in.begin(), in.end(), 'o');
    vowels += std::count(in.begin(), in.end(), 'u');

    bool consecutive = false;

    for (int i = 0; i < in.length() - 1; ++i) {
        if (in.at(i) == in.at(i + 1)) {
            consecutive = true;
            break;
        }
    }

    bool bad = false;
    if (in.find("ab") != std::string::npos || in.find("cd") != std::string::npos ||
            in.find("pq") != std::string::npos || in.find("xy") != std::string::npos) {
        bad = true;
    }

    return vowels >= 3 && consecutive && !bad;
}

int main() {
    std::ifstream file("5.txt");
    std::string input;

    int nice = 0;
    while (file >> input) {
        //std::cout << input << ": ";
        if (is_nice2(input)) {
            //std::cout << "Nice" << std::endl;
            nice++;
        } else {
            //std::cout << "Naughty" << std::endl;
        }
    }

    std::cout << is_nice2("qjhvhtzxzqqjkmpb") << std::endl;
    std::cout << is_nice2("xxyxx") << std::endl;
    std::cout << is_nice2("uurcxstgmygtbstg") << std::endl;
    std::cout << is_nice2("ieodomkazucvgmuy") << std::endl;
    std::cout << nice << std::endl;
}
