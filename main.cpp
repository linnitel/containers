
#include "Tester/Tester.hpp"

int main() {
	while (true) {
	    printColourText("Container tester:", GREEN, true);
	    printColourText("Vector ------ To test vector", GREEN, true);
	    printColourText("Stack ------ To test stack", GREEN, true);
	    printColourText("Map ------ To test map", GREEN, true);
	    printColourText("Set ------ To test set", GREEN, true);
	    printColourText("All ---- To test All containers", GREEN, true);
	    printColourText("Exit ---- To exit tester", GREEN, true);
		std::string input;
		std::cin >> input;
        if (input == "Vector" || input == "All") {
            Tester vectorT = Tester();
            vectorT.testContainer("Vector");
        }
        if (input == "Stack" || input == "All") {
            Tester stackT = Tester();
            stackT.testContainer("Stack");
        }
        if (input == "Map" || input == "All") {
            Tester mapT = Tester();
            mapT.testContainer("Map");
        }
        if (input == "Set" || input == "All") {
            Tester setT = Tester();
            setT.testContainer("Set");
        }
        if (input == "Exit"|| input == "All") {
            return 0;
        }
		printColourText("Test other container?", GREEN, true);
	}
}