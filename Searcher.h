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
    PriorityQueue<State<T>*,Comperator>* open = 0;
    int evaluatedNodes = 0;
public:
    Searcher(PriorityQueue<State<T>*,Comperator>* p_q){
        open = p_q;
    }


    virtual std::vector<std::string> search(Searchable<T> *searchable) = 0;

    ~Searcher() {
        delete(open);
    }
};


#endif //ALGORITHEMBRIDGE_SEARCHER_H
