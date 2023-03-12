#include <algorithm>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
using namespace std; 

int main() {
    constexpr int kNumArrays = 10;
    constexpr int kArraySize = 1000000;
    srand(time(nullptr));
    array<vector<double>, kNumArrays> data;
    for (auto& arr : data) {
        arr.resize(kArraySize);
        for (auto& elem : arr) {
            elem = static_cast<double>(rand()) / RAND_MAX;
        }
    }
    sort(data[0].begin(), data[0].end());
    sort(data[1].begin(), data[1].end(), greater<double>());
     for (const auto& arr : data) {
        for (const auto& elem : arr) {
           cout << elem << ' ';
        }
         cout << '\n';
    }
}

