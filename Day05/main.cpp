#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;
// ================================
// Example 1: vector
// ================================
void example_vector() {

	std::cout << "\n--- Example 1: vector ---\n";

	vector<int>scores = { 10,20,30,40,50 };
	scores.push_back(60);

	cout << "First : " << scores[0] << "\n";
	cout << "last : " << scores.back() << "\n";
	cout << "size : " << scores.size() << "\n";

	cout << "All :- ";
	for (const auto& s : scores)
		cout << s << "->";

	cout << "\n";

	scores.pop_back();
	std::cout << "After pop: " << scores.size() << " elements\n";


}

// ================================
// Example 2: map
// ================================
void example_map() {

	std::cout << "\n--- Example 2: map (sorted) ---\n";

	map<string, int>salary;

	salary["Sanam"] = 50000;
	salary["Sangam"] = 60000;
	salary["Bikash"] = 35000;

	std::cout << "Salaries (sorted):\n";

	for (const auto& [name, sal] : salary)
		cout << " " << name << " : " << sal << "\n";


	if (salary.count("Sanam"))
		cout << "Sanam found : " << salary["Sanam"] << "\n";



}
// ================================
// Example 3: unordered_map
// ================================
void example_unordered_map() {
    std::cout << "\n--- Example 3: unordered_map (fast lookup) ---\n";

    std::unordered_map<std::string, std::string> config;
    config["host"] = "localhost";
    config["port"] = "8080";
    config["database"] = "mydb";
    config["user"] = "admin";

    // order guaranteed nahi — but FASTER than map
    std::cout << "Config:\n";
    for (const auto& [key, val] : config)
        std::cout << "  " << key << " = " << val << "\n";

    // fast lookup O(1)
    std::cout << "Host: " << config["host"] << "\n";
    std::cout << "Port: " << config["port"] << "\n";

    // USE WHEN: fast lookup chahiye, order matter nahi
}

// ================================
// Example 4: set
// ================================
void example_set() {
    std::cout << "\n--- Example 4: set (unique + sorted) ---\n";

    std::set<int> unique_scores;
    unique_scores.insert(85);
    unique_scores.insert(92);
    unique_scores.insert(85);  // duplicate — ignore hoga!
    unique_scores.insert(78);
    unique_scores.insert(92);  // duplicate — ignore hoga!
    unique_scores.insert(100);

    std::cout << "Unique scores (sorted): ";
    for (const auto& s : unique_scores)
        std::cout << s << " ";
    std::cout << "\n";
    std::cout << "Size: " << unique_scores.size() << "\n";

    // check existence
    if (unique_scores.count(85))
        std::cout << "85 exists!\n";

    // USE WHEN: duplicate nahi chahiye, sorted order chahiye
}

// ================================
// Example 5: Comparison
// ================================
void example_when_to_use() {
    std::cout << "\n--- Example 5: When to use what ---\n";

    // vector  — student roll numbers (ordered, index access)
    std::vector<int> rolls = { 101, 102, 103, 104 };
    std::cout << "Roll #2: " << rolls[1] << "\n";

    // map — phone book (name → number, sorted)
    std::map<std::string, std::string> phonebook;
    phonebook["Sanam"] = "9876543210";
    phonebook["Rahul"] = "9123456789";
    std::cout << "Sanam's number: " << phonebook["Sanam"] << "\n";

    // unordered_map — cache (fast key lookup)
    std::unordered_map<int, std::string> cache;
    cache[1] = "result_one";
    cache[2] = "result_two";
    std::cout << "Cache[1]: " << cache[1] << "\n";

    // set — unique tags on a blog post
    std::set<std::string> tags = { "cpp", "ai", "cpp", "qt", "ai" };
    std::cout << "Unique tags: ";
    for (const auto& t : tags)
        std::cout << t << " ";
    std::cout << "\n";
}

int main() {
    std::cout << "=== Day 5: STL Containers ===\n";

    example_vector();
    example_map();
    example_unordered_map();
    example_set();
    example_when_to_use();

    std::cout << "\nDay 5 done!\n";
    return 0;
}