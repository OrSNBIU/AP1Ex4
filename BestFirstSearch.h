//
// Created by grufix on 31/01/2020.
//

#ifndef ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
#define ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H

#include "Path.h"
#include "Searcher.h"
#include "Searchable.h"

template<class T>
class BestFirstSearch : Searcher<T,Path<T>> {
public:
    BestFirstSearch();
    Path<T> search(Searchable<T> searchable) override;
};


#endif //ALGORITHEMBRIDGE_BESTFIRSTSEARCH_H
