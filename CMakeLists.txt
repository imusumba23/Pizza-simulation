cmake_minimum_required(VERSION 3.20)
project(Pizza_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Pizza_Project main.cpp Restaurant.hpp Order.hpp Time.hpp Driver.hpp)
