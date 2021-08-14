
#ifndef TESTER_HPP
# define TESTER_HPP

#define CONTAINERS_NUM 4
#include "VectorTest.hpp"
#include "Map/MapTest.hpp"
#include "Set/SetTest.hpp"
#include "Stack/StackTest.hpp"

class Tester {
private:
    void _testVector() {
        printColourText("----- THIS IS VECTOR CONTAINER TEST -----", YELLOW, true);
        testVector(true);
        testVector(false);
        compare_files("ft_vector", "std_vector");
    };
    void _testMap() {
        testMap(true);
        testMap(false);
        compare_files("ft_vector", "std_vector");
    };
    void _testStack() {
        printColourText("----- THIS IS STACK CONTAINER TEST -----", YELLOW, true);
        testStack(true);
        testStack(false);
        compare_files("ft_vector", "std_vector");

    };

    void _testSet() {
        printColourText("----- THIS IS SET CONTAINER TEST -----", YELLOW, true);
        testSet(true);
        testSet(false);
        compare_files("ft_vector", "std_vector");
    };

public:
    Tester() {};
    ~Tester() {};
    void testContainer(std::string const &containerName) {
        std::string container[CONTAINERS_NUM] = {"Vector", "Map", "Stack", "Set"};
        void (Tester::*f[CONTAINERS_NUM])();
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

    void compare_files(std::string ft_file, std::string std_file) {

    };

};

#endif //TESTER_HPP
