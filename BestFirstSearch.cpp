//
// Created by grufix on 31/01/2020.
//

#include "BestFirstSearch.h"
#include <vector>
#include <algorithm>
template<class T>
Path<T> traceBack(std::vector<State<T>> closed) {
    Path<T> path;
    State<T>* state = closed.back();
    while(state != NULL) {
        T* curr = state->getState();
        state = state->getCameFrom();
        path.insertToPath(curr->side(state.getState()));
    }
}

template<class T>
Path<T> BestFirstSearch<T>::search(Searchable<T> searchable) {
    OpenInset(searchable.getInitialState());
    std::vector<State<T>*> closed;
    while(this->OpenSize() > 0) {
        State<T>* n = this->popOpen();
        closed.push(n);
        if(searchable.isGoalState(n)) {
            return traceBack(closed);
        }
        for(State<T>* state : searchable.getAllPosibleStates(n)) {
            if(!this->isInOpen(state) && std::find(closed.begin(),closed.end(),state) == closed.end()) {
                state->setWhereFrom(n);
                OpenInset(state);
            }
            else {
                if(isInOpen(state)) {
                    if(state->getMoving() > (state->getCost() + n->getMoving()) ) {
                        OpenRemove(state);
                        state->updateMoving(n->getMoving());
                        OpenInset(state);
                    }
                }
            }
        }
    }
}