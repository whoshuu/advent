#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

int main() {
    std::ifstream file("3.txt");
    std::string input;
    file >> input;

    std::set<std::string> coords;
    coords.insert("0 0");

    int x = 0;
    int y = 0;

    int rx = 0;
    int ry = 0;

    bool robo = false;

    for(char& c : input) {
        if (c == '^') {
            if (robo) {
                y++;
            } else {
                ry++;
            }
        } else if (c == '<') {
            if (robo) {
                x--;
            } else {
                rx--;
            }
        } else if (c == 'v') {
            if (robo) {
                y--;
            } else {
                ry--;
            }
        } else if (c == '>') {
            if (robo) {
                x++;
            } else {
                rx++;
            }
        }

        std::stringstream ss;
        if (robo) {
            ss << x << " " << y;
        } else {
            ss << rx << " " << ry;
        }
        robo = !robo;
        std::cout << ss.str() << std::endl;
        coords.insert(ss.str());
    }

    std::cout << coords.size() << std::endl;
}
