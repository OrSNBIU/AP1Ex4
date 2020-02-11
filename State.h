//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_STATE_H
#define ALGORITHEMBRIDGE_STATE_H

template <class T>
class State {
    T* _state;
    double _cost,_moving;
    State<T>* _cameFrom;
public:
    State(T* state);
    T* getState();
    bool Equal(State<T> state);
    void setCost(double cost);
    double getCost();
    void setWhereFrom(State<T> state);
    State<T>* getCameFrom();
    double getMoving();
    bool operator==(State<T>* state);
    void updateMoving(double moving);


};


#endif //ALGORITHEMBRIDGE_STATE_H
