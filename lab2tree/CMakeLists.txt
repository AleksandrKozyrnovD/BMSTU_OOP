cmake_minimum_required(VERSION 3.28)
project(lab3tree)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab3tree main.cpp
        inc/BaseContainer.h
        inc/BaseException.h
        inc/BaseIterator.h
        inc/Concepts.h
        inc/ConstIterator.h
        inc/Exceptions.h
        inc/Iterator.h
        inc/Tree.h
        inc/TreeNode.h
        imp/ConstIterator.hpp
        imp/Iterator.hpp
        imp/Tree.hpp
        imp/TreeNode.hpp)
