//
// Created by grufix on 31/01/2020.
//

#include "Searcher.h"
template <class T,class Comperator>
void Searcher<T,Comperator>::update(State<T> *state)  {
    return open.update(state);
}

template <class T,class Comperator>
void Searcher<T,Comperator>::setOpen(const Comperator &comperator)  {
    open.setQueue(comperator);
}

template <class T,class Comperator>
int Searcher<T,Comperator>::numOfNodesEvaluated()  {
    return evaluatedNodes;
}

template <class T,class Comperator>
bool Searcher<T,Comperator>::isInOpen(State<T> *state)  {
    return open.Find(state);
}

template <class T,class Comperator>
int Searcher<T,Comperator>::OpenSize()  {
    return open.size();
}

template <class T,class Comperator>
void Searcher<T,Comperator>::OpenInset(State<T> *state)  {
    open.push(state);
}

template <class T,class Comperator>
State<T>* Searcher<T,Comperator>::popOpen()  {
    evaluatedNodes++;
    State<T>* n = open.top();
    open->pop();
    return n;
}


