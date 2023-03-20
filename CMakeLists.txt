cmake_minimum_required(VERSION 3.24)
project(BTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(BTree b_tree.cpp b_tree.h b_tree_node.cpp b_tree_node.h main.cpp)
