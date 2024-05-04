cmake_minimum_required(VERSION 3.27)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp
        Headers/Base/Container.h
        Headers/Base/ContainerException.h
        Headers/Class/List.h
        Headers/Class/ListException.h
        Headers/Base/BaseIterator.h
        Headers/Class/ListIterator.h
        Headers/Class/ConstListIterator.h
        Headers/ClassTree/Tree.h
        Headers/Class/Implementation/ListConstructors.hpp
        Headers/Class/Implementation/ListMethods.hpp
        Headers/Class/Implementation/ListOperators.hpp
        Headers/Class/Implementation/Node.hpp
        Headers/Class/IteratorImplementation/ListIterator.hpp
        Headers/Class/IteratorImplementation/ConstListIterator.hpp
        Headers/Base/Container.hpp
        Headers/Class/MyConcepts.h
        Headers/Class/IteratorException.h
        Headers/Base/BaseIterator.hpp
)
