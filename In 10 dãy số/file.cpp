#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>

int main() {
    constexpr int kNumArrays = 10;
    constexpr int kArraySize = 1000000;
    std::srand(std::time(nullptr));
    std::array<std::vector<double>, kNumArrays> data;
    for (auto& arr : data) {
        arr.resize(kArraySize);
        for (auto& elem : arr) {
            elem = static_cast<double>(std::rand()) / RAND_MAX;
        }
    }
    std::sort(data[0].begin(), data[0].end());
    std::sort(data[1].begin(), data[1].end(), std::greater<double>());
     for (const auto& arr : data) {
        for (const auto& elem : arr) {
            std::cout << elem << ' ';
        }
        std::cout << '\n';
    }
}

