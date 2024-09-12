cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)
project(linked)

set(LINKED_SOURCES "linked/linked.cpp")
set(TESTS_SOURCES "tests/tests.cpp")

add_compile_options(-g)
add_executable("linked_tests" ${TESTS_SOURCES} ${LINKED_SOURCES})
target_include_directories("linked_tests" PUBLIC "linked")