//
// Created by grufix on 11/02/2020.
//

#include <unordered_map>
#include "BreadthFirstSearch.h"

template <class T>
BreadthFirstSearch<T>::BreadthFirstSearch() {
    evaluatedNodes = 0;
}

template <class T>
std::vector<std::string>  BreadthFirstSearch<T>::search(Searchable<T> *searchable) {
        //mutexLock.lock();
        open.push_back(searchable->getInitialState());
        evaluatedNodes++;
        std::unordered_map<std::string,State<T>*> closed;
        State<T>* currentNode;
        std::vector<State<T>*> neighborsOfNode;
        double currentCost;
        while (this->OpenSize() > 0) {
            currentNode = open.front();
            open.pop_front();
            if (searchable->isGoalState(currentNode)) { //We found what we've been looking for.
                Path<T> *sol = new Path<T>(currentNode);
                return sol->getPath();
            }
            neighborsOfNode = searchable->getAllPossibleStates(currentNode);
            auto iterator = neighborsOfNode.begin();
            for (State<T>* state : searchable->getAllPosibleStates(currentNode)) {
                currentCost = currentNode->getCost() + searchable->getMovingCost(currentNode);
            if (!this->isInOpen(state) && closed.find(state->toString()) == closed.end()) {
                closed.insert(state->toString(),state);
                state->setWhereFrom(currentNode);
                open.push_back(state);
                evaluatedNodes++;
            }
        }
    }
}

template <class T>
bool BreadthFirstSearch<T>::isInOpen(State<T> *state) {
    for(State<T>* st : open) {
        if(*st->Equal(state))
            return true;
    }
    return false;
}

template <class T>
int BreadthFirstSearch<T>::numOfNodesEvaluated() { return evaluatedNodes; }