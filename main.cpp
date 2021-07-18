//#include "Vector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<std::string> vector(0, "this");
	std::cout << vector.capacity() << std::endl;
	std::cout << vector.size() << std::endl;
	vector.push_back("that");
	std::cout << vector.capacity() << std::endl;
	std::cout << vector.size() << std::endl;
//	vector.reserve(400);
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
	for (int i = 0; i < 10; i++) {
		vector.push_back("that");
	}
	std::cout << vector.capacity() << std::endl;
	std::cout << vector.size() << std::endl;
	for (int i = 0; i < 100; i++) {
		vector.push_back("that");
	}
	std::cout << vector.capacity() << std::endl;
	std::cout << vector.size() << std::endl;
	return 0;
}

// iterator_traits example
//#include <iostream>     // std::cout
//#include <iterator>     // std::iterator_traits
//#include <typeinfo>     // typeid
//
//int main() {
//    typedef std::iterator_traits<int*> traits;
//    if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
//        std::cout << "int* is a random-access iterator";
//    return 0;
//}