//
// Created by grufix on 11/02/2020.
//

#ifndef ALGORITHEMBRIDGE_ASTAR_H
#define ALGORITHEMBRIDGE_ASTAR_H


#include <vector>
#include "Path.h"
#include "Searcher.h"
#include "PriorityQueue.h"
#include "AStarComperator.h"

template<class T>
class AStar : public Searcher<T,AStarComperator<T>> {
public:
   // void setOpen(const AStarComperator<T>& comperator);
    AStar();
    std::vector<std::string> search(Searchable<T> *searchable) override ;
};


#endif //ALGORITHEMBRIDGE_ASTAR_H
