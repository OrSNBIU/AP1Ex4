cmake_minimum_required(VERSION 3.15)
project(AlgorithemBridge)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgorithemBridge main.cpp ISearcher.cpp ISearcher.h Searchable.cpp Searchable.h State.cpp State.h Searcher.cpp Searcher.h BestFirstSearch.cpp BestFirstSearch.h Path.cpp Path.h Matrix.cpp Matrix.h BreadthFirstSearch.cpp BreadthFirstSearch.h DepthFirstSearch.cpp DepthFirstSearch.h AStar.cpp AStar.h PointState.cpp PointState.h PriorityQueue.cpp PriorityQueue.h AStarComperator.cpp AStarComperator.h BestFirstSearchComperator.cpp BestFirstSearchComperator.h AlgorithemsTesting.cpp AlgorithemsTesting.h)