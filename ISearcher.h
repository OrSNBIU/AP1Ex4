//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_ISEARCHER_H
#define ALGORITHEMBRIDGE_ISEARCHER_H

#include "Searchable.h"

template <class T,class Solution>
class ISearcher {
public:
    virtual Solution search(Searchable<T> *searchable) = 0;
    virtual int numOfNodesEvaluated() = 0;
};


#endif //ALGORITHEMBRIDGE_ISEARCHER_H
