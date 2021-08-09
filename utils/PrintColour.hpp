//
// Created by Tothmure Isabel on 8/9/21.
//

#ifndef CONTAINERS_PRINTCOLOUR_HPP
#define CONTAINERS_PRINTCOLOUR_HPP

#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"
# define RESET  "\x1B[0m"

#include "iostream"

void printColourText(std::string text, std::string color, int newline);

#endif //CONTAINERS_PRINTCOLOUR_HPP
