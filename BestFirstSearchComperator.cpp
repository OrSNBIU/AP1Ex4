//
// Created by grufix on 15/02/2020.
//

#include "BestFirstSearchComperator.h"

template <class T>
bool BestFirstSearchComperator<T>::operator()(State<T> *s1, State<T> *s2) {
    return s1->getMoving() < s2->getMoving();
}