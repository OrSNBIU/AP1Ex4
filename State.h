//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_STATE_H
#define ALGORITHEMBRIDGE_STATE_H
#include<iostream>



template <class T>
class State {
protected:
    T _state;
    State<T>* _cameFrom;
    double _cost,_moving,_huristicCost;
public:
    State(T state, double cost);
    double getMoving();
    void updateMoving(double moving);
    double getCost();
    void setCost(double cost);
    double getHuristic();
    void setHuristic(double cost);
    T getState();
    void setWhereFrom(State<T>* state);
    State<T>* getCameFrom();

    virtual State<T>* clone() = 0;
    virtual bool Equal(State<T>* state) = 0;
    virtual bool operator==(State<T>* state) = 0;
    virtual std::string toString() = 0;
    virtual std::string getSide(State<T>* state) = 0;
    ~State();


};


#endif //ALGORITHEMBRIDGE_STATE_H
