//
// Created by grufix on 15/02/2020.
//

#ifndef ALGORITHEMBRIDGE_PRIORITYQUEUE_H
#define ALGORITHEMBRIDGE_PRIORITYQUEUE_H

#include "State.h"
#include <queue>
#include <unordered_map>

template <class T,class Comperator>
class PriorityQueue {
std::priority_queue<State<T>*, std::vector<State<T>*>,Comperator> _queue;
std::unordered_map<std::string,State<T>*> _states;

public:
    PriorityQueue(const Comperator &func);
    State<T>* top();
    void pop();
    void push(State<T>* state);
    void update(State<T>* state);
    int getSize();
    bool Find(State<T>* state);
};


#endif //ALGORITHEMBRIDGE_PRIORITYQUEUE_H
