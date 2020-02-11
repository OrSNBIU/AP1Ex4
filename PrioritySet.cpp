//
// Created by grufix on 28/01/2020.
//
//Intended for use in Searchable.
#include "PrioritySet.h"
template<class T>
void compare_nocase(T a1, T a2) {
    return (a1.compare(a2) >= 0);
}

template <class T>
PrioritySet<T>::PrioritySet(T first) {
    if(set.empty()) {
        set.push_back(first);
    }
}

template <class T>
T PrioritySet<T>::getTop() {
    T top = set.front();
    set.pop_front();
    return top;
}

template <class T>
void PrioritySet<T>::insert(T a) {
    set.push_back(a);
    set.sort();
}
