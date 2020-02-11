//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_CACHEMANAGER_H
#define MILD2_CACHEMANAGER_H

template<class Solution, class Problem>
class CacheManager {
public:
    virtual bool Find(Problem problem) = 0; //Checking if a solution is available.
    virtual Solution get(Problem problem) = 0; //Fetching the solution
    virtual void save(Problem problem, Solution solution) = 0; //Save a solution for the problem
};


#endif //MILD2_CACHEMANAGER_H
