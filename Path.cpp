//
// Created by grufix on 31/01/2020.
//

#include "Path.h"
template<class T>
Path<T>::Path() {_length = 0; _evaluated = 0;}

template<class T>
void Path<T>::insertToPath(std::string step) {
    path.push_back(step);
    _length++;
}

template<class T>
std::list<std::string> Path<T>::getPath() {
    return path;
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