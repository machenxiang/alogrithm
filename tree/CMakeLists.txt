cmake_minimum_required(VERSION 2.8.3)
project(cpp_basic)
add_compile_options(-std=c++11)

add_executable(main
  main.cpp
)
add_executable(dynamic_tree
  dynamic_tree.cpp
)
add_executable(test
  test.cpp
)