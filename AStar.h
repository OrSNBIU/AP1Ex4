//
// Created by grufix on 11/02/2020.
//

#ifndef ALGORITHEMBRIDGE_ASTAR_H
#define ALGORITHEMBRIDGE_ASTAR_H


#include <vector>
#include "Path.h"
#include "ISearcher.h"
#include "PriorityQueue.h"
#include "AStarComperator.h"

template<class T>
class AStar : public ISearcher<T,std::vector<std::string>> {
    PriorityQueue<State<T>*,AStarComperator<T>>* open = 0;
    int evaluatedNodes = 0;
public:
    AStar()  {
        open = new PriorityQueue<State<T>*,AStarComperator<T>>();
    }

    /*
     *for some uncleared reason when we tried the inheritance method, we got Errors for reasons un knowen
     *  so we decided to copy...we tried...
     */


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

    std::vector<std::string> search(Searchable<T> *searchable) override ;
};


#endif //ALGORITHEMBRIDGE_ASTAR_H
