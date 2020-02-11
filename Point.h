//
// Created by grufix on 01/02/2020.
//
//Header file for Point class
#ifndef ALGORITHEMBRIDGE_POINT_H
#define ALGORITHEMBRIDGE_POINT_H

#include <iostream>

class Point {
int _row, _col;
double _cost = 0;
public:
    Point(int row,int col, double cost);
    void setRow(int row);
    int getRow();
    void setCol(int col);
    int getCol();
    void setCost(double cost);
    int getCost();
    bool operator==(Point p);
    bool operator!=(Point p);
    std::string side(Point p);
};


#endif //ALGORITHEMBRIDGE_POINT_H
