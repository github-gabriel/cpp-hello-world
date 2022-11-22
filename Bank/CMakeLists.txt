cmake_minimum_required(VERSION 3.22)
project(Bank)

set(CMAKE_CXX_STANDARD 14)

add_executable(Bank main.cpp Bank.cpp Bank.hpp Kunde.cpp Kunde.hpp)
