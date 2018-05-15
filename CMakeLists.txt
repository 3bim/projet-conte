cmake_minimum_required(VERSION 3.1.3)
project(string
        VERSION 0.1
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) #Use C++14

add_executable(main main.cpp Bacterie.cpp BacterieA.cpp BacterieB.cpp Case.cpp Environnement.cpp)

