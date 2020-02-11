//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_CACHEMANAGER_H
#define MILD2_CACHEMANAGER_H

template<class Solution, class Problem>
class CacheManager {
public:
    virtual bool Find(Problem problem) = 0;
    virtual Solution get(Problem problem) = 0;
    virtual void save(Problem problem, Solution solution) = 0;
};


#endif //MILD2_CACHEMANAGER_H
