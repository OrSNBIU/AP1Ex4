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
    State(T state, double cost){
        _state = state;
        _cost = cost;
        _moving = cost;
        _huristicCost = 0;
        _cameFrom= 0;
    }

    double getMoving(){
        return _moving;
    }

    void updateMoving(double moving) {
        _moving = _cost + moving;
    }

    double getCost()  {
        return _cost;
    }

    void setCost(double cost) {
        _cost = cost;
        _moving = cost;
    }

    double getHuristic() {
        return _huristicCost;
    }

    void setHuristic(double cost) {
        _huristicCost = cost;
    }

    T getState() { return _state;};

    void setWhereFrom(State<T>* state) { _cameFrom = state;}

    State<T>* getCameFrom() { return _cameFrom;}

    virtual State<T>* clone() = 0;
    virtual bool Equal(State<T>* state) = 0;
    virtual bool operator==(State<T>* state) = 0;
    virtual std::string toString() = 0;
    virtual std::string getSide(State<T>* state) = 0;

    ~State() { delete(_cameFrom);}


};


#endif //ALGORITHEMBRIDGE_STATE_H
