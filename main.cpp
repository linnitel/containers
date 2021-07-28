#include "Vector/VectorTest.hpp"
#include "Stack/StackTest.hpp"
#include "Map/MapTest.hpp"

int main() {
	printColourText("Container tester:", GREEN, true);
	printColourText("V ------ To test Vector", GREEN, true);
	printColourText("S ------ To test Stack", GREEN, true);
	printColourText("M ------ To test Map", GREEN, true);
	printColourText("All ---- To test All containers", GREEN, true);
	printColourText("Exit ---- To exit tester", GREEN, true);
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