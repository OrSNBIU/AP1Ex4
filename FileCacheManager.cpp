//
// Created by grufix on 25/01/2020.
//

#include "FileCacheManager.h"
FileCacheManager* FileCacheManager::fileCacheManager = 0;

FileCacheManager::FileCacheManager() {}
/**
 * creating one state of this class so there will be only one object
 * @return the only existing object
 */
FileCacheManager * FileCacheManager::getFileCacheManager() {
    if(fileCacheManager == 0)
        fileCacheManager = new FileCacheManager();
    return fileCacheManager;
}

/**
 * check if there is a solution to the given problem
 * @param problem broblem to solve
 * @return  if there is an existed solution
 */
bool FileCacheManager::Find(string problem) {
    return (solutions.find(problem)!=solutions.end());
}

/**
 * save the solution to a problem in a file
 * @param solution
 * @param problem
 */
void FileCacheManager::save(string solution, string problem) {
    fstream file;
    file.open(problem,ios::out);
    if(!file){
        throw "no file been opened";
    }
    file<<solution<<endl;
    file.close();
    if(!Find(problem)) {
        solutions.insert(pair<string,string>{problem,problem});
    }
}

/**
 * if the solution exist return it
 * @param problem
 * @return the solution to the problem
 */
string FileCacheManager::get(string problem) {
    if(Find(problem)) {
        fstream file;
        file.open(problem,ios::in);
        if(!file) {
            throw "no file been opened";
        }
        string solution = "";
        string line;
        while(getline(file,line)){
            solution+=line + "\n";
        }
        return solution;
    }
}