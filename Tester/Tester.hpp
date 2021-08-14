
#ifndef TESTER_HPP
# define TESTER_HPP

#define CONTAINERS_NUM 4
#include <fstream>
#include <exception>
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
        compare_files("ft_map", "std_map");
    };
    void _testStack() {
        printColourText("----- THIS IS STACK CONTAINER TEST -----", YELLOW, true);
        testStack(true);
        testStack(false);
        compare_files("ft_stack", "std_stack");

    };

    void _testSet() {
        printColourText("----- THIS IS SET CONTAINER TEST -----", YELLOW, true);
        testSet(true);
        testSet(false);
        compare_files("ft_set", "std_set");
    };

    void _printFileError(std::string fileName) {
        printColourText("ERROR, FILE: ", RED, false);
        printColourText(fileName, RED, false);
        printColourText("FILE IS NOT CREATED!", RED, true);
    }

    std::ifstream _openFile(std::string fileName) {
        std::ifstream file;
        file.open(fileName);
        if (!file) {
            throw std::runtime_error(fileName);
        }
        return file;
    }

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

    void compare_files(std::string const &ft_file, std::string const &std_file) {
        try {
            std::ifstream fileOne = _openFile(ft_file);
            std::ifstream fileTwo = _openFile(std_file);
        }
        catch (std::exception &ex) {
            _printFileError(ex.what());
            printColourText("Fix problems in file and try to run tester again", MAGENTA, true);
            return;
        }
        int readOne = -1;
        int readTwo = -1;
        while (readOne != 0 && readTwo != 0)
    };
};

#endif //TESTER_HPP
