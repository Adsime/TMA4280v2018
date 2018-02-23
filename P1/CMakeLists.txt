cmake_minimum_required(VERSION 3.9)
project(P1)

set(CMAKE_CXX_STANDARD 11)

add_executable(P1 zeta0/zeta0.cpp zeta0/zeta0.h mach0/mach0.cpp mach0/mach0.h zeta0/zeta0utest.cpp zeta0/zeta0utest.h zeta0/tests.cpp)