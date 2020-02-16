//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
#define ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H

#include <vector>
#include "Path.h"
#include "Searchable.h"
#include "BestFirstSearchComperator.h"
#include "PriorityQueue.h"
#include"Searcher.h"

template<class T>
class BestFirstSearch : public Searcher<T,BestFirstSearchComperator<T>> {
public:
    BestFirstSearch();
    std::vector<std::string> search(Searchable<T>* searchable) override;
};


#endif //ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
