cmake_minimum_required(VERSION 3.15)
project(google_hash_code)

set(CMAKE_CXX_STANDARD 14)

add_executable(google_hash_code main.cpp Parser.cpp Parser.h Database.cpp Database.h GeneticAlgorithm.cpp GeneticAlgorithm.h Library.cpp Library.h Book.cpp Book.h)