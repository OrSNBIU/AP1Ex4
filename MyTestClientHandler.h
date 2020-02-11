//
// Created by grufix on 25/01/2020.
//
//Header file for MyTestClientHandler
#ifndef MILD2_MYTESTCLIENTHANDLER_H
#define MILD2_MYTESTCLIENTHANDLER_H

#include <iostream>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

using namespace std;

class MyTestClientHandler : public ClientHandler {
Solver<string,string> *_solver;
CacheManager<string,string> *_cm;
public:
    MyTestClientHandler(Solver<string ,string > *solver, CacheManager<string ,string > *cm);
    void handleClient(int input, int output) override ;
    ClientHandler* clone() override ;
    ~MyTestClientHandler();
};


#endif //MILD2_MYTESTCLIENTHANDLER_H
