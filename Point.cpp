//
// Created by grufix on 01/02/2020.
//

#include "Point.h"

Point::Point(int row, int col, double cost) {
    _row = row;
    _col = col;
    _cost = cost;
}

void Point::setRow(int row) {_row = row;}

void Point::setCol(int col) {_col = col;}

void Point::setCost(double cost) {_cost = cost;}

int Point::getRow() {return _row;}

int Point::getCol() {return _col;}

int Point::getCost() {return _cost;}

bool Point::operator!=(Point p) {
    return (_row != p.getRow() || _col != p.getCol());
}

bool Point::operator==(Point p) {
    return (_row == p.getRow() && _col == p.getCol());
}

std::string Point::side(Point p) {
    if(_row - p.getRow() == 1 && _col - p.getCol() == 0)
        return "Down";
    if(_row - p.getRow() == 0 && _col - p.getCol() == 1)
        return "Right";
    if(_row - p.getRow() == -1 && _col - p.getCol() == 0)
        return "Up";
    if(_row - p.getRow() == 0 && _col - p.getCol() == -1)
        return "Left";
    else return "Error";
}