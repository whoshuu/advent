#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::ifstream file("6.txt");
    std::string input;
    std::vector<std::vector<bool>> lights;
    std::vector<std::vector<int>> brights;

    for (int i = 0; i < 1000; ++i) {
        std::vector<bool> line(1000);
        std::vector<int> bline(1000);
        for (int j = 0; j < 1000; ++j) {
            line[j] = false;
            bline[j] = 0;
        }
        lights.push_back(line);
        brights.push_back(bline);
    }

    while (std::getline(file, input)) {
        if (input.find("turn on") != std::string::npos) {
            auto start = input.substr(8, input.find("through") - 9);
            auto end = input.substr(input.find("through") + 8, input.length() - input.find("through") - 8);
            auto x1 = std::stoi(start.substr(0, start.find(",")));
            auto y1 = std::stoi(start.substr(start.find(",") + 1, start.length() - start.find(",") - 1));
            auto x2 = std::stoi(end.substr(0, end.find(",")));
            auto y2 = std::stoi(end.substr(end.find(",") + 1, end.length() - end.find(",") - 1));
            for (int i = x1; i < x2 + 1; ++i) {
                for (int j = y1; j < y2 + 1; ++j) {
                    lights[i][j] = true;
                    brights[i][j] = brights[i][j] + 1;
                }
            }
        } else if (input.find("turn off") != std::string::npos) {
            auto start = input.substr(9, input.find("through") - 10);
            auto end = input.substr(input.find("through") + 8, input.length() - input.find("through") - 8);
            auto x1 = std::stoi(start.substr(0, start.find(",")));
            auto y1 = std::stoi(start.substr(start.find(",") + 1, start.length() - start.find(",") - 1));
            auto x2 = std::stoi(end.substr(0, end.find(",")));
            auto y2 = std::stoi(end.substr(end.find(",") + 1, end.length() - end.find(",") - 1));
            for (int i = x1; i < x2 + 1; ++i) {
                for (int j = y1; j < y2 + 1; ++j) {
                    lights[i][j] = false;
                    if (brights[i][j] > 0) {
                        brights[i][j] = brights[i][j] - 1;
                    }
                }
            }
        } else if (input.find("toggle") != std::string::npos) {
            auto start = input.substr(7, input.find("through") - 8);
            auto end = input.substr(input.find("through") + 8, input.length() - input.find("through") - 8);
            auto x1 = std::stoi(start.substr(0, start.find(",")));
            auto y1 = std::stoi(start.substr(start.find(",") + 1, start.length() - start.find(",") - 1));
            auto x2 = std::stoi(end.substr(0, end.find(",")));
            auto y2 = std::stoi(end.substr(end.find(",") + 1, end.length() - end.find(",") - 1));
            for (int i = x1; i < x2 + 1; ++i) {
                for (int j = y1; j < y2 + 1; ++j) {
                    lights[i][j] = !lights[i][j];
                    brights[i][j] = brights[i][j] + 2;
                }
            }
        }
    }

    int count = 0;
    for (auto&& line : lights) {
        for (auto&& light : line) {
            if (light) {
                count++;
            }
        }
    }

    int brightness = 0;
    for (auto&& bline : brights) {
        for (auto&& bright : bline) {
            brightness += bright;
        }
    }

    std::cout << "Lights: " << count << std::endl;
    std::cout << "Brights: " << brightness << std::endl;
}
