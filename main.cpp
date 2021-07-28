#include "Vector/VectorTest.hpp"
#include "Stack/StackTest.hpp"
#include "Map/MapTest.hpp"

int main() {
	std::cout << "Container tester:" << std::endl;
	std::cout << "V ------ To test Vector" << std::endl;
	std::cout << "S ------ To test Stack" << std::endl;
	std::cout << "M ------ To test Map" << std::endl;
	std::cout << "All ---- To test All containers" << std::endl;
	std::cout << "Exit ---- To exit tester" << std::endl;
	while (true) {
		std::string input;
		std::cin >> input;
		if (input == "V" || input == "S" || input == "M" || input == "All" || input == "Exit") {
			if (input == "V" || input == "All") {
				testVector();
			}
			if (input == "S" || input == "All") {
				testStack();
			}
			if (input == "M" || input == "All") {
				testMap();
			}
			return 0;
		}
	}
}