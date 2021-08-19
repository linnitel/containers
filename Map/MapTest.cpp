//
// Created by Tothmure Isabel on 7/28/21.
//

#include "MapTest.hpp"
#include "../utils/MyInt.hpp"

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

//	file << "### ASSIGNATION OPERATOR ###" << std::endl;
//	ft::map<int, std::string> secondNewMap = ft::map<int, std::string>();
//	secondNewMap[0] = "00000";
//	secondNewMap[1] = "11111";
//	secondNewMap[4] = "44444";
//	secondNewMap[30] = "303030";
//	secondNewMap[10] = "101010";
//	secondNewMap[7] = "77777";
//	secondNewMap[11] = "11111111";
//	secondNewMap[45] = "454545";
//	secondNewMap[50] = "505050";
//	newMap = secondNewMap;
//	file << "$ 31. ft::map<int, std::string> copyMap(newMap);" << std::endl;
//	file << "[ newMap.size() = " << secondNewMap.size() << ";";
//	file << " copyMap.size() = " << newMap.size() << "]" << std::endl;
////	file << "[ newMap == to secondNewMap? : " << (newMap[30] == secondNewMap[30]) << "]" << std::endl;
}

void checkMapIterators(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::map<int, std::string> newMap = ft::map<int, std::string>();
	file << "$ 12. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	newMap[0] = "Zero";
	newMap[1] = "One";
	newMap[4] = "Four";
	newMap[30] = "Thirty";
	newMap[10] = "Ten";
	newMap[7] = "Seven";
	newMap[11] = "Eleven";
	newMap[45] = "Forty Five";
	newMap[50] = "Fifty";
	file << "### ITERATORS BEGIN - END ###" << std::endl;
	file << "$ 77. for (ft::map<int, std::string>::iterator it = newMap.begin(); it != newMap.end(); it++) {" << std::endl;
	file << "[";
	for (ft::map<int, std::string>::iterator it = newMap.begin(); it != newMap.end(); it++) {
	    file << " = " << (it->getData()).first << "; ";
	}
	file << "]" << std::endl;

//	file << "### CONST ITERATORS BEGIN - END ###" << std::endl;
//	file << "$ 83. for (ft::map<int, std::string>::iterator it = newMap.begin(); it != newMap.end(); it++) {" << std::endl;
//	file << "[";
//	for (ft::map<int, std::string>::const_iterator it = newMap.begin(); it != newMap.end(); it++) {
//	    file << " = " << (it->getData()).first << "; ";
//	}
//	file << "]" << std::endl;

//    file << "### ITERATORS RBEGIN - REND ###" << std::endl;
//    file << "$ 91. for (ft::map<int, std::string>::iterator it = newMap.begin(); it != newMap.end(); it++) {" << std::endl;
//    file << "[";
//    for (ft::map<int, std::string>::reverse_iterator it = newMap.rbegin(); it != newMap.rend(); it++) {
//        file << " = " << (it->getData()).first << "; ";
//    }
//    file << "]" << std::endl;

//	file << "### CONST ITERATORS RBEGIN - REND ###" << std::endl;
//	file << "$ 99. for (ft::map<int, std::string>::iterator it = newMap.begin(); it != newMap.end(); it++) {" << std::endl;
	//	file << "[";
	//	for (ft::map<int, std::string>::const_reverse_iterator it = newMap.rbegin(); it != newMap.rend(); it++) {
	//	    file << " = " << (it->getData()).first << "; ";
	//	}
	//	file << "]" << std::endl;

	file << "### ITERATOR OPERATORS ###" << std::endl;
	ft::map<myInt, std::string> myIntMap = ft::map<myInt, std::string>();
	file << "$ 12. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	myIntMap[myInt(0)] = "Zero";
	myIntMap[myInt(1)] = "One";
	myIntMap[myInt(4)] = "Four";
	myIntMap[myInt(30)] = "Thirty";
	myIntMap[myInt(10)] = "Ten";
	myIntMap[myInt(7)] = "Seven";
	myIntMap[myInt(11)] = "Eleven";
	myIntMap[myInt(45)] = "Forty Five";
	myIntMap[myInt(50)] = "Fifty";
	ft::map<myInt, std::string>::iterator it = myIntMap.begin();
	file << "$ 117. ft::map<myInt, std::string>::iterator it = myIntMap.begin();" << std::endl;
	file << "[ ";
	file << (it->getData()).first << ", ";
	++it;
	file << ((*it).getData()).first << ", ";
	it++;
	file << ((*it).getData()).first << ", ";
	it--;
	file << (it->getData()).first << ", ";
	--it;
	file << (it->getData()).first << ", ";
	file << "] " << std::endl;

	file << "### ITERATOR COMPARISON ###" << std::endl;
	ft::map<myInt, std::string> secondMyIntMap = ft::map<myInt, std::string>();
	file << "$ 132. ft::map<myInt, std::string>::iterator it = myIntMap.begin();" << std::endl;
	    secondMyIntMap[myInt(0)] = "00000";
		secondMyIntMap[myInt(1)] = "11111";
		secondMyIntMap[myInt(4)] = "44444";
		secondMyIntMap[myInt(30)] = "303030";
		secondMyIntMap[myInt(10)] = "101010";
		secondMyIntMap[myInt(7)] = "77777";
		secondMyIntMap[myInt(11)] = "11111111";
		secondMyIntMap[myInt(45)] = "454545";
		secondMyIntMap[myInt(50)] = "505050";
    ft::map<myInt, std::string>::iterator itOne = myIntMap.begin();
    ft::map<myInt, std::string>::iterator itTwo = secondMyIntMap.begin();
	file << "[ ";
	file << (it == itTwo) << ", ";
	file << (it != itTwo) << ", ";
	file << " ]" << std::endl;

//    file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
//    ft::map<myInt, std::string>::const_reverse_iterator reverseIt = myIntMap.rbegin(); // TODO make separate iterators for const
//    file << "$ 117. ft::map<myInt, std::string>::iterator it = myIntMap.begin();" << std::endl;
//    file << "[ ";
//    file << (it->getData()).first << ", ";
//    ++it;
//    file << ((*it).getData()).first << ", ";
//    it++;
//    file << ((*it).getData()).first << ", ";
//    it--;
//    file << (it->getData()).first << ", ";
//    --it;
//    file << (it->getData()).first << ", ";
//    file << "] " << std::endl;
}

void checkMapCapacityAndAccessElements(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::map<std::string, std::string> stringMap = ft::map<std::string, std::string>();
	file << "$ 170. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	stringMap["1"] = "Zero";
	stringMap["12"] = "One";
	stringMap["123"] = "Four";
	stringMap["1234"] = "Thirty";
	stringMap["12345"] = "Ten";
	stringMap["123456"] = "Seven";
	stringMap["1234567"] = "Eleven";
	stringMap["12345678"] = "Forty Five";
	stringMap["123456789"] = "Fifty";
	file << "### SIZE, MAX_SIZE ###" << std::endl;
    file << "[ stringMap.max_size() = " << stringMap.max_size() << ";";
    file << " stringMap.size() = " << stringMap.size() << "]" << std::endl;

	file << "### EMPTY ###" << std::endl;
	bool empt = stringMap.empty();
	file << "$ 186. bool empt = stringMap.empty();" << std::endl;
	file << "[ stringMap.empty() = " << empt << "]" << std::endl;

	file << "### [] OPERATOR ###" << std::endl;
	std::string outputOfMap = stringMap["123456"];
	file << "$ 191. std::string outputOfMap = stringMap[\"123456\"];" << std::endl;
	file << "[ stringMap[\"123456\"] = " << outputOfMap << "]" << std::endl;

	file << "### CLEAR ###" << std::endl;
	stringMap.clear();
	file << "$ 196. stringMap.clear();" << std::endl;
	file << "[ stringMap.size() = " << stringMap.size() << "]" << std::endl;
}

void checkMapModifiers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::map<int, std::string> newMap = ft::map<int, std::string>();
	newMap[0] = "Zero";
	newMap[1] = "One";
	newMap[4] = "Four";
	newMap[30] = "Thirty";
	newMap[10] = "Ten";
	newMap[7] = "Seven";
	newMap[11] = "Eleven";
	newMap[45] = "Forty Five";
	newMap[50] = "Fifty";
	file << "### INSERT SINGLE ELEMENT ###" << std::endl;
	file << "$ 218. newMap.insert(ft::pair<int, std::string>(5, \"Five\"));" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;
	newMap.insert(ft::pair<int, std::string>(5, "Five"));
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;

	file << "### INSERT WITH HINT ###" << std::endl;
	file << "$ 218. newMap.insert(ft::pair<int, std::string>(5, \"Five\"));" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;
	newMap.insert(ft::map<int, std::string>::iterator(newMap.begin()), ft::pair<int, std::string>(12, "Twelve"));
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;

    file << "### INSERT ITERATOR RANGE ###" << std::endl;
    ft::map<int, std::string> rangeMap = ft::map<int, std::string>();
    rangeMap[79] = "Seventy Nine";
    rangeMap[177] = "One Hundred Seventy Seven";
    rangeMap[42] = "Quarante-deux";
    rangeMap[21] = "Vingt-et-un";
    ft::map<int, std::string>::iterator begin(rangeMap.begin());
    ft::map<int, std::string>::iterator end(rangeMap.end());
    newMap.insert(begin, end);
    file << "$ 235. newMap.insert(begin, end);" << std::endl;
    file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;

	file << "### ERASE BY ITERATOR ###" << std::endl;
	file << "$ 242. newMap.erase(ft::map<int, std::string>::iterator(newMap.begin()));" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << "] ";
	newMap.erase(ft::map<int, std::string>::iterator(newMap.begin()));
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;

	file << "### ERASE BY KEY ###" << std::endl;
	file << "$ 248. size_t numDel = newMap.erase(79);" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << ";";
	size_t numDel = newMap.erase(79);
	file << "number of deleted elements: " << numDel << "; ";
	numDel = newMap.erase(179);
	file << "number of deleted elements: " << numDel << "; ";
	file << " newMap.size() = " << newMap.size() << "]" << std::endl;

	file << "### ERASE ITERATOR RANGE ###" << std::endl;
	file << "$ 242. newMap.erase(ft::map<int, std::string>::iterator(newMap.begin()));" << std::endl;
	file << "[ newMap.size() = " << newMap.size() << "] ";
	newMap.erase(ft::map<int, std::string>::iterator(newMap.begin()), ft::map<int, std::string>::iterator(newMap.end()));
	file << "[ newMap.size() = " << newMap.size() << "]" << std::endl;

//	file << "### SWAP ###" << std::endl;
}

void checkMapOperations(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::map<int, std::string> newMap = ft::map<int, std::string>();
	newMap[0] = "Zero";
	newMap[1] = "One";
	newMap[4] = "Four";
	newMap[30] = "Thirty";
	newMap[10] = "Ten";
	newMap[7] = "Seven";
	newMap[11] = "Eleven";
	newMap[45] = "Forty Five";
	newMap[50] = "Fifty";
	file << "### FIND ###" << std::endl;
	ft::map<int, std::string>::iterator serchedVal = newMap.find(7);
	file << "$ 268. size_t numDel = newMap.erase(79);" << std::endl;
	file << "[ key of element: " << (serchedVal->getData()).first << "; ";
	file << " value of element: " << (serchedVal->getData()).second << "]" << std::endl;

//	file << "### CONST FIND ###" << std::endl;
//	ft::map<int, std::string>::const_iterator serchedValConst = newMap.find(7);
//	file << "$ 284. size_t numDel = newMap.erase(79);" << std::endl;
//	file << "key of element: " << (serchedValConst->getData()).first << "; ";
//	file << " value of element: " << (serchedValConst->getData()).second << "]" << std::endl;

	file << "### COUNT ###" << std::endl;
	size_t count = newMap.count(45);
	file << "$ 290. newMap.count(45);" << std::endl;
	file << "[ num of elements 45: " << count << "; ";
	count = newMap.count(54);
	file << " num of elements 54: " << count << "]" << std::endl;

	file << "### LOWER_BOUND ###" << std::endl;
	ft::map<int, std::string>::iterator lowerBound = newMap.lower_bound(45);
	file << "$ 297. ft::map<int, std::string>::iterator lowerBound = newMap.lower_bound(45);" << std::endl;
	file << "[ lower bound 45: " << lowerBound->getData().first << "; ";
	lowerBound = newMap.lower_bound(60);
	file << " lower bound 60: " << lowerBound->getData().first << "]" << std::endl;

	file << "### UUPPER_BOUND ###" << std::endl;
	ft::map<int, std::string>::iterator upperBound = newMap.upper_bound(45);
	file << "$ 297. ft::map<int, std::string>::iterator upperBound = newMap.upper_bound(45);" << std::endl;
	file << "[ upper bound 45: " << upperBound->getData().first << "; ";
	upperBound = newMap.upper_bound(60);
	file << " upper bound 60: " << upperBound->getData().first << "]" << std::endl;

	file << "### EQUAL_RANGE ###" << std::endl;
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> pair = newMap.equal_range(45);
	file << "$ 311. ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> pair = newMap.equal_range(45);" << std::endl;
	file << "[ upper bound 45: " << pair.second->getData().first << "; ";
	file << "lower bound 45: " << pair.first->getData().first << "; ";
	pair = newMap.equal_range(60);
	file << "lower bound 60: " << pair.first->getData().first << "; ";
	file << " upper bound 60: " << pair.second->getData().first << "]" << std::endl;
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
		checkMapOperations(file, containerType);
	}
}
