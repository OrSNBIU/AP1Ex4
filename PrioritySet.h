//
// Created by grufix on 28/01/2020.
//
//Header file for PrioritySet class.
#ifndef MILD2_PRIORITYSET_H
#define MILD2_PRIORITYSET_H


#include <list>

template<class T>
class PrioritySet {
std::list<T> set;

public:
    PrioritySet(T first);
    void insert(T a);
    T getTop();
};


#endif //MILD2_PRIORITYSET_H
