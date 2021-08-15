//
// Created by Yuliya Martsenko on 16.08.2021.
//

#include "MyInt.hpp"

std::ostream & operator<<(std::ostream & os, const myInt &myInt) {
	os << myInt.getI();
	return os;
}
