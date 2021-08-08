
#include "VectorTest.hpp"

void testVector() {
	printColourText("----- THIS IS VECTOR CONTAINER TEST -----", YELLOW, true);
    std::vector<std::string> std_vector(10, "this");
	ft::vector<std::string> ft_vector(10, "this");
    std::cout << ft_vector.capacity() << std::endl;
    std::cout << ft_vector.size() << std::endl;
    std::cout << ft_vector.max_size() << std::endl;
	std::cout << std_vector.capacity() << std::endl;
	std::cout << std_vector.size() << std::endl;
	std::cout << std_vector.max_size() << std::endl;
//	vector.reserve(400);
//	std::cout << vector.capacity() << std::endl;
//	std::cout << vector.size() << std::endl;
    for (int i = 0; i < 10; i++) {
        ft_vector.push_back("that");
		std_vector.push_back("that");
    }
	std::cout << ft_vector.capacity() << std::endl;
	std::cout << ft_vector.size() << std::endl;
	std::cout << ft_vector.max_size() << std::endl;
	std::cout << std_vector.capacity() << std::endl;
	std::cout << std_vector.size() << std::endl;
	std::cout << std_vector.max_size() << std::endl;
    for (int i = 0; i < 100; i++) {
		ft_vector.push_back("that");
		std_vector.push_back("that");
    }
	std::cout << ft_vector.capacity() << std::endl;
	std::cout << ft_vector.size() << std::endl;
	std::cout << ft_vector.max_size() << std::endl;
	std::cout << std_vector.capacity() << std::endl;
	std::cout << std_vector.size() << std::endl;
	std::cout << std_vector.max_size() << std::endl;
	std::cout << ft_vector[10] << std::endl;
	std::cout << std_vector[10] << std::endl;
	ft::vector<std::string>::iterator pointer = ft_vector.begin() + 10;
	ft_vector.erase(pointer);
	std::cout << ft_vector.size() << std::endl;
	std::cout << std_vector.size() << std::endl;
}
