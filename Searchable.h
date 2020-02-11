//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_SEARCHABLE_H
#define ALGORITHEMBRIDGE_SEARCHABLE_H

#include "State.h"
#include <list>

template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual std::list<State<T>*> getAllPosibleStates(State<T>* state) = 0;
};


#endif //ALGORITHEMBRIDGE_SEARCHABLE_H
