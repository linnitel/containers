
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

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
        {
    int idx;
    char buff[BUFFER_SIZE];
        };


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
        {
        public:
            MutantStack() {}
            MutantStack(const MutantStack<T>& src) { *this = src; }
            MutantStack<T>& operator=(const MutantStack<T>& rhs)
                    {
                this->c = rhs.c;
                return *this;
                    }
                    ~MutantStack() {}

                    typedef typename ft::stack<T>::container_type::iterator iterator;

            iterator begin() { return this->_stack.begin(); }
            iterator end() { return this->_stack.end(); }
        };

void testVector();
void testStack();
void testMap();

enum containersList {
    Vector, Stack, Map, Set, All, Exit
};

class CheckType {
private:
    containersList e;


public:
    std::string input;
    CheckType();
    ~CheckType();
    bool checkInput() {
        e(input);
        if (input == "Vector")
    };

};

int main(int argc, char **argv) {
	while (true) {
	    printColourText("Container tester:", GREEN, true);
	    printColourText("Vector ------ To test vector", GREEN, true);
	    printColourText("Stack ------ To test stack", GREEN, true);
	    printColourText("Map ------ To test map", GREEN, true);
	    printColourText("Set ------ To test set", GREEN, true);
	    printColourText("All ---- To test All containers", GREEN, true);
	    printColourText("Exit ---- To exit tester", GREEN, true);
		CheckType input;
		std::cin >> input.input;
		if (input.checkInut) {
			if (input == "V" || input == "All") {
				Tester vectorT = Tester();
				vectorT.testContainer(input);
			if (input == "Exit"|| input == "All") {
			    return 0;
			}
		}
		printColourText("Test other container?", GREEN, true);
	}
//    if (argc != 2)
//    {
//        std::cerr << "Usage: ./test seed" << std::endl;
//        std::cerr << "Provide a seed please" << std::endl;
//        std::cerr << "Count value:" << COUNT << std::endl;
//        return 1;
//    }
//    const int seed = atoi(argv[1]);
//    srand(seed);
//
//    ft::vector<std::string> vector_str;
//    ft::vector<int> vector_int;
//    ft::stack<int> stack_int;
//    ft::vector<Buffer> vector_buffer;
//    ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
//    ft::map<int, int> map_int;
//
//    for (int i = 0; i < COUNT; i++)
//    {
//        vector_buffer.push_back(Buffer());
//    }
//
//    for (int i = 0; i < COUNT; i++)
//    {
//        const int idx = rand() % COUNT;
//        vector_buffer[idx].idx = 5;
//    }
//    ft::vector<Buffer>().swap(vector_buffer);
//
//    try
//    {
//        for (int i = 0; i < COUNT; i++)
//        {
//            const int idx = rand() % COUNT;
//            vector_buffer.at(idx);
//            std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
//        }
//    }
//    catch(const std::exception& e)
//    {
//        //NORMAL ! :P
//    }
//
//    for (int i = 0; i < COUNT; ++i)
//    {
//        map_int.insert(ft::make_pair(rand(), rand()));
//    }
//
//    int sum = 0;
//    for (int i = 0; i < 10000; i++)
//    {
//        int access = rand();
//        sum += map_int[access];
//    }
//    std::cout << "should be constant with the same seed: " << sum << std::endl;
//
//    {
//        ft::map<int, int> copy = map_int;
//    }
//    MutantStack<char> iterable_stack;
//    for (char letter = 'a'; letter <= 'z'; letter++)
//        iterable_stack.push(letter);
//    for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
//    {
//        std::cout << *it;
//    }
//    std::cout << std::endl;


    return (0);
}