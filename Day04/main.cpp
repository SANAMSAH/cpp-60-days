#include <iostream>
#include <string>
#include <vector>
#include<memory>

using namespace std;

class Buffer
{
public:
    std::string name;
    int* data;
    size_t size;


    //constructor
    Buffer(std::string n, size_t s) : name(n), size(s)
    {
        data = new int[s];
        for (size_t i = 0; i < s; i++) data[i] = i * 10;
        std::cout << "Constructed: " << name << "\n";
    }

    //Destructor
    ~Buffer()
    {
        delete[] data;
        std::cout<< "Destroyed: " << name << "\n";
    }

    //copy constructor
    Buffer(const Buffer& other) : name(other.name + "_copy"), size(other.size) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) data[i] = other.data[i];
        std::cout << "Copy constructed: " << name << "\n";
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept
        : name(std::move(other.name)), size(other.size), data(other.data) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move constructed: " << name << "\n";
    }
    
    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        name = other.name + "_copy";
        data = new int[size];
        for (size_t i = 0; i < size; i++) data[i] = other.data[i];
        std::cout << "Copy assigned: " << name << "\n";
        return *this;
    }

    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this == &other) return *this;
        delete[] data;
        data = other.data;
        size = other.size;
        name = std::move(other.name);
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move assigned: " << name << "\n";
        return *this;
    }

    void print() const {
        if (!data) {
            std::cout << name << ": empty (moved from)\n";
            return;
        }
        std::cout << name << ": [";
        for (size_t i = 0; i < size; i++)
            std::cout << data[i] << (i + 1 < size ? "," : "");
        std::cout << "]\n";
    }
};

void example_copy_vs_move() {
    std::cout << "\n--- Example 1: Copy vs Move ---\n";
    Buffer original("Buf", 4);
    original.print();

    Buffer copied = original;            // copy
    Buffer moved = std::move(original);  // move

    copied.print();
    moved.print();
    original.print();  // empty
}

void example_move_assignment() {
    std::cout << "\n--- Example 2: Move Assignment ---\n";
    Buffer a("A", 3);
    Buffer b("B", 3);

    std::cout << "Before:\n";
    a.print();
    b.print();

    b = std::move(a);  // move assignment

    std::cout << "After:\n";
    a.print();  // empty
    b.print();  // a ka data
}

void example_move_vector() {
    std::cout << "\n--- Example 3: Move with vector ---\n";
    std::vector<std::string> v1 = { "C++", "Qt", "AI/ML" };
    std::cout << "v1 size before: " << v1.size() << "\n";

    std::vector<std::string> v2 = std::move(v1);
    std::cout << "v1 size after:  " << v1.size() << "\n";
    std::cout << "v2 size after:  " << v2.size() << "\n";

    for (const auto& s : v2)
        std::cout << s << " ";
    std::cout << "\n";
}

int main() {
    std::cout << "=== Day 4: Move Semantics ===\n";
    example_copy_vs_move();
    example_move_assignment();
    example_move_vector();
    std::cout << "\nDay 4 done!\n";
    return 0;
}