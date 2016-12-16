#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>


std::map<std::string, unsigned short> values;

inline bool isInteger(const std::string &s) {
  if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    return false;

  char *p;
  strtol(s.c_str(), &p, 10);

  return (*p == 0);
}

int search(std::ifstream& file, std::string wire) {
    //std::cin.get();
    std::string input;
    std::cout << "Looking for " << wire << std::endl;
    file.clear();
    file.seekg(0, std::ios::beg);

    while (std::getline(file, input)) {
        //std::cout << input << std::endl;
        if (input.find(std::string("-> ").append(wire).append(" ")) != std::string::npos) {
            break;
        }
    }
    //std::cout << input << std::endl;
    auto sub = input.substr(0, input.find(" ->"));
    std::cout << sub << std::endl;

    if (sub.find("AND") != std::string::npos) {
        auto left = sub.substr(0, sub.find(" AND"));
        auto right = sub.substr(sub.find("AND") + 4, sub.length() - sub.find("AND") - 4);
        if (!isInteger(left)) {
            if (values.find(left) == values.end()) {
                search(file, left);
            }
            if (values.find(right) == values.end()) {
                search(file, right);
            }
            values[wire] = values[left] & values[right];
        } else {
            if (values.find(right) == values.end()) {
                search(file, right);
            }
            values[wire] = std::stoi(left) & values[right];
        }
    } else if (sub.find("OR") != std::string::npos) {
        // There are two things to find
        auto left = sub.substr(0, sub.find(" OR"));
        auto right = sub.substr(sub.find("OR") + 3, sub.length() - sub.find("OR") - 3);
        if (values.find(left) == values.end()) {
            search(file, left);
        }
        if (values.find(right) == values.end()) {
            search(file, right);
        }
        values[wire] = values[left] | values[right];
    } else if (sub.find("LSHIFT") != std::string::npos) {
        auto left = sub.substr(0, sub.find(" LSHIFT"));
        auto right = sub.substr(sub.find("LSHIFT") + 7, sub.length() - sub.find("LSHIFT") - 7);
        if (values.find(left) == values.end()) {
            search(file, left);
        }
        values[wire] = values[left] << std::stoi(right);
    } else if (sub.find("RSHIFT") != std::string::npos) {
        auto left = sub.substr(0, sub.find(" RSHIFT"));
        auto right = sub.substr(sub.find("RSHIFT") + 7, sub.length() - sub.find("RSHIFT") - 7);
        if (values.find(left) == values.end()) {
            search(file, left);
        }
        values[wire] = values[left] >> std::stoi(right);
    } else if (sub.find("NOT") != std::string::npos) {
        auto n = sub.substr(4, sub.length() - 4);
        if (values.find(n) == values.end()) {
            search(file, n);
        }
        values[wire] = ~values[n];
    } else {
        // Assignment
        if (!isInteger(sub)) {
            if (values.find(sub) == values.end()) {
                search(file, sub);
            }
            values[wire] = values[sub];
        } else {
            values[wire] = std::stoi(sub);
        }
    }

    std::cout << "Setting " << wire << " to " << values[wire] << std::endl;
}

int main() {
    unsigned short x = 0;
    unsigned short y = 0;
    unsigned short d = x & y;
    unsigned short e = x | y;
    unsigned short f = x << 2;
    unsigned short g = y >> 2;
    unsigned short h = ~x;
    unsigned short i = ~y;
    std::cout << "Hello" << std::endl;

    std::cout << d << std::endl;
    std::cout << e << std::endl;
    std::cout << f << std::endl;
    std::cout << g << std::endl;
    std::cout << h << std::endl;
    std::cout << i << std::endl;

    std::ifstream file("7.txt");
    search(file, "a");

    std::cout << "a is: " << values["a"] << std::endl;
}
