cmake_minimum_required(VERSION 3.31)
project(lab4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab4
        CoadaCuPrioritati.cpp
        CoadaCuPrioritati.h
        IteratorCP.cpp
        IteratorCP.h
        TestScurt.cpp
        TestExtins.cpp
        main.cpp  # Fișierul care conține funcția main() a profei
)