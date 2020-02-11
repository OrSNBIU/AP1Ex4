cmake_minimum_required(VERSION 3.15)
project(AlgorithemBridge)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgorithemBridge main.cpp IShearcher.cpp IShearcher.h Searchable.cpp Searchable.h State.cpp State.h Searcher.cpp Searcher.h BestFirstSearch.cpp BestFirstSearch.h Path.cpp Path.h Point.cpp Point.h Matrix.cpp Matrix.h)