
#include "Tester/Tester.hpp"
#include <iostream>
#include <string>
#include <deque>
#define CONTAINER_TYPE 1
#if CONTAINER_TYPE == 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
    #include "utils/PrintColour.hpp"
	namespace ft = std;
#else
	#include "Vector/Vector.hpp"
    #include "Stack/Stack.hpp"
    #include "Map/Map.hpp"
#endif

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