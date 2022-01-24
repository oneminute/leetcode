# CMakeList.txt : CMake project for leetcode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SimpleTest")

set(SRC
	SimpleTest.h
	BaseTest.h
	TestCase.h
	TestCase.cpp
	TestSuite.h
	TestSuite.cpp
	TestRunner.h
	TestRunner.cpp
)

add_library(SimpleTest ${SRC})


# TODO: Add tests and install targets if needed.