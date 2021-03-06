cmake_minimum_required(VERSION 3.17.5)
project(containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Iterators)
include_directories(Map)
include_directories(Set)
include_directories(Stack)
include_directories(Vector)

add_executable(containers
        Iterators/Iterator.hpp
        Iterators/iterator_traits.hpp
        Map/Map.hpp
        Map/MapTest.cpp
        Map/MapTest.hpp
        Stack/Stack.hpp
        Stack/StackTest.cpp
        Stack/StackTest.hpp
        Vector/Vector.hpp
        Vector/VectorIterators.hpp
        Vector/VectorTest.cpp
        Vector/VectorTest.hpp
        Set/Set.hpp
        Set/SetTest.cpp
        Set/SetTest.hpp
        main.cpp
        RedBlackTree/RedBlackTree.hpp
        RedBlackTree/Node.hpp
        utils/PrintColour.cpp
        utils/utils.hpp
        Tester/Tester.hpp utils/PrintColour.hpp utils/MyInt.cpp utils/MyInt.hpp RedBlackTree/TreeIterator.hpp)
