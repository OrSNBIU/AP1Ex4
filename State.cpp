//
// Created by grufix on 31/01/2020.
//

#include "State.h"

template <class T>
State<T>::State(T* state) {
    _state = state;
}

template <class T>
bool State<T>::Equal(State<T> state) {
    return _state == state;
}

template <class T>
void State<T>::setWhereFrom(State<T> state) {
    _cameFrom = state;
    _moving += state.getMoving();
}

template <class T>
double State<T>::getMoving() {
    return _moving;
}

template <class T>
State<T>* State<T>::getCameFrom() {
    return _cameFrom;
}

template <class T>
double State<T>::getCost() {
    return _cost;
}

template <class T>
void State<T>::setCost(double cost) {
    _cost = cost;
    _moving = cost;
}

template <class T>
T* State<T>::getState() {
    return _state;
}

template <class T>
bool State<T>::operator==(State<T>* state) {
    return (_state == state->getState());
}

template <class T>
void State<T>::updateMoving(double moving) {
    _moving = _cost + moving;
}