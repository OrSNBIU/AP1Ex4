//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_FILECACHEMANAGER_H
#define MILD2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

class FileCacheManager : public CacheManager<string,string> {
    unordered_map<string,string> solutions;
    static FileCacheManager *fileCacheManager;
    FileCacheManager();
public:
    static FileCacheManager* getFileCacheManager();
    bool Find(string problem) override ;
    string get(string problem) override ;
    void save(string problem,string solution) override ;
};


#endif //MILD2_FILECACHEMANAGER_H
