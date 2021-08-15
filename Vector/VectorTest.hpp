
#ifndef VECTORTEST_HPP
# define VECTORTEST_HPP

#include <vector>
#include <iterator>
#include <algorithm>
#include "Vector.hpp"
#include "utils/utils.hpp"


void testVector(bool containerType);

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

#endif //VECTORTEST_HPP
