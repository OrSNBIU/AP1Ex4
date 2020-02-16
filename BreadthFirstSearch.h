//
// Created by grufix on 11/02/2020.
//

#ifndef ALGORITHEMBRIDGE_BREADTHFIRSTSEARCH_H
#define ALGORITHEMBRIDGE_BREADTHFIRSTSEARCH_H

#include <vector>
#include "Path.h"
#include "ISearcher.h"

template <class T>
class BreadthFirstSearch : public ISearcher<T,std::vector<std::string>> {
    std::list<State<T>*> open;
    int evaluatedNodes = 0;
public:
    BreadthFirstSearch();
    bool isInOpen(State<T>* state);
    std::vector<std::string> search(Searchable<T>* searchable) override;
    int numOfNodesEvaluated() override;
};


#endif //ALGORITHEMBRIDGE_BREADTHFIRSTSEARCH_H
