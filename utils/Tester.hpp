
#ifndef TESTER_HPP
# define TESTER_HPP

#include "VectorTest.hpp"
#include "MapTest.hpp"
#include "Stack.hpp"
#include "Set.hpp"

#define CONTAINERS_NUM 4

class Tester {


public:
    Tester() {};
    ~Tester() {};
    void testContainer(std::string const &containerName) {
        std::string container[CONTAINERS_NUM] = {"Vector", "Map", "Stack", "Set"};
        int (Tester::*f[CONTAINERS_NUM])();
        f[0] = &Tester::_testVector;
        f[1] = &Tester::_testMap;
        f[2] = &Tester::_testStack;
        f[3] = &Tester::_testSet;
        for (int i = 0; i < CONTAINERS_NUM; i++) {
            if (containerName == container[i]) {
                (this->*f[i])();
                break;
            }
        }
    };
    void compare_files() {};

};

#endif //TESTER_HPP
