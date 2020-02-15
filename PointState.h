//
// Created by grufix on 12/02/2020.
//

#ifndef ALGORITHEMBRIDGE_POINTSTATE_H
#define ALGORITHEMBRIDGE_POINTSTATE_H



#include "State.h"

class PointState : public State<std::pair<int,int>>{
public:
    PointState(std::pair<int,int> state, double cost) : State(state,cost){}
    bool Equal(State<std::pair<int,int>>* state) override;
    bool operator==(State<std::pair<int,int>>* state) override;
    std::string toString() override;
    std::string getSide(State<std::pair<int,int>>* state) override ;
    State<std::pair<int,int>>* clone() override ;
};


#endif //ALGORITHEMBRIDGE_POINTSTATE_H
