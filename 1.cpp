#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("1.txt");
    std::string input;
    file >> input;

    int floor = 0;
    int position = 0;

    for(char& c : input) {
        position++;
        if (c == '(') {
            floor++;
        } else if (c == ')') {
            floor--;
            if (floor < 0) {
                break;
            }
        }
    }

    auto left = std::count(input.begin(), input.end(), '(');
    auto right = std::count(input.begin(), input.end(), ')');
    std::cout << left - right << std::endl;
    std::cout << position << std::endl;
}
