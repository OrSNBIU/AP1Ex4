//
// Created by grufix on 31/01/2020.
//

#include "BestFirstSearch.h"
#include <vector>
#include <algorithm>

template <class T>
BestFirstSearch<T>::BestFirstSearch()  {
    this->setOpen(BestFirstSearchComperator<T>());
    this->evaluatedNodes = 0;
}

template<class T>
std::vector<std::string> BestFirstSearch<T>::search(Searchable<T>* searchable) {
    OpenInset(searchable->getInitialState());
    std::vector<State<T>*> closed;
    while(this->OpenSize() > 0) {
        State<T>* n = this->popOpen();
        closed.push(n);
        if(searchable->isGoalState(n)) {
            Path<T> sol =  new Path<T>(n);
            return sol->getPath();
        }
        for(State<T>* state : searchable->getAllPosibleStates(n)) {
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