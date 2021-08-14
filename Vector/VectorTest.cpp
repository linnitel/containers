
#include "VectorTest.hpp"

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

void testVector(bool containerType) {

#if containerType == 0
    namespace ft = std;
#endif

    ft::vector<std::string> vector(10, "this");
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
	std::cout << vector[10] << std::endl;
	ft::vector<std::string>::iterator pointer = vector.begin() + 10;
	vector.erase(pointer);
	std::cout << vector.size() << std::endl;
//	assignTest();
}
