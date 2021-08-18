//
// Created by Tothmure Isabel on 7/28/21.
//

#include "MapTest.hpp"

void checkMapConstructors(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### DEFAULT CONSTRUCTOR ###" << std::endl;
	ft::map<int, std::string> newMap = ft::map<int, std::string>();
	file << "$ 12. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << ";";
	newMap[0] = "Zero";
	newMap[1] = "One";
	newMap[4] = "Four";
	newMap[30] = "Thirty";
	newMap[10] = "Ten";
	newMap[7] = "Seven";
	newMap[11] = "Eleven";
	newMap[45] = "Forty Five";
	newMap[50] = "Fifty";
	file << " newMap.size() = " << newMap.size() << "]" << std::endl;


//	file << "### CONSTRUCTOR WITH ITERATOR ###" << std::endl;
//	ft::map<int, std::string> mapByIterator(newMap.begin(), newMap.end());
//	file << "$ 26. ft::map<std::string, std::string> mapText(newMap.begin(), newMap.end());" << std::endl;
//	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;
//	file << "[" << (newMap[4] == mapByIterator[4]) << "]" << std::endl;

//    file << "### COPY CONSTRUCTOR ###" << std::endl;
//    ft::map<int, std::string> copyMap(newMap);
//	file << "$ 31. ft::map<int, std::string> copyMap(newMap);" << std::endl;
//	file << "[ copyMap.size() = " << copyMap.size() << "]" << std::endl;
//	file << "[ newMap == to copyMap? : " << (newMap[30] == copyMap[30]) << "]" << std::endl;

	file << "### ASSIGNATION OPERATOR ###" << std::endl;
	ft::map<int, std::string> secondNewMap = ft::map<int, std::string>();
	secondNewMap[0] = "00000";
	secondNewMap[1] = "11111";
	secondNewMap[4] = "44444";
	secondNewMap[30] = "303030";
	secondNewMap[10] = "101010";
	secondNewMap[7] = "77777";
	secondNewMap[11] = "11111111";
	secondNewMap[45] = "454545";
	secondNewMap[50] = "505050";
	newMap = secondNewMap;
	file << "$ 31. ft::map<int, std::string> copyMap(newMap);" << std::endl;
	file << "[ newMap.size() = " << secondNewMap.size() << ";";
	file << " copyMap.size() = " << newMap.size() << "]" << std::endl;
//	file << "[ newMap == to secondNewMap? : " << (newMap[30] == secondNewMap[30]) << "]" << std::endl;
}

void checkMapIterators(std::ofstream &file, bool containerType) {
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

void checkMapCapacityAndAccessElements(std::ofstream &file, bool containerType) {
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

	file << "### [] OPERATOR ###" << std::endl;

	file << "### CLEAR ###" << std::endl;
}

void checkMapModifiers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### INSERT SINGLE ELEMENT ###" << std::endl;

	file << "### INSERT WITH HINT ###" << std::endl;

    file << "### INSERT ITERATOR RANGE ###" << std::endl;

	file << "### ERASE BY ITERATOR ###" << std::endl;

	file << "### ERASE BY KEY ###" << std::endl;

	file << "### ERASE ITERATOR RANGE ###" << std::endl;

	file << "### SWAP ###" << std::endl;
}

void checkMapObservers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### KEY_COMPARE ###" << std::endl;

	file << "### VALUE_COMPARE ###" << std::endl;

	file << "### GET_ALLOCATOR ###" << std::endl;
}

void checkMapOperations(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### FIND ###" << std::endl;

	file << "### CONST FIND ###" << std::endl;

	file << "### COUNT ###" << std::endl;

	file << "### LOWER_BOUND ###" << std::endl;

	file << "### UUPPER_BOUND ###" << std::endl;

	file << "### EQUAL_RANGE ###" << std::endl;
}

void testMap(bool containerType) {
	std::string fileName = containerType ? "ft_map" : "std_map";
	std::ofstream file;
	file.open(fileName);
	if (file.is_open()) {
		checkMapConstructors(file, containerType);
		checkMapIterators(file, containerType);
		checkMapCapacityAndAccessElements(file, containerType);
		checkMapModifiers(file, containerType);
		checkMapObservers(file, containerType);
		checkMapOperations(file, containerType);
	}
}
