cmake_minimum_required(VERSION 3.27)
project(employee_management_system)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(employee_management_system
        include/admin_functions.h
        include/login.h
        include/user_functions.h
        src/admin_functions.cpp
        src/login.cpp
        src/main.cpp
        src/user_functions.cpp)
