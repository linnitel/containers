
#ifndef MYINT_HPP
#define MYINT_HPP

#include "utils.hpp"

class myInt {
private:
	int _i;

public:
	explicit myInt(int const &i): _i(i) {};
	myInt(): _i(0) {};
	~myInt() {};

	int getI() const {
		return _i;
	}

	void setI(int i) {
		_i = i;
	}
};

std::ostream & operator<<(std::ostream & os, const myInt &myInt);
bool operator==(const myInt& lhs, const myInt& rhs);
bool operator!=(const myInt& lhs, const myInt& rhs);
bool operator<(const myInt& lhs, const myInt& rhs);
bool operator<=(const myInt& lhs, const myInt& rhs);
bool operator>(const myInt& lhs, const myInt& rhs);
bool operator>=(const myInt& lhs, const myInt& rhs);


#endif //MYINT_HPP
