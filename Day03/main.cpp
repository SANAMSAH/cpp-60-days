#include <iostream>
#include <string>
#include <vector>
#include<memory>



class Robot {
public:
    std::string name;

    Robot(std::string n) : name(n) {
        std::cout << "Robot created: " << name << "\n";
    }
    ~Robot() {
        std::cout << "Robot destroyed: " << name << "\n";
    }
    void speak() {
        std::cout << name << " says: Hello!\n";
    }
};

void example_unique_ptr() {


    std::cout << "\n--- Example 1: unique_ptr ---\n";


    auto r = std::make_unique<Robot>("UniqueBot");
    r->speak();

    auto r2 = std::move(r);  
    r2->speak();

    if (!r) std::cout << "r is now empty after move\n";

}   


void example_shared_ptr() {
    std::cout << "\n--- Example 2: shared_ptr ---\n";

    auto r1 = std::make_shared<Robot>("SharedBot");
    std::cout << "ref count: " << r1.use_count() << "\n";  // 1

    {
        auto r2 = r1;  
        std::cout << "ref count: " << r1.use_count() << "\n";  // 2
        r2->speak();
    }   // r2 destroy

    std::cout << "ref count: " << r1.use_count() << "\n";  // 1

}   //r1 destroy


void example_weak_ptr() {
    std::cout << "\n--- Example 3: weak_ptr ---\n";

    auto shared = std::make_shared<Robot>("WeakBot");
    std::weak_ptr<Robot> weak = shared;  // observe only, no ownership

    std::cout << "ref count: " << shared.use_count() << "\n";  // 1

   
    if (auto locked = weak.lock()) {
        locked->speak();
        std::cout << "ref count while locked: " << shared.use_count() << "\n";  // 2
    }

    shared.reset();  // Robot destroy

    if (weak.expired()) {
        std::cout << "WeakBot is gone!\n";
    }
}

int main()
{
	std::cout << "Day 03\n";
    example_unique_ptr();
    example_shared_ptr();
    example_weak_ptr();
	return 0;
}