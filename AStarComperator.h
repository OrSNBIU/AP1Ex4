//
// Created by grufix on 15/02/2020.
//

#ifndef ALGORITHEMBRIDGE_ASTARCOMPERATOR_H
#define ALGORITHEMBRIDGE_ASTARCOMPERATOR_H
#include"State.h"

template <class T>
class AStarComperator {
public:
    bool operator()(State<T>* s1,State<T>* s2) {
        return (s1->getMoving() + s1->getHuristic()) > (s2->getMoving() + s2->getHuristic());
    }
};


#endif //ALGORITHEMBRIDGE_ASTARCOMPERATOR_H
