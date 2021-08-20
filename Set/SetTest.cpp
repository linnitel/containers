//
// Created by Tothmure Isabel on 7/28/21.
//

#include "SetTest.hpp"

void checkSetConstructors(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### DEFAULT CONSTRUCTOR ###" << std::endl;
	ft::set<int> newSet = ft::set<int>();
	file << "$ 12. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	file << "[ newMap.size() = " << newSet.size() << ";";
	newSet.insert(0);
	newSet.insert(1);
	newSet.insert(4);
	newSet.insert(5);
	newSet.insert(10);
	newSet.insert(7);
	newSet.insert(11);
	newSet.insert(40);
	newSet.insert(30);
	file << " newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### CONSTRUCTOR WITH ITERATOR ###" << std::endl;
	ft::set<int> iteratorSet = ft::set<int>(newSet.begin(), newSet.end());
	file << "$ 27. ft::map<int, std::string> newMap = ft::map<int, std::string>();" << std::endl;
	file << "[ iteratorSet.size() = " << iteratorSet.size() << "]" << std::endl;

//	file << "### COPY CONSTRUCTOR ###" << std::endl;
//	ft::set<int> copySet = ft::set<int>(newSet);
//	file << "$ 32. ft::set<int> copySet = ft::set<int>(newSet);" << std::endl;
//	file << "[ copySet.size() = " << copySet.size() << "]" << std::endl;

//	file << "### ASSIGNATION OPERATOR ###" << std::endl;
//	ft::set<int> testSet = ft::set<int>();
//	testSet.insert(500);
//	testSet.insert(100);
//	testSet.insert(400);
//	testSet.insert(50);
//	testSet.insert(10000);
//	file << "$ 45. testSet = newSet;" << std::endl;
//	file << "[ testSet.size() = " << testSet.size() << "]" << std::endl;
//	testSet = newSet;
//	file << "[ testSet.size() = " << testSet.size() << "]" << std::endl;
}

void checkSetIterators(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::set<myInt> newSet = ft::set<myInt>();
	newSet.insert(myInt(500));
	newSet.insert(myInt(100));
	newSet.insert(myInt(400));
	newSet.insert(myInt(50));
	newSet.insert(myInt(10000));
	file << "### ITERATORS BEGIN - END ###" << std::endl;
	file << "$ 62. for (ft::set<myInt>::iterator it = newSet.begin(); it != newSet.end(); it++) {" << std::endl;
	file << "[ ";
	for (ft::set<myInt>::iterator it = newSet.begin(); it != newSet.end(); it++) {
		file << it->getData().first << "; ";
	}
	file << "] " << std::endl;

//	file << "### CONST ITERATORS BEGIN - END ###" << std::endl;
//	for (ft::set<myInt>::const_iterator it = newSet.begin(); it != newSet.end(); it++) {
//		file << it->getData().first << "; ";
//	}
//	file << "] " << std::endl;

	file << "### ITERATORS RBEGIN - REND ###" << std::endl;
	file << "$ 76. for (ft::set<myInt>::reverse_iterator it = newSet.rbegin(); it != newSet.rend(); it++) {" << std::endl;
	file << "[ ";
	for (ft::set<myInt>::reverse_iterator it = newSet.rbegin(); it != newSet.rend(); it++) {
		file << it->getData().first << "; ";
	}
	file << "] " << std::endl;

//	file << "### CONST ITERATORS RBEGIN - REND ###" << std::endl;
//	file << "$ 84. for (ft::set<myInt>::const_reverse_iterator it = newSet.rbegin(); it != newSet.rend(); it++) {" << std::endl;
//	file << "[ ";
//	for (ft::set<myInt>::const_reverse_iterator it = newSet.rbegin(); it != newSet.rend(); it++) {
//		file << it->getData().first << "; ";
//	}
//	file << "] " << std::endl;

	file << "### ITERATOR OPERATORS ###" << std::endl;
	ft::set<myInt>::iterator it = newSet.begin();
	file << "$ 90. ft::set<myInt>::iterator it = newSet.begin();" << std::endl;
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
	ft::set<std::string> testSetOne = ft::set<std::string>();
	testSetOne.insert("One");
	testSetOne.insert("Two");
	testSetOne.insert("three");
	testSetOne.insert("da kakaya raznitsa");
	testSetOne.insert("who is it?");
	testSetOne.insert("1245");
	testSetOne.insert("I go and search for you");
	testSetOne.insert("Simple dimple");
	testSetOne.insert("pop it");
	ft::set<std::string> testSetTwo = ft::set<std::string>();
	testSetTwo.insert("One");
	testSetTwo.insert("Two");
	testSetTwo.insert("three");
	testSetTwo.insert("da kakaya raznitsa");
	testSetTwo.insert("who is it?");
	testSetTwo.insert("1245");
	testSetTwo.insert("I go and search for you");
	testSetTwo.insert("Simple dimple");
	testSetTwo.insert("pop it");
	ft::set<std::string>::iterator itOne = testSetOne.begin();
    ft::set<std::string>::iterator itTwo = testSetTwo.begin();
	file << "[ ";
	for(; itOne != testSetOne.end(); it++) {
		file << (itOne == itTwo) << ", ";
		file << (itOne != itTwo) << ", ";
	}
	file << " ]" << std::endl;

	file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
	ft::set<std::string>::reverse_iterator reverseIt = testSetOne.rbegin();
	file << "$ 117. ft::map<myInt, std::string>::iterator it = myIntMap.begin();" << std::endl;
	file << "[ ";
	file << (reverseIt->getData()).first << ", ";
	++reverseIt;
	file << ((*reverseIt).getData()).first << ", ";
	reverseIt++;
	file << ((*reverseIt).getData()).first << ", ";
	reverseIt--;
	file << (reverseIt->getData()).first << ", ";
	--reverseIt;
	file << (reverseIt->getData()).first << ", ";
	file << "] " << std::endl;
}

void checkSetCapacityAndAccessElements(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::set<int> newSet = ft::set<int>();
	newSet.insert(0);
	newSet.insert(1);
	newSet.insert(4);
	newSet.insert(5);
	newSet.insert(10);
	newSet.insert(7);
	newSet.insert(11);
	newSet.insert(40);
	newSet.insert(30);
	file << "### SIZE, MAX_SIZE ###" << std::endl;
	file << "[ stringMap.max_size() = " << newSet.max_size() << ";";
	file << " stringMap.size() = " << newSet.size() << "]" << std::endl;

	file << "### EMPTY ###" << std::endl;
	bool empt = newSet.empty();
	file << "$ 169. bool empt = newSet.empty();" << std::endl;
	file << "[ newSet.empty() = " << empt << "]" << std::endl;

	file << "### CLEAR ###" << std::endl;
	newSet.clear();
	file << "$ 174. newSet.clear();" << std::endl;
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;
}

void checkSetModifiers(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### INSERT SINGLE ELEMENT ###" << std::endl;
	file << "$ 186. newSet.insert(0);" << std::endl;
	ft::set<int> newSet = ft::set<int>();
	newSet.insert(0);
	newSet.insert(1);
	newSet.insert(4);
	newSet.insert(5);
	newSet.insert(10);
	file << "[ newMap.size() = " << newSet.size() << "]" << std::endl;
	newSet.insert(7);
	newSet.insert(11);
	newSet.insert(40);
	newSet.insert(30);
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### INSERT WITH HINT ###" << std::endl;
	file << "$ 200. newSet.insert(ft::set<int>::iterator(newSet.find(7)), 8);" << std::endl;
	newSet.insert(ft::set<int>::iterator(newSet.find(7)), 8);
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### INSERT ITERATOR RANGE ###" << std::endl;
	ft::set<int> additionalSet = ft::set<int>();
	additionalSet.insert(500);
	additionalSet.insert(100);
	additionalSet.insert(400);
	additionalSet.insert(50);
	additionalSet.insert(10000);
	file << "$ 211. newSet.insert(additionalSet.begin(), additionalSet.end());" << std::endl;
	newSet.insert(additionalSet.begin(), additionalSet.end());
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### ERASE BY ITERATOR ###" << std::endl;
	file << "$ 217. newSet.erase(newSet.begin());" << std::endl;
	file << "[ newSet.size() = " << newSet.size() << "] ";
	newSet.erase(newSet.begin());
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### ERASE BY VALUE ###" << std::endl;
	file << "$ 217. newSet.erase(newSet.begin());" << std::endl;
	file << "[ newSet.size() = " << newSet.size() << "] ";
	newSet.erase(10);
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;
	file << "$ 226. newSet.erase(101);" << std::endl;
	newSet.erase(101);
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### ERASE ITERATOR RANGE ###" << std::endl;
	file << "$ 231. newSet.erase(newSet.begin(), newSet.end());" << std::endl;
	newSet.erase(newSet.begin(), newSet.end());
	file << "[ newSet.size() = " << newSet.size() << "]" << std::endl;

	file << "### SWAP ###" << std::endl;
	file << "$ 236. newSet.swap(additionalSet);" << std::endl;
	size_t size = newSet.size();
	newSet.swap(additionalSet);
	file << "[ newSet.size() = old size ?" << (newSet.size() == size) << "]" << std::endl;
}

void checkSetOperations(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::set<int> newSet = ft::set<int>();
	newSet.insert(500);
	newSet.insert(100);
	newSet.insert(400);
	newSet.insert(50);
	newSet.insert(10000);
	file << "### FIND ###" << std::endl;
	file << "$ 253. (newSet.find(7) == newSet.end());" << std::endl;
	file << "[ find non present " << (newSet.find(7) == newSet.end()) << "; " << std::endl;
	file << " find present " << newSet.find(100)->getData().first << "]" << std::endl;

	file << "### COUNT ###" << std::endl;
	size_t count = newSet.count(45);
	file << "$ 290. newMap.count(45);" << std::endl;
	file << "[ num of elements 45: " << count << "; ";
	count = newSet.count(50);
	file << " num of elements 50: " << count << "]" << std::endl;

//	file << "### LOWER_BOUND ###" << std::endl;
//	ft::set<int>::iterator lowerBound = newSet.lower_bound(45);
//	file << "$ 264. ft::set<int>::iterator lowerBound = newSet.lower_bound(45);" << std::endl;
//	file << "[ lower bound 45: " << lowerBound->getData().first << "; ";
//	lowerBound = newSet.lower_bound(100);
//	file << " lower bound 100: " << lowerBound->getData().first << "]" << std::endl;

//	file << "### UUPPER_BOUND ###" << std::endl;
//	ft::set<int>::iterator upperBound = newSet.upper_bound(450);
//	file << "$ 264. ft::set<int>::iterator upperBound = newSet.upper_bound(45);" << std::endl;
//	file << "[ upper bound 450: " << upperBound->getData().first << "; ";
//	upperBound = newSet.upper_bound(100);
//	file << " upper bound 100: " << upperBound->getData().first << "]" << std::endl;

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
		checkSetOperations(file, containerType);
	}
}
