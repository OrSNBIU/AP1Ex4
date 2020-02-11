//
// Created by grufix on 25/01/2020.
//
//Header file for StringReverser
#ifndef MILD2_STRINGREVERSER_H
#define MILD2_STRINGREVERSER_H


#include "Solver.h"
#include <iostream>

using namespace std;

class StringReverser : public Solver<string,string> {
public:
    StringReverser();
    string solve(string problem) override;

};


#endif //MILD2_STRINGREVERSER_H
