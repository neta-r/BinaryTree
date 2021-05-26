cmake_minimum_required(VERSION 3.19)
project(binraytree)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo Demo.cpp BinaryTree.cpp BinaryTree.hpp)
add_executable(test Test.cpp BinaryTree.cpp BinaryTree.hpp doctest.h)