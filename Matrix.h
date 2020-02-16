//
// Created by grufix on 06/02/2020.
//

#ifndef ALGORITHEMBRIDGE_MATRIX_H
#define ALGORITHEMBRIDGE_MATRIX_H


#include "State.h"
#include "Searchable.h"
#include "PointState.h"
#include <vector>

class Matrix : public Searchable<std::pair<int,int>> {
int sizeR,sizeC;
State<std::pair<int,int>> *goal;
State<std::pair<int,int>> *initial;
std::vector<State<std::pair<int,int>>*> states;

public:
    Matrix(std::vector<double> input);
    State<std::pair<int,int>>* getInitialState() override ;
    bool isGoalState(State<std::pair<int,int>> *state) override ;
    std::list<State<std::pair<int,int>>*> getAllPosibleStates(State<std::pair<int,int>>* state) override ;
    int getsize();
    double getHuristicVal(State<std::pair<int, int>> *pState);
    ~Matrix();
};


#endif //ALGORITHEMBRIDGE_MATRIX_H
