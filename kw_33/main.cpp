#include <algorithm>
#include <iostream>
#include <array>

// Advent of code - 1

int main() {
    std::array l = {3,4,2,1,3,3};
    std::array r = {4,3,5,3,9,3};

    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());

    int sum {};
    for (int i = 0; i<l.size(); i++) {
        sum += std::abs(l[i]-r[i]);
    }

    std::cout << sum;
    return 0;
}