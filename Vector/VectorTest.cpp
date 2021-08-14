
#include "VectorTest.hpp"
#include <fstream>
#include <unistd.h>

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int


template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = 1)
{
	std::cout << "size: " << vct.size() << std::endl;
	std::cout << "capacity: " << vct.capacity() << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		assignTest() {
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(7);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_two(4);
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_three;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	printSize(vct);
	printSize(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(vct);
	printSize(vct_two);
	printSize(vct_three);
	printSize(vct_four);

	vct_four.assign(6, 84);
	printSize(vct_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	printSize(vct);
	printSize(vct_two);

	return (0);
}

void checkConstructors(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### DEFAULT CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorDef = ft::vector<std::string>();
    file << "# 71. ft::vector<std::string> vectorDef = ft::vector<std::string>();" << std::endl;
    file << "[ vectorDef.capacity() = " << vectorDef.capacity() << ";";
    file << " vectorDef.size() = " << vectorDef.size() << "]" << std::endl;

    file << "### CONSTRUCTOR WITH N ###" << std::endl;
    ft::vector<std::string> vectorN(3, "this");
    file << "# 77. ft::vectorN<std::string> vectorN(10, \"this\");" << std::endl;
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
    file << "# 93. ft::vector<std::string> vectorIter(vector.begin(), vector.end());" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << "]" << std::endl;

    file << "### COPY CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorCopy = vectorIter;
    file << "# 99. ft::vector<std::string> vectorCopy = vectorIter;" << std::endl;
    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;

    file << "### ASSIGNATION OPERATOR ###" << std::endl;
    vectorCopy = vectorIter;
    file << "# 105. vectorCopy = vectorIter;" << std::endl;
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
    file << "# 117. ft::vector<float> vectorIter(vectorN.begin(), vectorN.end());" << std::endl;
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

    file << "### ITERATORS RBEGIN - REND ###" << std::endl;
    ft::vector<float> vectorReverseIter(vectorN.rbegin(), vectorN.rend());
    file << "# 133. ft::vector<float> vectorIter(vectorN.rbegin(), vectorN.rend());" << std::endl;
    file << "[ vectorIter.capacity() = " << vectorIter.capacity() << ";";
    file << " vectorIter.size() = " << vectorIter.size() << ";";
    file << "[";
    for (ft::vector<float>::reverse_iterator it = vectorReverseIter.rbegin(); it != vectorReverseIter.rend(); it++) {
        file << *it;
        if (*it != vectorN[0]) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;

    file << "### PUSH_BACK ###" << std::endl;
    ft::vector<int> vectorInt;
    for (int i = 0; i < 6; i++) {
        vectorInt.push_back(i);
    }
    file << "# 151. vectorInt.push_back(i);" << std::endl;
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
    file << "# 168. ft::vector<int>::iterator it = vectorInt.begin();" << std::endl;
    file << "[ ";
    it += 4;
    file << *it << ", ";
    it--;
    file << *it << ", ";
    --it;
    file << *it << ", ";
    file << it[5] << ", ";
    ++it;
    file << *it << ", ";
    file << " ]" << std::endl;

    file << "### REVERSE ITERATOR OPERATORS ###" << std::endl;
    ft::vector<int>::reverse_iterator itConstReverseIter = vectorInt.rbegin();
    file << "# 184. ft::vector<float>::const_reverse_iterator itConstReverseIter = vectorN.rbegin();" << std::endl;
    file << "[ ";
    itConstReverseIter += 3;
    file << *itConstReverseIter;
    file << " ]" << std::endl;
}

void testVector(bool containerType) {
    std::string fileName = containerType ? "ft_vector" : "std_vector";
    std::ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        checkConstructors(file, containerType);
        checkIterators(file, containerType);
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
