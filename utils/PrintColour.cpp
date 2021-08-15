//
// Created by Yuliya Martsenko on 28.07.2021.
//

#include "PrintColour.hpp"

void printColourText(std::string text, std::string color, int newline) {
	std::cout << color << text << RESET;
	if (newline) {
		std::cout << std::endl;
	}
}