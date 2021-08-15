//
// Created by Tothmure Isabel on 7/28/21.
//

#include "SetTest.hpp"

void checkSetConstructors(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### DEFAULT CONSTRUCTOR ###" << std::endl;

	file << "### CONSTRUCTOR WITH ITERATOR ###" << std::endl;

	file << "### COPY CONSTRUCTOR ###" << std::endl;

	file << "### ASSIGNATION OPERATOR ###" << std::endl;
}

void checkSetIterators(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### ITERATORS BEGIN - END ###" << std::endl;

	file << "### CONST ITERATORS BEGIN - END ###" << std::endl;

	file << "### ITERATORS RBEGIN - REND ###" << std::endl;

	file << "### CONST ITERATORS RBEGIN - REND ###" << std::endl;

	file << "### ITERATOR OPERATORS ###" << std::endl;

	file << "### ITERATOR COMPARISON ###" << std::endl;
//	ft::vector<int>::iterator itTwo = vectorInt.begin();
//	file << "$ 134. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;
//	file << "[ ";
//	file << (it == itTwo) << ", ";
//	file << (it != itTwo) << ", ";
//	file << (it > itTwo) << ", ";
//	file << (it < itTwo) << ", ";
//	file << (it >= itTwo) << ", ";
//	file << (it <= itTwo);
//	file << " ]" << std::endl;

	file << "### ITERATOR ADD AND DEL ###" << std::endl;
//	ft::vector<int>::iterator itThree;
//	itThree = itTwo;
//	itThree = itThree + it; // TODO how iterator addition and dif work?
//	file << "$ 148. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;

	file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
//    ft::vector<int>::reverse_iterator itConstReverseIter = vectorInt.rbegin();
//    file << "$ 153. ft::vector<float>::const_reverse_iterator itConstReverseIter = vectorN.rbegin();" << std::endl;
//    file << "[ ";
//    itConstReverseIter += 3;
//    file << *itConstReverseIter;
//    file << " ]" << std::endl; TODO fix reverse iterators
}

void checkSetCapacityAndAccessElements(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### SIZE, MAX_SIZE ###" << std::endl;
//	ft::vector<std::string> vectorSize(100, "vectorSizeTest");
//	file << "$ 165. ft::vector<std::string> vectorSize(100, \"vectorSizeTest\");" << std::endl;
//	file << "[ vectorSize.max_size() = " << vectorSize.max_size() << ";";
//	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;

	file << "### EMPTY ###" << std::endl;
//	bool empt = vectorSize.empty();
//	file << "$ 199. bool empt = vectorSize.empty();" << std::endl;
//	file << "[ vectorSize.empty() = " << empt << "]" << std::endl;

//	file << "### [] OPERATOR ###" << std::endl;
//
	file << "### CLEAR ###" << std::endl;
}

void checkSetModifiers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### INSERT SINGLE ELEMENT ###" << std::endl;

	file << "### INSERT WITH HINT ###" << std::endl;

	file << "### INSERT ITERATOR RANGE ###" << std::endl;

	file << "### ERASE BY ITERATOR ###" << std::endl;

	file << "### ERASE BY VALUE ###" << std::endl;

	file << "### ERASE ITERATOR RANGE ###" << std::endl;

	file << "### SWAP ###" << std::endl;
}

void checkSetObservers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### KEY_COMPARE ###" << std::endl;

	file << "### VALUE_COMPARE ###" << std::endl;

	file << "### GET_ALLOCATOR ###" << std::endl;
}

void checkSetOperations(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### FIND ###" << std::endl;

	file << "### COUNT ###" << std::endl;

	file << "### LOWER_BOUND ###" << std::endl;

	file << "### UUPPER_BOUND ###" << std::endl;

}

void testSet(bool containerType) {
	std::string fileName = containerType ? "ft_set" : "std_set";
	std::ofstream file;
	file.open(fileName);
	if (file.is_open()) {
		checkSetConstructors(file, containerType);
		checkSetIterators(file, containerType);
		checkSetCapacityAndAccessElements(file, containerType);
		checkSetModifiers(file, containerType);
		checkSetObservers(file, containerType);
		checkSetOperations(file, containerType);
	}
}
