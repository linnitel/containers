//
// Created by Tothmure Isabel on 7/28/21.
//

#include "StackTest.hpp"

void checkStackConstructors(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    // three cases one with default type other with template type ft_vector and deque
    file << "### DEFAULT CONSTRUCTOR WITH FT_VECTOR ###" << std::endl;
	ft::vector<int> vectorInt;
	for (int i = 0; i < 6; i++) {
		vectorInt.push_back(i);
	}
    ft::stack<int, ft::vector<int>> stack(vectorInt);
    file << "$ 17. ft::stack<int, ft::vector<int>> stack(vectorInt);" << std::endl;
    file << "[ stack.size() = " << stack.size() << "]" << std::endl;

    file << "### DEFAULT CONSTRUCTOR WITH STD_DEQUE ###" << std::endl;
	ft::stack<int, std::deque<int> > stackTwo = ft::stack<int, std::deque<int> >();
	file << "$ 22. ft::stack<int, std::deque<int> > stackTwo = ft::stack<int, std::deque<int> >();" << std::endl;
	file << "[ stack.size() = " << stack.size() << "]" << std::endl;

    file << "### DEFAULT CONSTRUCTOR DEFAULT SETTINGS ###" << std::endl;
	ft::stack<int> stackThree = ft::stack<int>();
	file << "$ 27. ft::stack<int> stackThree = ft::stack<int>();" << std::endl;
	file << "[ stack.size() = " << stack.size() << "]" << std::endl;
}

void checkStackCapacity(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
	std::deque<int> dequeInt;
	for (int i = 0; i < 6; i++) {
		dequeInt.push_back(i);
	}
	ft::stack<int, std::deque<int>> stack(dequeInt);
    file << "### SIZE ###" << std::endl;
	file << "$ 40. ft::stack<int, std::deque<int>> stack(dequeInt);" << std::endl;
	file << "[ stack.size() = " << stack.size() << "]" << std::endl;

    file << "### EMPTY ###" << std::endl;
    bool empt = stack.empty();
    file << "$ 46. bool empt = stack.empty();" << std::endl;
    file << "[ stack.empty() = " << empt << "]" << std::endl;
}

void checkStackModifiersAndAccessElements(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### PUSH AND TOP ###" << std::endl;
	ft::stack<myInt> stackMyInt;
	file << "$ 59. stackMyInt.push(myInt(i));" << std::endl;
	for (int i = 0; i < 15; i++) {
		stackMyInt.push(myInt(i));
		file << "[ stackMyInt.top() = " << stackMyInt.top() << "; ";
	}
	file << "]" << "; ";
	file << "[ stackMyInt.size() = " << stackMyInt.size() << "]" << std::endl;

    file << "### POP AND CONSTANT TOP ###" << std::endl;
	for (int i = 0; i < 5; i++) {
		stackMyInt.pop();
		const myInt topStack = stackMyInt.top();
		file << "[ stackMyInt.top() = " << topStack << "; ";
	}
	file << "]" << "; ";
	file << "[ stackMyInt.size() = " << stackMyInt.size() << "]" << std::endl;
}

void checkStackComparison(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
	ft::vector<int> vectorOne(5, 10);
	ft::vector<int> vectorTwo(5, 9);
	ft::vector<std::string> vectorThree(3, "this");
	ft::vector<std::string> vectorFour(10, "piupiu");
    ft::stack<int> stackOne(vectorOne);
	ft::stack<int> stackTwo(vectorTwo);
	ft::stack<int> stackThree(vectorOne);
	ft::stack<std::string> stackFour(vectorThree);
	ft::stack<std::string> stackFive(vectorFour);
	file << "### OPERATOR == ###" << std::endl;
	bool equal = (stackOne == stackTwo);
	file << "$ 83. bool equal = (stackOne == stackTwo);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
	equal = (stackOne == stackThree);
	file << "$ 86. equal = (stackOne == stackThree);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
	file << "### OPERATOR != ###" << std::endl;
	equal = (stackOne != stackThree);
	file << "$ 90. equal = (stackOne != stackThree);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
	file << "### OPERATOR > ###" << std::endl;
	bool compare = stackFour > stackFive;
	file << "$ 94. bool compare = stackFour > stackFive;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
	file << "### OPERATOR < ###" << std::endl;
	compare = stackOne < stackTwo;
	file << "$ 99. ompare = stackOne < stackTwo;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
	file << "### OPERATOR >= ###" << std::endl;
	compare = stackOne >= stackThree;
	file << "$ 102. compare = stackOne >= stackThree;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
	file << "### OPERATOR <= ###" << std::endl;
	compare = stackFour <= stackFive;
	file << "$ 106. compare = stackFour <= stackFive;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
}

void testStack(bool containerType) {
	std::string fileName = containerType ? "ft_stack" : "std_stack";
	std::ofstream file;
	file.open(fileName);
	if (file.is_open()) {
	    checkStackConstructors(file, containerType);
	    checkStackCapacity(file, containerType);
	    checkStackModifiersAndAccessElements(file, containerType);
	    checkStackComparison(file, containerType);
	}
}
