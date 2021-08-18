//
// Created by Yuliya Martsenko on 16.08.2021.
//

#include "MyInt.hpp"

std::ostream & operator<<(std::ostream & os, const myInt &myInt) {
	os << myInt.getI();
	return os;
}

bool operator==(const myInt& lhs, const myInt& rhs) {
    return (lhs.getI() == rhs.getI());
}

bool operator!=(const myInt& lhs, const myInt& rhs) {
    return !(lhs == rhs);
}

bool operator<(const myInt& lhs, const myInt& rhs) {
    return (lhs.getI() < rhs.getI());
}

bool operator<=(const myInt& lhs, const myInt& rhs) {
    return !(rhs < lhs);
}

bool operator>(const myInt& lhs, const myInt& rhs) {
    return rhs < lhs;
}

bool operator>=(const myInt& lhs, const myInt& rhs) {
    return !(lhs < rhs);
}
