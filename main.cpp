#include "Vector/VectorTest.hpp"
#include "Stack/StackTest.hpp"
#include "Map/MapTest.hpp"

int main() {
	while (true) {
	    printColourText("Container tester:", GREEN, true);
	    printColourText("V ------ To test vector", GREEN, true);
	    printColourText("S ------ To test stack", GREEN, true);
	    printColourText("M ------ To test Map", GREEN, true);
	    printColourText("All ---- To test All containers", GREEN, true);
	    printColourText("Exit ---- To exit tester", GREEN, true);
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
			if (input == "Exit"|| input == "All") {
			    return 0;
			}
		}
		printColourText("Test other container?", GREEN, true);
	}
}