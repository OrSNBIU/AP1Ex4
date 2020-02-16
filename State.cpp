//
// Created by grufix on 31/01/2020.
//

#include "State.h"


template <class T>
State<T>::State(T state, double cost) {
    _state = state;
    _cost = cost;
    _moving = cost;
    _huristicCost = 0;
    _cameFrom= 0;
}

template <class T>
double State<T>::getMoving() {
    return _moving;
}

template <class T>
State<T> * State<T>::getCameFrom()  { return _cameFrom;}

template <class T>
T State<T>::getState() { return _state;};


template <class T>
double State<T>::getHuristic()  {
    return _huristicCost;
}



template <class T>
void State<T>::setHuristic(double cost)  {
    _huristicCost = cost;
}


template <class T>
double State<T>::getCost()  {
    return _cost;
}


template <class T>
void State<T>::setCost(double cost) {
    _cost = cost;
    _moving = cost;
}

template <class T>
void State<T>::updateMoving(double moving)  {
    _moving = _cost + moving;
}



template <class T>
void State<T>::setWhereFrom(State<T> *state)  { _cameFrom = state;}

template <class T>
State<T>::~State() { delete(_cameFrom);}