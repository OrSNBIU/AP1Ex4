//
// Created by grufix on 31/01/2020.
//

#ifndef MILD2_POINT_H
#define MILD2_POINT_H


class Point {
int _row, _col;
double _cost;
public:
    Point(int row,int col) {
        _row = row;
        _col = col;
    }
    int getRow() {return _row;}
    int getCol() {return _col;}
    double getCost() {return _cost;}
    string side(Point p);
    bool operator==(Point p);
    bool operator!=(Point p);
};


#endif //MILD2_POINT_H
