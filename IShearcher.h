//
// Created by grufix on 31/01/2020.
//
//Header file of IShearcher

#ifndef ALGORITHEMBRIDGE_ISHEARCHER_H
#define ALGORITHEMBRIDGE_ISHEARCHER_H

#include "Searchable.h"

template <class T,class Solution>
class IShearcher {
public:
    virtual Solution search(Searchable<T> searchable) = 0; //Searching for a solution
    virtual int numOfNodesEvaluated() = 0; //Holds a counter of how many nodes we've evaluated.
};


#endif //ALGORITHEMBRIDGE_ISHEARCHER_H
