
#include "VectorTest.hpp"

void testVector() {
	std::cout << "----- THIS IS VECTOR CONTAINER TEST -----" << std::endl;
    std::vector<std::string> vector(10, "this");
    std::cout << vector.capacity() << std::endl;
    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
//	vector.reserve(400);
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
    for (int i = 0; i < 10; i++) {
        vector.push_back("that");
    }
    std::cout << vector.capacity() << std::endl;
    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
    for (int i = 0; i < 100; i++) {
        vector.push_back("that");
    }
    std::cout << vector.capacity() << std::endl;
    std::cout << vector.size() << std::endl;
    std::cout << vector.max_size() << std::endl;
}
