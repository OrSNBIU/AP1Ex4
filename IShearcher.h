//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_ISHEARCHER_H
#define ALGORITHEMBRIDGE_ISHEARCHER_H

#include "Searchable.h"

template <class T,class Solution>
class IShearcher {
public:
    virtual Solution search(Searchable<T> searchable) = 0;
    virtual int numOfNodesEvaluated() = 0;
};


#endif //ALGORITHEMBRIDGE_ISHEARCHER_H
