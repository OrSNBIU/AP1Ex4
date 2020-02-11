//
// Created by grufix on 06/02/2020.
//
//Header file for Matrix class.
#ifndef ALGORITHEMBRIDGE_MATRIX_H
#define ALGORITHEMBRIDGE_MATRIX_H


#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include <vector>

class Matrix : public Searchable<Point> {
int size;
State<Point> *goal;
State<Point> *initial;
std::vector<State<Point>*> states;
public:
    Matrix(std::vector<double> input);
    State<Point>* getInitialState();
    bool isGoalState(State<Point> *state);
    std::list<State<Point>* > getAllPosibleStates(State<Point> state); //To learn how can I move.
};


#endif //ALGORITHEMBRIDGE_MATRIX_H
