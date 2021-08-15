
#include "VectorTest.hpp"
#include <fstream>

void checkConstructors(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### DEFAULT CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorDef = ft::vector<std::string>();
    file << "$ 11. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
    file << "[ vectorDef.capacity() = " << vectorDef.capacity() << ";";
    file << " vectorDef.size() = " << vectorDef.size() << "]" << std::endl;

    file << "### CONSTRUCTOR WITH N ###" << std::endl;
    ft::vector<std::string> vectorN(3, "this");
    file << "$ 17. ft::vectorN<std::string> vectorN(10, \"this\");" << std::endl;
    file << "[ vectorN.capacity() = " << vectorN.capacity() << ";";
    file << " vectorN.size() = " << vectorN.size() << ";";
    file << " vectorN = [";
    for (int i = 0; i < vectorN.size(); i++) {
        file << vectorN[i];
        if (i != vectorN.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;

    file << "### CONSTRUCTOR WITH ITERATOR ###" << std::endl;
    ft::vector<std::string> vectorIter(vectorN.begin(), vectorN.end());
    file << "$ 33. ft::vector<std::string> vectorIter(vector.begin(), vector.end());" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << "]" << std::endl;

    file << "### COPY CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorCopy = vectorIter;
    file << "$ 39. ft::vector<std::string> vectorCopy = vectorIter;" << std::endl;
    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;

    file << "### ASSIGNATION OPERATOR ###" << std::endl;
    vectorCopy = vectorIter;
    file << "$ 45. vectorCopy = vectorIter;" << std::endl;
    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;
}

void checkIterators(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    ft::vector<float> vectorN(5, 45.89234);
    file << "### ITERATORS BEGIN - END ###" << std::endl;
    ft::vector<float> vectorIter(vectorN.begin(), vectorN.end());
    file << "$ 57. ft::vector<float> vectorIter(vectorN.begin(), vectorN.end());" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << ";";
    file << " vectorIter = [";
    for (int i = 0; i < vectorN.size(); i++) {
        file << vectorN[i];
        if (i != vectorN.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;

//    file << "### ITERATORS RBEGIN - REND ###" << std::endl;
//    ft::vector<float> vectorReverseIter(vectorN.rbegin(), vectorN.rend());
//    file << "$ 133. ft::vector<float> vectorIter(vectorN.rbegin(), vectorN.rend());" << std::endl;
//    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
//    file << " vectorIter.size() = " << vectorIter.size() << ";";
//    file << "[";
//    for (ft::vector<float>::reverse_iterator it = vectorReverseIter.rbegin(); it != vectorReverseIter.rend(); it++) {
//        file << *it;
//        if (*it != vectorN[0]) {
//            file << ", ";
//        } else {
//            file << "]";
//        }
//    }
//    file << " ]" << std::endl; TODO fix const Iterators

    file << "### PUSH_BACK ###" << std::endl;
    ft::vector<int> vectorInt;
    for (int i = 0; i < 6; i++) {
        vectorInt.push_back(i);
    }
    file << "$ 91. vectorInt.push_back(i);" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << ";";
    file << "[ ";
    for (int i = 0; i < vectorInt.size(); i++) {
        file << vectorInt[i];
        if (i != vectorInt.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;

    file << "### ITERATOR OPERATORS ###" << std::endl;
    ft::vector<int>::iterator it = vectorInt.begin();
    file << "$ 108. ft::vector<int>::iterator it = vectorInt.begin();" << std::endl;
    file << "[ ";
    it += 4;
    file << *it << ", ";
    it--;
    file << *it << ", ";
    --it;
    file << *it << ", ";
	if (it[5]) {
		file << "OK" << ", ";
	} else {
		file << "KO" << ", ";
	}
//	file << it[4] << ", "; // TODO what does [] thing do?
    ++it;
    file << *it << ", ";
	it -= 2;
	file << *it << ", ";
	it = it + 3;
	file << *it << ", ";
	it = it - 3;
	file << *it;
    // file << it->something << ", "; // TODO what does -> thing do?
    file << " ]" << std::endl;

	file << "### ITERATOR COMPARISON ###" << std::endl;
	ft::vector<int>::iterator itTwo = vectorInt.begin();
	file << "$ 134. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;
	file << "[ ";
	file << (it == itTwo) << ", ";
	file << (it != itTwo) << ", ";
	file << (it > itTwo) << ", ";
	file << (it < itTwo) << ", ";
	file << (it >= itTwo) << ", ";
	file << (it <= itTwo);
	file << " ]" << std::endl;

//	file << "### ITERATOR ADD AND DEL ###" << std::endl;
//	ft::vector<int>::iterator itThree;
//	itThree = itTwo;
//	itThree = itThree + it; // TODO how iterator addition and dif work?
//	file << "$ 148. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;

//    file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
//    ft::vector<int>::reverse_iterator itConstReverseIter = vectorInt.rbegin();
//    file << "$ 153. ft::vector<float>::const_reverse_iterator itConstReverseIter = vectorN.rbegin();" << std::endl;
//    file << "[ ";
//    itConstReverseIter += 3;
//    file << *itConstReverseIter;
//    file << " ]" << std::endl; TODO fix reverse iterators
}

void checkCapacity(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### SIZE, MAX_SIZE, CAPACITY ###" << std::endl;
	ft::vector<std::string> vectorSize(100, "vectorSizeTest");
	file << "$ 165. ft::vector<std::string> vectorSize(100, \"vectorSizeTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### POP_BACK ###" << std::endl;
	vectorSize.pop_back();
	file << "$ 170. vectorSize.pop_back();" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.push_back("newItem");
	vectorSize.push_back("newItem");
	vectorSize.push_back("newItem");
	file << "$ 174. vectorSize.push_back(\"newItem\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### RESIZE ###" << std::endl;
	vectorSize.resize(10, "newTest");
	file << "$ 181. vectorSize.resize(10, \"newTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.resize(45, "newTest");
	file << "$ 185. vectorSize.resize(45, \"newTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### RESERVE ###" << std::endl;
	vectorSize.reserve(1000);
	file << "$ 190. vectorSize.reserve(1000);" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.reserve(10);
	file << "$ 194. vectorSize.reserve(10);" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### EMPTY ###" << std::endl;
	bool empt = vectorSize.empty();
	file << "$ 199. bool empt = vectorSize.empty();" << std::endl;
	file << "[ vectorSize.empty() = " << empt << "]" << std::endl;
}

void checkAccessElements(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::vector<myInt> vectorMyInt;
	for (int i = 0; i < 15; i++) {
		vectorMyInt.push_back(myInt(i));
	}
	file << "### [] OPERATOR ###" << std::endl;
	file << "$ 212. vectorMyInt[10] = " << std::endl;
	file << "[ " << vectorMyInt[10] << " ]" << std::endl;
	const myInt constCopy = vectorMyInt[10];
	file << "$ 215. const myInt constCopy = vectorMyInt[10];" << std::endl;
	file << "[ " << constCopy << " ]" << std::endl;
	file << "### AT ###" << std::endl;
	file << "$ 216. vectorMyInt.at(10) = " << std::endl;
	file << "[ " << vectorMyInt.at(10)  << " ]" << std::endl;
	const myInt constAt = vectorMyInt.at(5);
	file << "$ 221. const myInt constCopy = vectorMyInt.at(5);" << std::endl;
	file << "[ " << constAt << " ]" << std::endl;

}

void testVector(bool containerType) {
    std::string fileName = containerType ? "ft_vector" : "std_vector";
    std::ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        checkConstructors(file, containerType);
        checkIterators(file, containerType);
        checkCapacity(file, containerType);
        checkAccessElements(file, containerType);
    }

//	vector.reserve(400);
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
//    for (int i = 0; i < 10; i++) {
//		vector.push_back("that");
//    }
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
//	std::cout << vector.max_size() << std::endl;
//    for (int i = 0; i < 100; i++) {
//		vector.push_back("that");
//    }
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
//	std::cout << vector.max_size() << std::endl;
//	std::cout << vector[10] << std::endl;
//	ft::vector<std::string>::iterator pointer = vector.begin() + 10;
//	vector.erase(pointer);
//	std::cout << vector.size() << std::endl;
//	assignTest();
}
