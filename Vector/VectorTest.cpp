
#include "VectorTest.hpp"

void checkVectorConstructors(std::ofstream &file, bool containerType) {
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

//    file << "### COPY CONSTRUCTOR ###" << std::endl;
    ft::vector<std::string> vectorCopy(vectorN);
//    file << "$ 39. ft::vector<std::string> vectorCopy = vectorIter;" << std::endl;
//    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
//    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;

    file << "### ASSIGNATION OPERATOR ###" << std::endl;
    vectorCopy = vectorIter;
    file << "$ 45. vectorCopy = vectorIter;" << std::endl;
    file << "[ vectorCopy.capacity() = " << vectorCopy.capacity() << ";";
    file << " vectorCopy.size() = " << vectorCopy.size() << "]" << std::endl;
}

void checkVectorIterators(std::ofstream &file, bool containerType) {
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
	if (it[3]) {
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

void checkVectorCapacity(std::ofstream &file, bool containerType) {
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
	file << "### PUSH_BACK ###" << std::endl;
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
	file << "[ vectorSize.empty() = " << empt << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
	file << "### CLEAR ###" << std::endl;
	vectorSize.clear();
	empt = vectorSize.empty();
	file << "$ 205. vectorSize.clear();" << std::endl;
	file << "[ vectorSize.empty() = " << empt << ";";
	file << " vectorSize.size() = " << vectorSize.size() << "]" << std::endl;
}

void checkVectorAccessElements(std::ofstream &file, bool containerType) {
	if (!containerType) {
		namespace ft = std;
	}
	ft::vector<myInt> vectorMyInt;
	for (int i = 0; i < 15; i++) {
		vectorMyInt.push_back(myInt(i));
	}
	file << "### [] OPERATOR ###" << std::endl;
	file << "$ 219. vectorMyInt[10] = " << std::endl;
	file << "[ " << vectorMyInt[10] << " ]" << std::endl;
	const myInt constCopy = vectorMyInt[10];
	file << "$ 222. const myInt constCopy = vectorMyInt[10];" << std::endl;
	file << "[ " << constCopy << " ]" << std::endl;
	file << "### AT ###" << std::endl;
	file << "$ 226. vectorMyInt.at(10) = " << std::endl;
	file << "[ " << vectorMyInt.at(10)  << " ]" << std::endl;
	const myInt constAt = vectorMyInt.at(5);
	file << "$ 228. const myInt constCopy = vectorMyInt.at(5);" << std::endl;
	file << "[ " << constAt << " ]" << std::endl;
	file << "$ 234. myInt outRange = vectorMyInt.at(30);" << std::endl;
	file << "[ ";
    try {
        myInt outRange = vectorMyInt.at(30);
    } catch (std::exception &ex) {
        file << ex.what() << std::endl;
    }
    file << " ]" << std::endl;
	file << "### FRONT ###" << std::endl;
	myInt front = vectorMyInt.front();
	file << "$ 240. myInt front = vectorMyInt.front();" << std::endl;
	file << "[ " << front << " ]" << std::endl;
	const myInt frontConst = vectorMyInt.front();
	file << "$ 243. const myInt front = vectorMyInt.front();" << std::endl;
	file << "[ " << frontConst << " ]" << std::endl;
	file << "### BACK ###" << std::endl;
	myInt back = vectorMyInt.back();
	file << "$ 247. myInt back = vectorMyInt.back();" << std::endl;
	file << "[ " << front << " ]" << std::endl;
	const myInt backConst = vectorMyInt.back();
	file << "$ 250. const myInt backConst = vectorMyInt.back();" << std::endl;
	file << "[ " << backConst << " ]" << std::endl;
}

void checkVectorModifiers(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
    file << "### ASSIGN VIA ITERATORS ###" << std::endl;
    ft::vector<std::string> vectorOne(3, "this");
    ft::vector<std::string> vectorTwo(10, "some");
    ft::vector<std::string> vectorThree(5, "what");
    std::vector<std::string> vectorFour(2, "piupiu");
    vectorThree.assign(vectorOne.begin(), vectorOne.end());
    file << "$ 256. vectorThree.assign(vectorOne.begin(), vectorOne.end());" << std::endl;
    file << "[ vectorThree.capacity() = " << vectorThree.capacity() << ";";
    file << " vectorThree.size() = " << vectorThree.size() << "]; ";
    file << " vector = [ ";
    for (int i = 0; i < vectorThree.size(); i++) {
        file << vectorThree[i];
        if (i != vectorThree.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
    file << "### ASSIGN VIA FILL ###" << std::endl;
    vectorTwo.assign(7, "truth");
    file << "$ 271. vectorTwo.assign(7, \"truth\");" << std::endl;
    file << "[ vectorTwo.capacity() = " << vectorTwo.capacity() << ";";
    file << " vectorTwo.size() = " << vectorTwo.size() << "]; ";
    file << " vector = [ ";
    for (int i = 0; i < vectorTwo.size(); i++) {
        file << vectorTwo[i];
        if (i != vectorTwo.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
    file << "### INSERT SINGLE ELEMENT ###" << std::endl;
    vectorOne.insert(vectorOne.begin() + 1, "foooooo");
    file << "$ 286. vectorOne.insert(vectorOne.begin() + 1, \"foooooo\");" << std::endl;
    file << "[ vectorOne.capacity() = " << vectorOne.capacity() << ";";
    file << " vectorOne.size() = " << vectorOne.size() << ";";
    file << " vector = [ ";
    for (int i = 0; i < vectorOne.size(); i++) {
        file << vectorOne[i];
        if (i != vectorOne.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
    file << "### INSERT SEVERAL ELEMENTS ###" << std::endl;
    vectorOne.insert(vectorOne.begin() + 3, 5, "fooooooTwppp");
    file << "$ 292. vectorOne.insert(vectorOne.begin() + 3, 5, \"fooooooTwppp\");" << std::endl;
    file << "[ vectorOne.capacity() = " << vectorOne.capacity() << ";";
    file << " vectorOne.size() = " << vectorOne.size() << ";";
    file << " vector = [ ";
    for (int i = 0; i < vectorOne.size(); i++) {
        file << vectorOne[i];
        if (i != vectorOne.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
//    file << "### INSERT ITERATOR RANGE ###" << std::endl;
//    vectorOne.insert(vectorOne.begin(), vectorFour.begin(), vectorFour.end()); // TODO insert with iterators???
    file << "### ERASE SINGLE ELEMENT ###" << std::endl;
    vectorOne.erase(vectorOne.begin() + 3);
    file << "$ 301. vectorOne.erase(vectorOne.begin() + 3);" << std::endl;
    file << "[ vectorOne.capacity() = " << vectorOne.capacity() << ";";
    file << " vectorOne.size() = " << vectorOne.size() << ";";
    file << " vector = [ ";
    for (int i = 0; i < vectorOne.size(); i++) {
        file << vectorOne[i];
        if (i != vectorOne.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
    file << "### ERASE SEVERAL ELEMENTS VIA ITERATOR ###" << std::endl;
    vectorOne.erase(vectorOne.begin() + 3, vectorOne.begin() + 5);
    file << "$ 307. vectorOne.erase(vectorOne.begin() + 3, vectorOne.begin() + 5);" << std::endl;
    file << "[ vectorOne.capacity() = " << vectorOne.capacity() << ";";
    file << " vectorOne.size() = " << vectorOne.size() << ";";
    file << " vector = [ ";
    for (int i = 0; i < vectorOne.size(); i++) {
        file << vectorOne[i];
        if (i != vectorOne.size() - 1) {
            file << ", ";
        } else {
            file << "]";
        }
    }
    file << " ]" << std::endl;
}

void checkVectorComparison(std::ofstream &file, bool containerType) {
    if (!containerType) {
        namespace ft = std;
    }
	ft::vector<std::string> vectorOne(3, "this");
	ft::vector<std::string> vectorThree(5, "what");
	ft::vector<std::string> vectorFive(5, "what");
    file << "### OPERATOR == ###" << std::endl;
    bool equal = (vectorOne == vectorThree);
	file << "$ 357. bool equal = (vectorOne == vectorThree);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
	equal = (vectorOne == vectorFive);
	file << "$ 357. bool equal = (vectorOne == vectorFive);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
    file << "### OPERATOR != ###" << std::endl;
    equal = (vectorOne != vectorThree);
	file << "$ 361. equal = (vectorOne != vectorThree);" << std::endl;
	file << "[ " << equal << "]" <<std::endl;
	ft::vector<int> vectorTwo(5, 10);
	ft::vector<int> vectorFour(5, 9);
	ft::vector<int> vectorSix = ft::vector<int>();
    file << "### OPERATOR > ###" << std::endl;
    bool compare = vectorTwo > vectorFour;
	file << "$ 367. bool compare = vectorTwo > vectorFour;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
    file << "### OPERATOR < ###" << std::endl;
	compare = vectorTwo < vectorFour;
	file << "$ 367. bool compare = vectorTwo > vectorFour;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
    file << "### OPERATOR >= ###" << std::endl;
	compare = vectorTwo >= vectorSix;
	file << "$ 380. compare = vectorTwo >= vectorSix;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
    file << "### OPERATOR <= ###" << std::endl;
	compare = vectorOne <= vectorThree;
	file << "$ 384. compare = vectorOne <= vectorThree;" << std::endl;
	file << "[ " << compare << "]" <<std::endl;
}

void testVector(bool containerType) {
    std::string fileName = containerType ? "ft_vector" : "std_vector";
    std::ofstream file;
    file.open(fileName);
    if (file.is_open()) {
        checkVectorConstructors(file, containerType);
        checkVectorIterators(file, containerType);
        checkVectorCapacity(file, containerType);
        checkVectorAccessElements(file, containerType);
        checkVectorModifiers(file, containerType);
        checkVectorComparison(file, containerType);
    }
}

