#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>
#include "aoc2024/day_02.h"

#include <sstream>

namespace aoc2024::day_02{
    using namespace std::string_view_literals;
    void part1() {

        constexpr auto file{"../data/2024/day_01.txt"sv};

        if (std::fstream fs{file.data()}; fs.is_open()) {
            std::vector<std::vector<int>> tokens;

            for (std::string l; std::getline(fs, l);) {
                std::stringstream k{l};

                std::vector<int> x{};
                for (std::string s; std::getline(k, s, ' '); x.push_back(std::stoi(s))) {}
                tokens.push_back(x);
            }

            int sum = 0;
            for (const auto& t : tokens) {
                bool rising = (t[0] < t[1]) ? true : false ;


                std::cout << rising;
                if (t[0] > t[1]) {
                    int passed = 0;
                    for (int i = 0; i < t.size()-1; i++) {
                        if (int diff = t[i]-t[i+1]; t[i] > t[i+1] and diff <= 3 and diff > 0) {
                            passed +=1;
                        }
                    }
                    if (passed == t.size()-1){ sum+=1; }
                }
                else if (t[0] < t[1]) {
                    int passed = 0;
                    for (int i = 0; i < t.size()-1; i++) {
                        if (int diff = t[i+1]-t[i]; t[i] < t[i+1] and diff <= 3 and diff > 0) {
                            passed +=1;
                        }
                    }
                    if (passed == t.size()-1){ sum+=1; }

                }
            }

            std::cout << sum;

        }else {
            std::cerr << "Error reading " << file << '\n';
        }

    }
}
