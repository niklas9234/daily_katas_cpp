// lib/aoc/2024/day_03/src/day03.cpp
#include "aoc2024/day_03.h"
#include <algorithm>
#include <array>
#include <cmath>   // für std::abs

namespace aoc2024::day_03{

    int part1() {
        std::array<int, 6> l = {3,4,2,1,3,3};
        std::array<int, 6> r = {4,3,5,3,9,3};

        std::sort(l.begin(), l.end());
        std::sort(r.begin(), r.end());

        int sum{};
        for (std::size_t i = 0; i < l.size(); i++) {
            sum += std::abs(l[i] - r[i]);
        }

        return sum;  // <-- statt direkt auszugeben
    }

}

