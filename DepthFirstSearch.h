//
// Created by grufix on 11/02/2020.
//

#ifndef ALGORITHEMBRIDGE_DEPTHFIRSTSEARCH_H
#define ALGORITHEMBRIDGE_DEPTHFIRSTSEARCH_H

#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include "Path.h"
#include "ISearcher.h"
using namespace std;
template<class T>
class DepthFirstSearch : public ISearcher<T,vector<string>> {
    stack<State<T>*> open;
    int evaluatedNodes;
    double minCost;
    State<T>* bestPath;
public:
    DepthFirstSearch();
    std::vector<std::string> search(Searchable<T>* searchable) override;
    bool isInOpen(State<T> *state);
    int numOfNodesEvaluated() override ;
    ~DepthFirstSearch() { delete(bestPath);}
};


#endif //ALGORITHEMBRIDGE_DEPTHFIRSTSEARCH_H
