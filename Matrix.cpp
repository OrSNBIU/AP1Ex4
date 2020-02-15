//
// Created by grufix on 06/02/2020.
//

#include "Matrix.h"
#include "PointState.h"

Matrix::Matrix(std::vector<double> input) {
    double col_last = input.back();
    input.pop_back();
    double row_last = input.back();
    input.pop_back();
    std::pair<int,int> goalP {row_last,col_last};
    double col_first = input.back();
    input.pop_back();
    double row_first = input.back();
    input.pop_back();
    std::pair<int,int> initialP {row_first,col_first};
    sizeR = row_last + 1;
    sizeC = col_last + 1;
    double goalCost = input.back(),initialCost = input.front();
    initial = new PointState(initialP,initialCost);
    goal = new PointState(goalP,goalCost);
    for(int i = 0; i < sizeR ;i++) {
        for(int j = 0; j < sizeC; j++) {
            State<std::pair<int,int>> *state = new PointState(std::pair<int,int> {i,j},input[i*sizeR + j]);
            //std::cout<<"inserted :"<<state->toString()<<" with cost: "<<input[i*sizeR+j]<<std::endl;
            state->setHuristic(getHuristicVal(state));
            states.push_back(state);
        }
    }
}

State<std::pair<int,int>>* Matrix::getInitialState() {
    return initial;
}

std::list<State<std::pair<int,int>>*> Matrix::getAllPosibleStates(State<std::pair<int,int>> *state) {
    std::pair<int,int> p = (state->getState());
    int x = p.first, y = p.second;
    std::list<State<std::pair<int,int>>*> posibleStates;
    if(y < sizeC)
        posibleStates.push_back(states[x*sizeR + y + 1]);
    if(y > 0)
        posibleStates.push_back(states[x*sizeR + y  - 1]);
    if(x < sizeR)
        posibleStates.push_back(states[(x + 1)*sizeR + y ]);
    if(x > 0)
        posibleStates.push_back(states[(x - 1)*sizeR + y ]);
    return posibleStates;
}

bool Matrix::isGoalState(State<std::pair<int,int>> *state) {
    return (state->getState() == goal->getState());
}

double Matrix::getHuristicVal(State<std::pair<int, int>> *pState) {
    return (abs(pState->getState().first-initial->getState().first + pState->getState().second-initial->getState().second));
}

