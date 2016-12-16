#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

int sum(int x, int y, int z) {
    return 2*x*y + 2*y*z + 2*z*x + std::min(x*y, std::min(y*z, z*x));
}

int ribbon(int x, int y, int z) {
    return x*y*z + std::min(2*(x + y), std::min(2*(z + y), 2*(x + z)));
}

int main() {
    std::ifstream file("2.txt");
    std::string input;

    auto total = 0;
    auto l = 0;
    while (file >> input) {
        std::string xs, ys, zs;
        std::istringstream iss(input);
        getline(iss, xs, 'x');
        getline(iss, ys, 'x');
        getline(iss, zs, '\n');
        auto x = std::stoi(xs);
        auto y = std::stoi(ys);
        auto z = std::stoi(zs);

        total += ribbon(x, y, z);
        l++;
    }

    
    std::cout << total << std::endl;
    std::cout << l << std::endl;
    std::cout << sum(2, 3, 4) << std::endl;
    std::cout << ribbon(2, 3, 4) << std::endl;
    std::cout << ribbon(1, 1, 10) << std::endl;
}
