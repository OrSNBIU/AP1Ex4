//
// Created by grufix on 15/02/2020.
//

#include "PriorityQueue.h"
template <class T,class Comperator>
PriorityQueue<T,Comperator>::PriorityQueue(const Comperator &func) {
    std::priority_queue<State<T>*,std::vector<State<T>*>,decltype(func)> temp(func);
    _queue = temp;
}

template <class T,class Comperator>
State<T> * PriorityQueue<T,Comperator>::top() { return _queue.top();}

template <class T,class Comperator>
void PriorityQueue<T,Comperator>::pop() {_queue.pop();}

template <class T,class Comperator>
void PriorityQueue<T,Comperator>::push(State<T> *state) {
    _queue.push(state);
    _states.insert(state->toString(),state);
}

template <class T,class Comperator>
int PriorityQueue<T,Comperator>::getSize() { return _queue.size(); }

template <class T,class Comperator>
void PriorityQueue<T,Comperator>::update(State<T> *state) {
    std::vector<State<T>*> temp;
    while(_queue.size() > 0) {
        temp.push_back(_queue.top());
        _queue.pop();
    }
    while(temp.size() > 0) {
        _queue.push(temp.back());
        temp.pop_back();
    }
}

template <class T,class Comperator>
bool PriorityQueue<T,Comperator>::Find(State<T> *state) { return _states.find(state) != _states.end();}

