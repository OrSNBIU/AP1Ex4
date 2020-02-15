//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_PATH_H
#define ALGORITHEMBRIDGE_PATH_H

#include <list>
#include <iostream>
#include "State.h"

template<class T>
class Path {
std::list<State<T>*> path;
int _length, _evaluated;
public:
    Path(State<T>* state);
    void insertToPath(State<T>* state);
    std::list<std::string> getPath();
    void setLength(int _length);
    int getLength();
    void setEvaluated(int evaluated);
    int getEvaluated();
};


#endif //ALGORITHEMBRIDGE_PATH_H
