
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
        printColourText("----- VECTOR CONTAINER TEST -----", YELLOW, true);
        testVector(true);
        testVector(false);
        compare_files("ft_vector", "std_vector");
    };
    void _testMap() {
        printColourText("----- MAP CONTAINER TEST -----", YELLOW, true);
        testMap(true);
        testMap(false);
        compare_files("ft_map", "std_map");
    };
    void _testStack() {
        printColourText("----- STACK CONTAINER TEST -----", YELLOW, true);
        testStack(true);
        testStack(false);
        compare_files("ft_stack", "std_stack");
    };

    void _testSet() {
        printColourText("----- SET CONTAINER TEST -----", YELLOW, true);
        testSet(true);
        testSet(false);
        compare_files("ft_set", "std_set");
    };

    void _printFileError(std::string const &fileName) {
        printColourText("ERROR, FILE: ", RED, false);
        printColourText(fileName, RED, false);
        printColourText("FILE IS NOT CREATED!", RED, true);
    }

    std::ifstream _openFile(std::string const &fileName) {
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
        std::ifstream fileOne, fileTwo;
        try {
            fileOne = _openFile(ft_file);
            fileTwo = _openFile(std_file);
        }
        catch (std::exception &ex) {
            _printFileError(ex.what());
            printColourText("Fix problems in file and try to run tester again", MAGENTA, true);
            return;
        }
        std::string stringOne, stringTwo, str;
        str = "";
        while (!fileOne.eof() || !fileTwo.eof()) {
            if (!fileOne.eof()) {
                getline(fileOne, stringOne);
            } else {
                stringOne = "";
            }
            if (!fileTwo.eof()) {
                getline(fileTwo, stringTwo);
            } else {
                stringTwo = "";
            }
            if (stringOne[0] == '#') {
				printColourText(stringOne.substr(0, stringOne.find_last_of('\n')), YELLOW, false);
            } else if (stringOne[0] == '$') {
            	str += stringOne;
            }
            else if (stringOne[0] == '[') {
                if (stringOne == stringTwo) {
                    printColourText("----------------[OK]", GREEN, true);
                } else {
                    printColourText("----------------[KO]", RED, true);
					printColourText(str, RED, true);
                    if (!stringOne.empty())
                        printColourText(stringOne.substr(0, stringOne.find_last_of(']') + 1), RED, true);
                    if (!stringTwo.empty())
                        printColourText(stringTwo.substr(0, stringTwo.find_last_of(']') + 1), RED, true);
                }
                str = "";
            } else {
                str = "";
            }
        }
    };
};

#endif //TESTER_HPP
