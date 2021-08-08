//
// Created by Tothmure Isabel on 7/28/21.
//

#include "MapTest.hpp"

void testMap() {
	printColourText("----- THIS IS MAP CONTAINER TEST -----", YELLOW, true);
	ft::Map<int, std::string> ft_map;
	std::map<int, std::string> std_map;
	ft_map[1] = "one";
	ft_map[2] = "two";
	ft_map[3] = "three";
	ft_map[5] = "five";
	ft_map[10] = "ten";
	ft_map[0] = "zero";
	std::cout << "MY MAP" << std::endl;
	std::cout << ft_map[1] << std::endl;
	std::cout << ft_map[2] << std::endl;
	std::cout << ft_map[3] << std::endl;
	std::cout << ft_map[5] << std::endl;
	std::cout << ft_map[10] << std::endl;
	std::cout << ft_map[0] << std::endl;
	std_map[1] = "one";
	std_map[2] = "two";
	std_map[3] = "three";
	std_map[5] = "five";
	std_map[10] = "ten";
	std_map[0] = "zero";
	std::cout << "STD MAP" << std::endl;
	std::cout << std_map[1] << std::endl;
	std::cout << std_map[2] << std::endl;
	std::cout << std_map[3] << std::endl;
	std::cout << std_map[5] << std::endl;
	std::cout << std_map[10] << std::endl;
	std::cout << std_map[0] << std::endl;
//	std::cout << ft_map.find(3)->_data.first << "   " << ft_map.find(3)->_data.second << std::endl;
}
