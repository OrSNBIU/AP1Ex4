//
// Created by grufix on 11/02/2020.
//


#include "DepthFirstSearch.h"

template <class T>
DepthFirstSearch<T>::DepthFirstSearch() {
    evaluatedNodes = 0;
    minCost = 0;
}




template<class T>
std::vector<std::string> DepthFirstSearch<T>::search(Searchable<T> *searchable) {
    open.push(searchable->getInitialState());
    std::unordered_map<std::string,State<T>*> closed;
    double currentCost;
    while (!open.empty()) {
        State<T>* node = this->open.top();
        open.pop();
        evaluatedNodes++;
        closed.insert(node->toString(),node);
        if(searchable->isGoalState(node)) {
            if(minCost == 0){
                minCost = node->getMoving();
                bestPath = node->clone();
            }
            else if(node->getMoving() < minCost) {
                minCost = node->getMoving();
                bestPath = node->clone();
            }
        }
        std::vector<State<T>*> neighbors = searchable->getAllPosibleStates(node);
        for(State<T>* state : neighbors) {
            if(closed.find(state->toString()) == closed.end() && !isInOpen(state)) {
                state->setWhereFrom(node);
                open.push(state);
            }
            else if(isInOpen(state)) {
                if(state->getMoving() > state->getCost() + node->getMoving()) {
                    state->setWhereFrom(node);
                }
            }
        }
    }
    if(bestPath == 0)
        std::cerr<<"no path found"<<endl;
    Path<T>* sol = new Path<T>(bestPath);
    return sol ->getPath();
}

template <class T>
bool DepthFirstSearch<T>::isInOpen(State<T>* state) {
    std::stack<State<T> *> temp;
    bool find = false;
    while (!open.top()->Equal(state) && !find) {
        if (!state->Equal(open.top())) {
            temp.push(open.top());
            open.pop();
        } else find = true;
    }
    while (!temp.empty()) {
        open.push(temp.top());
        temp.pop();
    }
    return find;
}

template <class T>
int DepthFirstSearch<T>::numOfNodesEvaluated() { return evaluatedNodes; }

