//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_SOLVER_H
#define MILD2_SOLVER_H

template<class Solution,class Problem>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;

};


#endif //MILD2_SOLVER_H
