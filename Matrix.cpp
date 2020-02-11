//
// Created by grufix on 06/02/2020.
//

#include "Matrix.h"
//Establishing a matrix of states to serve searchable. The matrix is our searchable.
Matrix::Matrix(std::vector<double> input) {
    double col_last = input.back();
    input.pop_back();
    double row_last = input.back();
    input.pop_back();
    Point *goalP = new Point(row_last,col_last,input[size*size-1]);
    double col_first = input.back();
    input.pop_back();
    double row_first = input.back();
    input.pop_back();
    Point *initialP = new Point(row_first,col_first,input[0] );
    size = row_last;
    for(int i = 0; i < row_last;i++) {
        for(int j = 0; j < col_last; j++) {
            states[i*size + j] = new State<Point>(new Point(i,j,input[i*size + j]));
            states[i*size + j]->setCost(input[i*size + j]);
        }
    }
    goal = new State<Point>(goalP);
    goal->setCost(goalP->getCost());
    initial = new State<Point>(initialP);
    initial->setCost(initialP->getCost());
}

State<Point>* Matrix::getInitialState() {
    return initial;
}

std::list<State<Point>* > Matrix::getAllPosibleStates(State<Point> state) {
    Point* p = state.getState();
    int x = p->getRow(), y = p->getCol();
    std::list<State<Point>*> posibleStates;
    posibleStates.push_back(states[x*size + y + 1]);
    posibleStates.push_back(states[x*size + y  - 1]);
    posibleStates.push_back(states[(x + 1)*size + y ]);
    posibleStates.push_back(states[(x - 1)*size + y ]);
    return posibleStates;
}

bool Matrix::isGoalState(State<Point> *state) {
    return (state->getState() == goal->getState());
}

