//
// Created by grufix on 15/02/2020.
//

#include "AStarComperator.h"

template <class T>
bool AStarComperator<T>::operator()(State<T> *s1, State<T> *s2) {
    return (s1->getMoving() + s1->getHuristic()) < (s2->getMoving() + s2->getHuristic());
}