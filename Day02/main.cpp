#include <iostream>
#include <string>
#include <vector>

void example_auto() {
    std::cout << "\n--- Example 1: auto ---\n";
    auto x = 42;
    auto pi = 3.14;
    auto name = std::string("Sanam");
    std::cout << "x = " << x << "\n";
    std::cout << "pi = " << pi << "\n";
    std::cout << "name = " << name << "\n";
    std::vector<int> nums = { 1, 2, 3, 4, 5 };
    auto it = nums.begin();
    std::cout << "first element = " << *it << "\n";
}

void example_range_for() {
    std::cout << "\n--- Example 2: Range-based for ---\n";
    std::vector<int> nums = { 10, 20, 30, 40, 50 };
    for (auto n : nums)
        std::cout << n << " ";
    std::cout << "\n";
    for (const auto& n : nums)
        std::cout << n * 2 << " ";
    std::cout << "\n";
}

void example_lvalue_rvalue() {
    std::cout << "\n--- Example 3: lvalue & rvalue ---\n";
    int a = 10;
    int& lref = a;
    lref = 20;
    std::cout << "lvalue ref: a = " << a << "\n";
    int&& rref = 42;
    std::cout << "rvalue ref: " << rref << "\n";
}

void increment(int& val) { val++; }

void example_ref_function() {
    std::cout << "\n--- Example 4: Reference in function ---\n";
    int score = 99;
    std::cout << "before: " << score << "\n";
    increment(score);
    std::cout << "after:  " << score << "\n";
}

void printName(const std::string& name) {
    std::cout << "Name: " << name << "\n";
}

void example_const_ref() {
    std::cout << "\n--- Example 5: const reference ---\n";
    std::string n = "Sanam Sah";
    printName(n);
}

int main() {
    std::cout << "=== Day 2: auto & References ===\n";
    example_auto();
    example_range_for();
    example_lvalue_rvalue();
    example_ref_function();
    example_const_ref();
    std::cout << "\nDay 2 done!\n";
    return 0;
}