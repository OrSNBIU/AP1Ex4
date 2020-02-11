//
// Created by grufix on 31/01/2020.
//

#include "Searcher.h"
template<class T,class Solution>
Searcher<T,Solution>::Searcher() {
    evaluatedNodes = 0;
}

template<class T,class Solution>
int Searcher<T,Solution>::numOfNodesEvaluated() {
    return evaluatedNodes;
}

template<class T,class Solution>
int Searcher<T,Solution>::OpenSize() {
    return open.size();
}

template<class T,class Solution>
State<T> Searcher<T,Solution>::popOpen() {
    evaluatedNodes++;
    State<T> n = open.top();
    open.pop();
    return n;
}

template<class T,class Solution>
void Searcher<T,Solution>::OpenInset(State<T> state) {
    open.push(state);
}

template<class T,class Solution>
bool Searcher<T,Solution>::isInOpen(State<T> state) {
    int c = 0;
    for(State<T> n : open) {
        if(n == state) {
            c++;
        }
    }
    return (c > 0);
}

template<class T,class Solution>
void Searcher<T,Solution>::OpenRemove(State<T> state) {
    std::vector<State<T>> temp;
    while(open.top()!= state) {
        temp.push_back(open.top());
        open.pop();
    }
    open.pop();
    while(!temp.empty()) {
        open.push(temp.back());
        temp.pop_back();
    }
}

