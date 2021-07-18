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
        Map/Map.hpp
        Set/Set.hpp
        Stack/Stack.hpp
        Vector/Vector.hpp
        main.cpp Iterators/Iterator_library.hpp)
