//
// Created by grufix on 15/02/2020.
//

#ifndef ALGORITHEMBRIDGE_ALGORITHEMSTESTING_H
#define ALGORITHEMBRIDGE_ALGORITHEMSTESTING_H


#include <fstream>
#include <iostream>
#include <vector>
#include "AStar.h"
#include "BreadthFirstSearch.h"
#include "BestFirstSearch.h"
#include "DepthFirstSearch.h"
#include "Matrix.h"

using namespace std;

class AlgorithemsTesting {
int evaluatedNodes[4][10];

public:
    void testall();
};


#endif //ALGORITHEMBRIDGE_ALGORITHEMSTESTING_H
