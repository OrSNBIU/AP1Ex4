//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
#define ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H

#include <vector>
#include "Path.h"
#include "Searchable.h"
#include "BestFirstSearchComperator.h"
#include "PriorityQueue.h"
#include"ISearcher.h"

template<class T>
class BestFirstSearch : public ISearcher<T,std::vector<std::string>> {
    PriorityQueue<State<T>*,BestFirstSearchComperator<T>>* open = 0;
    int evaluatedNodes = 0;
public:
    BestFirstSearch() {
        open = new PriorityQueue<State<T>*,BestFirstSearch<T>>();
    }

    std::vector<std::string> search(Searchable<T>* searchable) override;

    void OpenInset(State<T> *state) {
        open->push(state);
        evaluatedNodes++;
    }

    void update(State<T> *state) {
        return open->Find(state);
    }

    State<T>* popOpen() {
        evaluatedNodes++;
        State<T>* n = open->top();
        open->pop();
        return n;
    }

    int OpenSize() {
        return open->size();
    }

    int numOfNodesEvaluated() override {
        return evaluatedNodes;
    }

    bool isInOpen(State<T> *state) {
        return open->Find(state);
    }

    std::vector<std::string> getPath(State<T>* state) {
        open->update(state);
    }
};


#endif //ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
