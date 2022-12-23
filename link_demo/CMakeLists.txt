#放在根目录下
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#规定cmake的最低版本要求
cmake_minimum_required (VERSION 3.10)
#设置c++编译器
set(CMAKE_CXX_COMPILER "g++")
#项目的名称，可以和文件夹名称不同
project(LINK_DEMO)
#设置可执行文件的名称，make之后bin目录下出现my_swap.exe
add_executable(demo01 link_demo/demo01.cpp link_demo/girls.cpp link_demo/tools.cpp link_demo/girls.h link_demo/tools.h)
