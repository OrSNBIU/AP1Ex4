//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_SEARCHER_H
#define ALGORITHEMBRIDGE_SEARCHER_H


#include <queue>
#include "ISearcher.h"
#include "PriorityQueue.h"
#include "Path.h"
#include<iostream>

template <class T,class Comperator>
class Searcher : public ISearcher<T,std::vector<std::string>>{
protected:
    PriorityQueue<T,Comperator> open ;
    int evaluatedNodes = 0;
public:
    void setOpen(const Comperator& comperator );
    void OpenInset(State<T> *state);
    void update(State<T> *state);
    State<T>* popOpen();
    int OpenSize();
    int numOfNodesEvaluated() override;
    bool isInOpen(State<T> *state);

    virtual std::vector<std::string> search(Searchable<T> *searchable) = 0;
};


#endif //ALGORITHEMBRIDGE_SEARCHER_H
