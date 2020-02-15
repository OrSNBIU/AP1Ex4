//
// Created by grufix on 15/02/2020.
//

#ifndef ALGORITHEMBRIDGE_BESTFIRSTSEARCHCOMPERATOR_H
#define ALGORITHEMBRIDGE_BESTFIRSTSEARCHCOMPERATOR_H

#include "State.h"

template<class T>
class BestFirstSearchComperator {
public:
    bool operator()(State<T>* s1,State<T>* s2) {
        return s1->getMoving() > s2->getMoving();
    }
};


#endif //ALGORITHEMBRIDGE_BESTFIRSTSEARCHCOMPERATOR_H
