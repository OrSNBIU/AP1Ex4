//
// Created by grufix on 31/01/2020.
//

#include "Path.h"
template<class T>
Path<T>::Path(State<T>* goal) {
    State<T>* state = goal;
    while(state->getCameFrom() != NULL) {
        path.push_front(state);
        state = state->getCameFrom();
    }
    _length = 0; _evaluated = 0;}

template<class T>
void Path<T>::insertToPath(State<T>* state) {
    path.push_back(state);
    _length++;
}

template<class T>
std::list<std::string> Path<T>::getPath() {
    std::list<std::string> moves;
    for(int i = 0;i < path.size();i++) {
        State<T>* curr = path.top();
        path.pop_front();
        moves.push_back(curr->getSide(path.top()));
    }
    return moves;
}

template<class T>
void Path<T>::setLength(int length) {
    _length = length;
}

template<class T>
int Path<T>::getLength() {return _length;}

template<class T>
void Path<T>::setEvaluated(int evaluated) {
    _evaluated = _evaluated;
}

template<class T>
int Path<T>::getEvaluated() {return _evaluated;}