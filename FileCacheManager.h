//
// Created by grufix on 25/01/2020.
//
//Header file for FileCacheManager

#ifndef MILD2_FILECACHEMANAGER_H
#define MILD2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

class FileCacheManager : public CacheManager<string,string> {
    unordered_map<string,string> solutions; //A map that holds the name of the file- 
    //which is the name of the solution, and the solution itself.
    static FileCacheManager *fileCacheManager;
    FileCacheManager();
public:
    static FileCacheManager* getFileCacheManager();
    bool Find(string problem) override; //Overriding inherited methods.
    string get(string problem) override; //Overriding inherited methods.
    void save(string problem,string solution) override; //Overriding inherited methods.
};


#endif //MILD2_FILECACHEMANAGER_H
