//
// Created by Tothmure Isabel on 7/28/21.
//

#include "StackTest.hpp"

void checkConstructors(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    // three cases one with default type other with template type ft_vector and deque
    file << "### DEFAULT CONSTRUCTOR WITH FT_VECTOR ###" << std::endl;
//    file << "$ 11. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
//    file << "[ stack.size() = " << stack.size() << "]" << std::endl;

    file << "### DEFAULT CONSTRUCTOR WITH STD_DEQUE ###" << std::endl;
//    file << "$ 11. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
//    file << "[ stack.size() = " << stack.size() << "]" << std::endl;

    file << "### DEFAULT CONSTRUCTOR DEFAULT SETTINGS ###" << std::endl;
//    file << "$ 11. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
//    file << "[ stack.size() = " << stack.size() << "]" << std::endl;
}

void checkCapacity(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### SIZE ###" << std::endl;
//    ft::vector<std::string> vectorSize(100, "vectorSizeTest");
//    file << "$ 165. ft::vector<std::string> vectorSize(100, \"vectorSizeTest\");" << std::endl;
//    file << "[ vectorSize.size() = " << vectorSize.size() << "]" << std::endl;

    file << "### EMPTY ###" << std::endl;
//    bool empt = vectorSize.empty();
//    file << "$ 199. bool empt = vectorSize.empty();" << std::endl;
//    file << "[ vectorSize.empty() = " << empt << "]" << std::endl;
}

void checkModifiersAndAccessElements(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### PUSH ###" << std::endl;
    //    vectorSize.push_back("newItem");
    //    vectorSize.push_back("newItem");
    //    vectorSize.push_back("newItem");
    //    file << "$ 174. vectorSize.push_back(\"newItem\");" << std::endl;
    //    file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
    //    file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
    file << "### POP ###" << std::endl;
//    vectorSize.pop_back();
//    file << "$ 170. vectorSize.pop_back();" << std::endl;
//    file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
//    file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
    file << "### TOP ###" << std::endl;
    //    vectorSize.pop_back();
    //    file << "$ 170. vectorSize.pop_back();" << std::endl;
    //    file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
    //    file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
    file << "### CONSTANT TOP ###" << std::endl;
    //    vectorSize.pop_back();
    //    file << "$ 170. vectorSize.pop_back();" << std::endl;
    //    file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
    //    file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
}

void checkComparison(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### OPERATOR == ###" << std::endl;
    file << "### OPERATOR != ###" << std::endl;
    file << "### OPERATOR > ###" << std::endl;
    file << "### OPERATOR < ###" << std::endl;
    file << "### OPERATOR >= ###" << std::endl;
    file << "### OPERATOR <= ###" << std::endl;
}

void testStack(bool containerType) {
	std::string fileName = containerType ? "ft_stack" : "std_stack";
	std::ofstream file;
	file.open(fileName);
	if (file.is_open()) {
	    checkConstructors(file, containerType);
	    checkCapacity(file, containerType);
	    checkModifiersAndAccessElements(file, containerType);
	    checkComparison(file, containerType);
	}
}
