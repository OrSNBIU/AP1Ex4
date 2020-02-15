//
// Created by grufix on 11/02/2020.
//

#include "AStar.h"

template <class T>
std::vector<std::string> AStar<T>::search(Searchable<T> *searchable) {
    int currentCost;
    std::unordered_map<std::string,State<T>*> closed;
    OpenInset(searchable->getInitialState()->setWhereFrom(NULL));
    while (this->OpenSize() > 0) {
        this->numberOfEvaluatedNodes++;
        State<T> *node = this->popOpen();
        if (closed.find(node) == closed.end()) {
            closed.insert(node->toString(),node);
        }
        if (searchable->isGoalState(node)) {
            Path<T> *sol = new Path<T>(node);
            return sol->getPath(node);
        }
        std::vector<State<T> *> neighborsOfNode = searchable->getAllPossibleStates();
        for (State<T> *state : neighborsOfNode) {
            currentCost = node->getMoving() + state->getCost();
            if (closed.find(state->toString()) == closed.end() && (!isInOpen(state))) {
                state->setWhereFrom(node);
                state->updateMoving(node);
                OpenInset(state);
            } else if (closed.find(state->toString()) == closed.end()  && state->getMoving() > currentCost) {
                state->setWhereFrom(node);
                state->updateMoving(node->getMoving());
                update(state);
            }
        }
    }
    std::cerr<<"no path"<<std::endl;
}