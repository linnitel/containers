
#include "VectorTest.hpp"
#include <fstream>
#include <unistd.h>

//#define TESTED_NAMESPACE ft
//#define TESTED_TYPE int
//
//
//template <typename T>
//void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = 1)
//{
//	std::cout << "size: " << vct.size() << std::endl;
//	std::cout << "capacity: " << vct.capacity() << std::endl;
//	std::cout << "max_size: " << vct.max_size() << std::endl;
//	if (print_content)
//	{
//		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
//		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
//		std::cout << std::endl << "Content is:" << std::endl;
//		for (; it != ite; ++it)
//			std::cout << "- " << *it << std::endl;
//	}
//	std::cout << "###############################################" << std::endl;
//}
//
//int		assignTest() {
//	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
//	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
//	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
//	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;
//
//	for (unsigned long int i = 0; i < vct.size(); ++i)
//		vct[i] = (vct.size() - i) * 3;
//	for (unsigned long int i = 0; i < vct_two.size(); ++i)
//		vct_two[i] = (vct_two.size() - i) * 5;
//	printSize(vct);
//	printSize(vct_two);
//
//	vct_three.assign(vct.begin(), vct.end());
//	vct.assign(vct_two.begin(), vct_two.end());
//	vct_two.assign(2, 42);
//	vct_four.assign(4, 21);
//
//	std::cout << "\t### After assign(): ###" << std::endl;
//
//	printSize(vct);
//	printSize(vct_two);
//	printSize(vct_three);
//	printSize(vct_four);
//
//	vct_four.assign(6, 84);
//	printSize(vct_four);
//
//	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;
//
//	vct.assign(5, 53);
//	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);
//
//	printSize(vct);
//	printSize(vct_two);
//
//	return (0);
//}

class myInt {
private:
	int _i;

public:
	myInt(int i): _i(i) {};
	myInt(): _i(0) {};
	~myInt();

	int getI() const {
		return _i;
	}

	void setI(int i) {
		_i = i;
	}
};

std::ostream & operator<<(std::ostream & os, const myInt &myInt) {
	os << myInt.getI();
	return os;
}

void checkConstructors(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### DEFAULT CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorDef = ft::vector<std::string>();
    file << "$ 71. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
    file << "[ vectorDef.capacity() = " << vectorDef.capacity() << ";";
    file << " vectorDef.size() = " << vectorDef.size() << "]" << std::endl;

    file << "### CONSTRUCTOR WITH N ###" << std::endl;
    ft::vector<std::string> vectorN(3, "this");
    file << "$ 77. ft::vectorN<std::string> vectorN(10, \"this\");" << std::endl;
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
    file << "$ 93. ft::vector<std::string> vectorIter(vector.begin(), vector.end());" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << "]" << std::endl;

    file << "### COPY CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorCopy = vectorIter;
    file << "$ 99. ft::vector<std::string> vectorCopy = vectorIter;" << std::endl;
    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;

    file << "### ASSIGNATION OPERATOR ###" << std::endl;
    vectorCopy = vectorIter;
    file << "$ 105. vectorCopy = vectorIter;" << std::endl;
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
    file << "$ 117. ft::vector<float> vectorIter(vectorN.begin(), vectorN.end());" << std::endl;
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
    file << "$ 151. vectorInt.push_back(i);" << std::endl;
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
    file << "$ 168. ft::vector<int>::iterator it = vectorInt.begin();" << std::endl;
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
	file << "$ 196. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;
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
//	file << "$ 196. ft::vector<int>::iterator itTwo = vectorInt.begin();" << std::endl;

//    file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
//    ft::vector<int>::reverse_iterator itConstReverseIter = vectorInt.rbegin();
//    file << "$ 184. ft::vector<float>::const_reverse_iterator itConstReverseIter = vectorN.rbegin();" << std::endl;
//    file << "[ ";
//    itConstReverseIter += 3;
//    file << *itConstReverseIter;
//    file << " ]" << std::endl; TODO fix reverse iterators
}

void checkCapacity(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	file << "### SIZE, MAX_SIZE, CAPACITY" << std::endl;
	ft::vector<std::string> vectorSize(100, "vectorSizeTest");
	file << "$ 226. ft::vector<std::string> vectorSize(100, \"vectorSizeTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.pop_back();
	file << "$ 230. vectorSize.pop_back();" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.push_back("newItem");
	vectorSize.push_back("newItem");
	vectorSize.push_back("newItem");
	file << "$ 234. vectorSize.push_back(\"newItem\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### RESIZE ###" << std::endl;
	vectorSize.resize(10, "newTest");
	file << "$ 240. vectorSize.resize(10, \"newTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.resize(45, "newTest");
	file << "$ 245. vectorSize.resize(45, \"newTest\");" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### RESERVE ###" << std::endl;
	vectorSize.reserve(1000);
	file << "$ 250. vectorSize.reserve(1000);" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	vectorSize.reserve(10);
	file << "$ 254. vectorSize.reserve(10);" << std::endl;
	file << "[ vectorSize.capacity() = " << vectorSize.capacity() << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### EMPTY ###" << std::endl;
	bool empt = vectorSize.empty();
	file << "$ 259. bool empt = vectorSize.empty();" << std::endl;
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
	file << "$ 297. vectorMyInt[10] = " << std::endl;
	file << "[ " << vectorMyInt[10] << " ]" << std::endl;
	file << "### AT ###" << std::endl;
	file << "$ 300. vectorMyInt.at(10) = " << std::endl;
	file << "[ " << vectorMyInt.at(10)  << " ]" << std::endl;
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
