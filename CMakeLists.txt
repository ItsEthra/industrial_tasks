cmake_minimum_required(VERSION 3.25)

project(industrial_tasks)

set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

add_executable(week2
	week2/main.cpp
	week2/triangle.cpp
	week2/circle.cpp
	week2/figure.cpp
)

add_executable(week3
	week3/main.cpp
	week3/equation.cpp
	week3/rational.cpp
)
