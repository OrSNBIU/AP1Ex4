//
// Created by grufix on 12/02/2020.
//

#include "PointState.h"



PointState::PointState(std::pair<int,int> state,double cost) : State(state,cost){}


bool PointState::Equal(State<std::pair<int,int>> *state) {
    return (state->getState().first == _state.first && state->getState().second == _state.second);
}


bool PointState::operator==(State<std::pair<int,int>> *state) {
    return Equal(state);
}

std::string PointState::toString() {
    return (std::to_string(_state.first) + "," +std::to_string(_state.second));
}

std::string PointState::getSide(State<std::pair<int, int> > *state) {
    int x_self,y_self,x_other, y_other;
    x_self= _state.first;
    y_self = _state.second;
    x_other = state->getState().first;
    y_other = state->getState().second;
    if(x_self + 1 == x_other && y_other == y_self)
        return "Right";
    else if(x_self + 1 == x_other && y_other == y_self)
        return "Left";
    else if(y_self + 1 == y_other && x_other == x_self)
        return "Up";
    else if(y_self - 1 == y_other && x_other == x_self)
        return "Down";
    else
        return "";
}

State<std::pair<int, int> > * PointState::clone() {
    State<std::pair<int,int>>* c_state = new PointState(_state,_cost);
    c_state->setWhereFrom(_cameFrom);
    c_state->updateMoving(_moving - _cost);
    c_state->setHuristic(_huristicCost);
    return c_state;
}