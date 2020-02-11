//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_SEARCHER_H
#define ALGORITHEMBRIDGE_SEARCHER_H


#include <queue>
#include "IShearcher.h"
template <class T,class Solution>
class Searcher : public IShearcher<T,Solution>{
std::priority_queue<State<T>> open;
int evaluatedNodes;

public:
    Searcher();
    void OpenInset(State<T> state);
    void OpenRemove(State<T> state);
    State<T> popOpen();
    int OpenSize();
    int numOfNodesEvaluated() override ;
    bool isInOpen(State<T> state);
    virtual Solution search(Searchable<T> searchable) = 0;
};


#endif //ALGORITHEMBRIDGE_SEARCHER_H
