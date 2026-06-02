#include <iostream>
#include <string>

//static_assert(__cplusplus >= 201703L, "Need C++17 or later!");

int main() {
    std::pair<std::string, int> goal = {"days_remaining", 60};
    auto [label, days] = goal;

    std::cout << "=== cpp-60-days ===" << "\n";
    std::cout << "Engineer : Sanam Sah\n";
    std::cout << "Mission  : Modern C++ + Qt + AI/ML\n";
    std::cout << label << " : " << days << "\n";
    std::cout << "Day 1    : Toolchain verified. Let's go.\n";

    return 0;
}