//
// Created by grufix on 16/02/2020.
//
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <netinet/in.h>
#include <fstream>
#include <mutex>

using namespace std;








//-----------------------------------------------------------------------------
template <class T>
class State {
protected:
    T _state;
    State<T>* _cameFrom;
    double _cost,_moving,_huristicCost;
    string name;
public:
    State(T state, double cost);
    double getMoving();
    void updateMoving(double moving);
    double getCost();
    void setCost(double cost);
    double getHuristic();
    void setHuristic(double cost);
    T getState();
    void setWhereFrom(State<T>* state);
    State<T>* getCameFrom();

    virtual State<T>* clone() = 0;
    virtual bool Equal(State<T>* state) = 0;
    virtual bool operator==(State<T>* state) = 0;
    virtual std::string toString() = 0;
    virtual std::string getSide(State<T>* state) = 0;
    ~State();

};
/**
 * Ctor
 * @tparam T
 * @param state
 * @param cost
 */
template <class T>
State<T>::State(T state, double cost) {
    _state = state;
    _cost = cost;
    _moving = cost;
    _huristicCost = 0;
    _cameFrom= 0;
}

/**
 * return the cost of the path till here
 * @tparam T
 * @return
 */
template <class T>
double State<T>::getMoving() {
    return _moving;
}

/**
 * return the father
 * @tparam T
 * @return
 */
template <class T>
State<T> * State<T>::getCameFrom()  { return _cameFrom;}

/**
 * return the state's data
 * @tparam T
 * @return
 */
template <class T>
T State<T>::getState() { return _state;};

/**
 * return the huristic value
 * @tparam T
 * @return
 */
template <class T>
double State<T>::getHuristic()  {
    return _huristicCost;
}


/**
 * set a huristic valse
 * @tparam T
 * @param cost value to set
 */
template <class T>
void State<T>::setHuristic(double cost)  {
    _huristicCost = cost;
}

/**
 * return the step in cost
 * @tparam T
 * @return
 */
template <class T>
double State<T>::getCost()  {
    return _cost;
}

/**
 * set the step in cost
 * @tparam T
 * @param cost
 */
template <class T>
void State<T>::setCost(double cost) {
    _cost = cost;
    _moving = cost;
}

/**
 * update the cost of the path till here
 * @tparam T
 * @param moving cost of new path to here
 */
template <class T>
void State<T>::updateMoving(double moving)  {
    _moving = _cost + moving;
}


/**
 * set the father
 * @tparam T
 * @param state the father
 */
template <class T>
void State<T>::setWhereFrom(State<T> *state)  { _cameFrom = state;}

/**
 * Dtor
 * @tparam T
 */
template <class T>
State<T>::~State() { delete(_cameFrom);}



//-----------------------------------------------------------------------------
template<class T>
class Path {
    std::vector<State<T>*> path;
public:
    Path(State<T>* state);
    void insertToPath(State<T>* state);
    std::vector<std::string> getPath();

};

/**
 * Ctor
 * @tparam T
 * @param goal
 */
template<class T>
Path<T>::Path(State<T>* goal) {
    State<T>* state = goal;
    while(state->getCameFrom() != NULL) {
        path.push_back(state);
        state = state->getCameFrom();
    }
}

/**
 * isert new node to the path
 * @tparam T
 * @param state
 */
template<class T>
void Path<T>::insertToPath(State<T>* state) {
    path.push_back(state);
}

/**
 * return the steps to the goal
 * @tparam T
 * @return
 */
template<class T>
std::vector<std::string> Path<T>::getPath() {
    std::vector<std::string> moves;
    for(int i = 0;i < path.size();i++) {
        State<T>* curr = path.back();
        path.pop_back();
        moves.push_back(curr->getSide(path.back()));
    }
    return moves;
}

//-----------------------------------------------------------------------------
template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual std::list<State<T>*> getAllPossibleStates(State<T>* state) = 0;
};





//-----------------------------------------------------------------------------
template <class T,class Solution>
class ISearcher {
public:
    virtual Solution search(Searchable<T> *searchable) = 0;
    virtual int numOfNodesEvaluated() = 0;
    virtual void resetnodes() = 0;
};


//-----------------------------------------------------------------------------
class PointState : public State<std::pair<int,int>>{
public:
    PointState(std::pair<int,int> state, double cost);
    bool Equal(State<std::pair<int,int>>* state) override;
    bool operator==(State<std::pair<int,int>>* state) override;
    std::string toString() override;
    std::string getSide(State<std::pair<int,int>>* state) override ;
    State<std::pair<int,int>>* clone() override ;
};

/**
 * Ctor
 * @param state
 * @param cost
 */
PointState::PointState(std::pair<int,int> state,double cost) : State(state,cost){
    name = this->toString();
}

/**
 * check if this state equal to the given state
 * @param state
 * @return
 */
bool PointState::Equal(State<std::pair<int,int>> *state) {
    return (state->getState().first == _state.first && state->getState().second == _state.second);
}

/**
 * operator is equal
 * @param state
 * @return
 */
bool PointState::operator==(State<std::pair<int,int>> *state) {
    return Equal(state);
}

std::string PointState::toString() {
    return (std::to_string(_state.first) + "," +std::to_string(_state.second));
}

std::string PointState::getSide(State<std::pair<int, int> > *state) {
    int x_self,y_self,x_other, y_other;
    x_self= _state.first;
    y_self = _state.second;
    x_other = state->getState().first;
    y_other = state->getState().second;
    if(x_self + 1 == x_other && y_other == y_self)
        return "Down";
    else if(x_self - 1 == x_other && y_other == y_self)
        return "Up";
    else if(y_self + 1 == y_other && x_other == x_self)
        return "Right";
    else if(y_self - 1 == y_other && x_other == x_self)
        return "Left";
    else
        return "";
}

State<std::pair<int, int> > * PointState::clone() {
    State<std::pair<int,int>>* c_state = new PointState(_state,_cost);
    c_state->setWhereFrom(_cameFrom);
    c_state->updateMoving(_moving - _cost);
    c_state->setHuristic(_huristicCost);
    return c_state;
}





//-----------------------------------------------------------------------------
class Matrix : public Searchable<std::pair<int,int>> {
    int sizeR,sizeC;
    State<std::pair<int,int>> *goal;
    State<std::pair<int,int>> *initial;
    std::vector<State<std::pair<int,int>>*> states;

public:
    Matrix(std::vector<double> input);
    State<std::pair<int,int>>* getInitialState() override ;
    bool isGoalState(State<std::pair<int,int>> *state) override ;
    std::list<State<std::pair<int,int>>*> getAllPossibleStates(State<std::pair<int,int>>* state) override ;
    int getsize();
    double getHuristicVal(State<std::pair<int, int>> *pState);
    ~Matrix();
};
Matrix::Matrix(std::vector<double> input) {
    double col_last = input.back();
    input.pop_back();
    double row_last = input.back();
    input.pop_back();
    std::pair<int,int> goalP {row_last,col_last};
    double col_first = input.back();
    input.pop_back();
    double row_first = input.back();
    input.pop_back();
    std::pair<int,int> initialP {row_first,col_first};
    sizeR = row_last + 1;
    sizeC = col_last + 1;
    double goalCost = input.back(),initialCost = input.front();
    initial = new PointState(initialP,initialCost);
    goal = new PointState(goalP,goalCost);
    for(int i = 0; i < sizeR ;i++) {
        for(int j = 0; j < sizeC; j++) {
            State<std::pair<int,int>> *state = new PointState(std::pair<int,int> {i,j},input[i*sizeR + j]);
            //std::cout<<"inserted :"<<state->toString()<<" with cost: "<<input[i*sizeR+j]<<std::endl;
            state->setHuristic(getHuristicVal(state));
            states.push_back(state);
        }
    }
}

Matrix::~Matrix() {
    delete (initial);
    delete(goal);
}

int Matrix::getsize() { return sizeR; }

State<std::pair<int,int>>* Matrix::getInitialState() {
    return initial;
}

std::list<State<std::pair<int,int>>*> Matrix::getAllPossibleStates(State<std::pair<int,int>> *state) {
    std::pair<int,int> p = (state->getState());
    int x = p.first, y = p.second;
    std::list<State<std::pair<int,int>>*> posibleStates;
    if(x < sizeR - 1)
        posibleStates.push_back(states[(x + 1)*sizeR + y ]);
    if(y < sizeC - 1) {
        posibleStates.push_back(states[x*sizeR + y + 1]);
    }
    if(x > 0) {
        posibleStates.push_back(states[(x - 1)*sizeR + y ]);
    }
    if(y > 0) {
        posibleStates.push_back(states[x*sizeR + y  - 1]);
    }
    return posibleStates;
}

bool Matrix::isGoalState(State<std::pair<int,int>> *state) {
    return (state->getState() == goal->getState());
}

double Matrix::getHuristicVal(State<std::pair<int, int>> *pState) {
    return (abs(pState->getState().first-initial->getState().first + pState->getState().second-initial->getState().second));
}






//-----------------------------------------------------------------------------
template <class T,class Comperator>
class PriorityQueue {
    std::priority_queue<State<T>*, std::vector<State<T>*>,Comperator> _queue;
    std::unordered_map<std::string,State<T>*> _states;

public:
    void setQueue(Comperator func);
    State<T>* top();
    void pop();
    void push(State<T>* state);
    void update(State<T>* state);
    int getSize();
    bool Find(State<T>* state);

};

template<class T,class Comperator>
void PriorityQueue<T,Comperator>::setQueue(Comperator func) {
    {
        std::priority_queue<State<T>*,std::vector<State<T>*>,decltype(func)> temp(func);
        _queue = temp;
    }
}

template<class T,class Comperator>
void PriorityQueue<T,Comperator>::pop() {_queue.pop();}

template<class T,class Comperator>
State<T> * PriorityQueue<T,Comperator>::top() { return _queue.top();}

template<class T,class Comperator>
void PriorityQueue<T,Comperator>::update(State<T> *state)  {
    std::vector<State<T>*> temp;
    while(_queue.size() > 0) {
        temp.push_back(_queue.top());
        _queue.pop();
    }
    while(temp.size() > 0) {
        _queue.push(temp.back());
        temp.pop_back();
    }
}

template<class T,class Comperator>
bool PriorityQueue<T,Comperator>::Find(State<T> *state)  { return _states.find(state->toString()) != _states.end();}

template<class T,class Comperator>
int PriorityQueue<T,Comperator>::getSize() { return _queue.size(); }

template <class T,class Comperator>
void PriorityQueue<T,Comperator>::push(State<T> *state)  {
    _queue.push(state);
    _states.insert({state->toString(),state});
}





//-----------------------------------------------------------------------------
template <class T,class Comperator>
class Searcher : public ISearcher<T,std::vector<std::string>>{
protected:
PriorityQueue<T,Comperator> open ;
int evaluatedNodes = 0;
public:
void setOpen(const Comperator& comperator );
void OpenInset(State<T> *state);
void update(State<T> *state);
State<T>* popOpen();
int OpenSize();
int numOfNodesEvaluated() override;
bool isInOpen(State<T> *state);
void resetnodes() override ;

virtual std::vector<std::string> search(Searchable<T> *searchable) = 0;
};

template <class T,class Comperator>
void Searcher<T,Comperator>::update(State<T> *state)  {
    return open.update(state);
}

template <class T,class Comperator>
void Searcher<T,Comperator>::setOpen(const Comperator &comperator)  {
    open.setQueue(comperator);
}

template <class T,class Comperator>
int Searcher<T,Comperator>::numOfNodesEvaluated()  {
    return evaluatedNodes;
}

template <class T,class Comperator>
bool Searcher<T,Comperator>::isInOpen(State<T> *state)  {
    return open.Find(state);
}

template <class T,class Comperator>
int Searcher<T,Comperator>::OpenSize()  {
    return open.getSize();
}

template <class T,class Comperator>
void Searcher<T,Comperator>::OpenInset(State<T> *state)  {
    open.push(state);
}

template <class T,class Comperator>
State<T>* Searcher<T,Comperator>::popOpen()  {
    evaluatedNodes++;
    State<T>* n = open.top();
    open.pop();
    return n;
}

template <class T,class Comperator>
void Searcher<T,Comperator>::resetnodes() {
    evaluatedNodes = 0;
}



//-----------------------------------------------------------------------------
template <class T>
class AStarComperator {
public:
    bool operator()(State<T>* s1,State<T>* s2);
};

template <class T>
bool AStarComperator<T>::operator()(State<T> *s1, State<T> *s2) {
    return (s1->getMoving() + s1->getHuristic()) < (s2->getMoving() + s2->getHuristic());
}





//-----------------------------------------------------------------------------
template<class T>
class AStar : public Searcher<T,AStarComperator<T>> {
public:
AStar();
std::vector<std::string> search(Searchable<T> *searchable) override ;
};


template <class T>
AStar<T>::AStar() {
    this->setOpen(AStarComperator<T>());
    this->evaluatedNodes = 0;
}

template <class T>
std::vector<std::string> AStar<T>::search(Searchable<T> *searchable) {
    int currentCost;
    std::unordered_map<std::string,State<T>*> closed;
    this->OpenInset(searchable->getInitialState());
    while (this->OpenSize() > 0) {
        State<T> *node = this->popOpen();
        if (closed.find(node->toString()) == closed.end()) {
            closed.insert({node->toString(),node});
        }
        if (searchable->isGoalState(node)) {
            Path<T> *sol = new Path<T>(node);
            return sol->getPath();
        }
        list<State<pair<int, int>> *> neighborsOfNode = searchable->getAllPossibleStates(node);
        for (State<T> *state : neighborsOfNode) {
            if(state == NULL || state->getCost() == -1)
                continue;
            currentCost = node->getMoving() + state->getCost();
            if (closed.find(state->toString()) == closed.end() && (!this->isInOpen(state))) {
                state->setWhereFrom(node);
                state->updateMoving(node->getMoving());
                this->OpenInset(state);
            } else if (closed.find(state->toString()) == closed.end()  && state->getMoving() > currentCost) {
                state->setWhereFrom(node);
                state->updateMoving(node->getMoving());
                this->update(state);
            }
        }
    }
    std::cerr<<"no path"<<std::endl;
}






//-----------------------------------------------------------------------------
template<class T>
class BestFirstSearchComperator {
public:
    bool operator()(State<T>* s1,State<T>* s2);
};

template <class T>
bool BestFirstSearchComperator<T>::operator()(State<T> *s1, State<T> *s2) {
    return s1->getMoving() < s2->getMoving();
}

//-----------------------------------------------------------------------------
template<class T>
class BestFirstSearch : public Searcher<T,BestFirstSearchComperator<T>> {
public:
BestFirstSearch();
std::vector<std::string> search(Searchable<T>* searchable) override;
};

template <class T>
BestFirstSearch<T>::BestFirstSearch()  {
    this->setOpen(BestFirstSearchComperator<T>());
    this->evaluatedNodes = 0;
}

template<class T>
std::vector<std::string> BestFirstSearch<T>::search(Searchable<T>* searchable) {
    this->OpenInset(searchable->getInitialState());
    std::unordered_map<string,State<T>*> closed;
    while(this->OpenSize() > 0) {
        State<T>* n = this->popOpen();
        closed.insert({n->toString(),n});
        if(searchable->isGoalState(n)) {
            Path<T> *sol =  new Path<T>(n);
            return sol->getPath();
        }
        for(State<T>* state : searchable->getAllPossibleStates(n)) {
            if(state == NULL || state->getCost() == -1)
                continue;
            if(!this->isInOpen(state) && closed.find(state->toString()) == closed.end()) {
                state->setWhereFrom(n);
                this->OpenInset(state);
            }
            else {
                if(this->isInOpen(state)) {
                    if(state->getMoving() > (state->getCost() + n->getMoving()) ) {
                        state->updateMoving(n->getMoving());
                        this->update(state);
                    }
                }
            }
        }
    }
}



//-----------------------------------------------------------------------------
template <class T>
class BreadthFirstSearch : public ISearcher<T,std::vector<std::string>> {
std::list<State<T>*> open;
int evaluatedNodes = 0;
public:
BreadthFirstSearch();
bool isInOpen(State<T>* state);
std::vector<std::string> search(Searchable<T>* searchable) override;
int numOfNodesEvaluated() override;
void resetnodes() override ;
};

template <class T>
BreadthFirstSearch<T>::BreadthFirstSearch() {}

template <class T>
std::vector<std::string>  BreadthFirstSearch<T>::search(Searchable<T> *searchable) {
    //mutexLock.lock();
    open.push_back(searchable->getInitialState());
    evaluatedNodes++;
    std::unordered_map<std::string,State<T>*> closed;
    State<T>* currentNode;
    double currentCost;
    while (this->open.size() > 0) {
        currentNode = open.front();
        open.pop_front();
        evaluatedNodes++;
        if (searchable->isGoalState(currentNode)) { //We found what we've been looking for.
            Path<T> *sol = new Path<T>(currentNode);
            return sol->getPath();
        }
        for (State<T>* state : searchable->getAllPossibleStates(currentNode)) {
            if(state == NULL || state->getCost() == -1)
                continue;
            currentCost = currentNode->getCost() + state->getMoving();
            if (!this->isInOpen(state) && closed.find(state->toString()) == closed.end()) {
                closed.insert({state->toString(),state});
                state->setWhereFrom(currentNode);
                open.push_back(state);
            }
        }
    }
}

template <class T>
bool BreadthFirstSearch<T>::isInOpen(State<T> *state) {
    for(State<T>* st : open) {
        if(st->Equal(state))
            return true;
    }
    return false;
}

template <class T>
int BreadthFirstSearch<T>::numOfNodesEvaluated() { return evaluatedNodes; }

template <class T>
void BreadthFirstSearch<T>::resetnodes() { evaluatedNodes = 0;}

//-----------------------------------------------------------------------------
template<class T>
class DepthFirstSearch : public ISearcher<T,vector<string>> {
std::stack<State<T>*> open;
int evaluatedNodes = 0;
double minCost = 0;
State<T>* bestPath = 0;
public:
DepthFirstSearch();
std::vector<std::string> search(Searchable<T>* searchable) override;
bool isInOpen(State<T> *state);
int numOfNodesEvaluated() override ;
void resetnodes() override ;
void update(State<T>* state);
~DepthFirstSearch();
};

template<class T>
DepthFirstSearch<T>::DepthFirstSearch() {}

template <class T>
DepthFirstSearch<T>::~DepthFirstSearch<T>()  { delete(bestPath);}


template<class T>
std::vector<std::string> DepthFirstSearch<T>::search(Searchable<T> *searchable) {
    open.push(searchable->getInitialState());
    std::unordered_map<std::string,State<T>*> closed;
    double currentCost;
    while (!open.empty()) {
        State<T>* node = this->open.top();
        open.pop();
        evaluatedNodes++;
        closed.insert({node->toString(),node});
        if(searchable->isGoalState(node)) {
            Path<T>* sol = new Path<T>(node);
            return sol ->getPath();
        }
        std::list<State<T>*> neighbors = searchable->getAllPossibleStates(node);
        for(State<T>* state : neighbors) {
            if(state == NULL || state->getCost() == -1) {
                continue;
            }
            if(closed.find(state->toString()) == closed.end() && !isInOpen(state)) {
                state->setWhereFrom(node);
                open.push(state);
            }
        }
    }
    std::cerr<<"no path found"<<endl;
}

template <class T>
bool DepthFirstSearch<T>::isInOpen(State<T>* state) {
    std::stack<State<T> *> temp;
    bool find = false;
    while (!open.empty() && !open.top()->Equal(state) && !find) {
        if (!state->Equal(open.top())) {
            temp.push(open.top());
            open.pop();
        } else find = true;
    }
    while (!temp.empty()) {
        open.push(temp.top());
        temp.pop();
    }
    return find;
}

template <class T>
int DepthFirstSearch<T>::numOfNodesEvaluated() { return evaluatedNodes; }

template <class T>
void DepthFirstSearch<T>::resetnodes() { evaluatedNodes = 0;}

template <class T>
void DepthFirstSearch<T>::update(State<T> *state) {
    stack<State<T>*> temp;
    while(!state->Equal(open.top())) {
        temp.push(open.top());
        open.pop();
    }
    open.pop();
    while(!temp.empty()) {
        open.push(temp.top());
        temp.pop();
    }
    open.push(state);
}


//-----------------------------------------------------------------------------
class AlgorithemsTesting {
    int evaluatedNodes[4][10];

public:
    void testall();
};

void AlgorithemsTesting::testall()  {
    string filename = "matrix",type = ".txt";
    vector<vector<double>> matrixex;
    for(int i = 1; i <= 10 ; i++) {
        std::ifstream file("matrix"+ to_string(i) +".txt", std::ios::in);
        if (!file)
            cerr << "no file" << endl;
        vector<double> costs;
        string line;
        while (getline(file, line)) {
            string val = "";
            for (int j = 0; j < line.length(); j++) {
                char c = line[j];
                if (c == ' ' || c == ',') {
                    if (val.length() > 0) {
                        costs.push_back(stod(val));
                        val = "";
                    } else continue;
                } else {
                    val += c;
                }
            }
            if(val == "end")
                break;
            if (val.length() > 0)
                costs.push_back(stod(val));
        }
        matrixex.push_back(costs);
    }

    //testing Astar
    ofstream fileA("Astar.txt",ios::out);
    Searcher<pair<int,int>,AStarComperator<pair<int,int>>> *searcherA;
    for(int i = 0; i < matrixex.size() ; i++) {
        searcherA = new AStar<pair<int,int>>();
        vector<string> As = searcherA->search(new Matrix(matrixex[i]));
        evaluatedNodes[0][i] = searcherA->numOfNodesEvaluated();
        searcherA->resetnodes();
        if(fileA) {
            fileA<<"size: "<<matrixex[i].back()<<" ";
            for(string side : As) {
                fileA<<side<<",";
            }
            fileA<<"\n";
        }
    }
    ofstream fileBf("BestFirstSearch.txt",ios::out);
    //testing best-first-search
    for(int i = 0; i < matrixex.size() ; i++) {
        Searcher<pair<int,int>,BestFirstSearchComperator<pair<int,int>>> *searcherBe = new BestFirstSearch<pair<int,int>>();
        vector<string> Bf = searcherBe->search(new Matrix(matrixex[i]));
        evaluatedNodes[1][i] = searcherBe->numOfNodesEvaluated();
        searcherBe->resetnodes();
        if(fileBf) {
            fileBf<<"size: "<<matrixex[i].back()<<" ";
            for(string side : Bf) {
                fileBf<<side<<",";
            }
            fileBf<<"\n";
        }
    }
    ofstream fileBFS("BFS.txt",ios::out);
    for(int i = 0; i < matrixex.size() ; i++) {
        ISearcher<pair<int,int>,vector<string>> *searcherBFS = new BreadthFirstSearch<pair<int,int>>();
        vector<string> Bfs = searcherBFS->search(new Matrix(matrixex[i]));
        evaluatedNodes[2][i] = searcherBFS->numOfNodesEvaluated();
        searcherBFS->resetnodes();
        if(fileBFS) {
            fileBFS<<"size: "<<matrixex[i].back()<<" ";
            for(string side : Bfs) {
                if(side.length() > 0)
                    fileBFS<<side<<",";
            }
            fileBFS<<"\n";
        }
    }
    ofstream fileDFS("DFS.txt",ios::out);
    for(int i = 0; i < matrixex.size() ; i++) {
        ISearcher<pair<int,int>,vector<string>> *searcherDFS = new DepthFirstSearch<pair<int,int>>();
        vector<string> Dfs = searcherDFS->search(new Matrix(matrixex[i]));
        evaluatedNodes[3][i] = searcherDFS->numOfNodesEvaluated();
        searcherDFS->resetnodes();
        if(fileDFS) {
            fileDFS<<"size: "<<matrixex[i].back()<<" ";
            for(string side : Dfs) {
                fileDFS<<side<<",";
            }
            fileDFS<<"\n";
        }
    }
    cout<<"num in Astar :";
    for(int i = 0; i < 10; i++) {
        cout<<" in matrix "<<i + 1<<" : " <<evaluatedNodes[0][i];
    }

    cout<<endl<<"num in BestFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" in matrix "<<i + 1<<": " << evaluatedNodes[0][i];
    }

    cout<<endl<<"num in BFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" in matrix "<<i + 1<< " : " <<evaluatedNodes[0][i];
    }

    cout<<endl<<"num in DFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" in matrix "<<i + 1<< " : " <<evaluatedNodes[0][i];
    }

}


//-----------------------------------------------------------------------------
template<class Solution, class Problem>
class CacheManager {
public:
    virtual bool Find(Problem problem) = 0;
    virtual Solution get(Problem problem) = 0;
    virtual void save(Problem problem, Solution solution) = 0;
};




//-----------------------------------------------------------------------------
class ClientHandler {
public:
    virtual void handleClient(int input, int output) = 0;
    virtual ClientHandler* clone() = 0;
};


//-----------------------------------------------------------------------------
    class Server {
    protected:
        int _server_socket;

    public:
        virtual void open(int port, ClientHandler *cm) = 0;

        virtual void stop() = 0;
    };




//-----------------------------------------------------------------------------
class FileCacheManager  : public CacheManager<string,string> {
    unordered_map<string,string> solutions;
    static FileCacheManager *fileCacheManager;
    FileCacheManager();
public:
    static FileCacheManager* getFileCacheManager();
    bool Find(string problem) override ;
    string get(string problem) override ;
    void save(string problem,string solution) override ;
};

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
    hash<string> hasher;
    return (solutions.find(to_string(hasher(problem)))!=solutions.end());
}

/**
 * save the solution to a problem in a file
 * @param solution
 * @param problem
 */
void FileCacheManager::save(string solution, string problem) {
    hash<string> hasher;
    size_t problem_hash = hasher(problem);
    fstream file;
    file.open(to_string(problem_hash),ios::out);
    if(!file){
        throw "no file been opened";
    }
    file<<solution<<endl;
    file.close();
    if(!Find(to_string(problem_hash))) {
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
        hash<string> hasher;
        fstream file;
        file.open(to_string(hasher(problem)),ios::in);
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


//-----------------------------------------------------------------------------
template<class Solution,class Problem>
class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};


//-----------------------------------------------------------------------------
template <class T,class Solution,class Problem>
class SolverSearch : public Solver<Solution,Problem> {
ISearcher<T,Solution>* _searcher;
public:
    SolverSearch(ISearcher<T,Solution>* searcher);
    Solution solve(Problem problem) override ;
};

template <class T,class Solution,class Problem>
SolverSearch<T,Solution,Problem>::SolverSearch(ISearcher<T, Solution> *searcher) {
    this->_searcher = searcher;
}

template <class T,class Solution,class Problem>
Solution SolverSearch<T, Solution, Problem>::solve(Problem problem) {
    return _searcher->search(problem);
}


//-----------------------------------------------------------------------------
class MySerialServer  : public Server {
        bool openConnection = false;
public:
    MySerialServer();
    void open(int port, ClientHandler *cm) override ;
    void stop() override ;
};


void callHandler(ClientHandler *cm,int input, int output) {
    ClientHandler *cm_new = cm->clone();
    cm_new->handleClient(input, output);
}

void handleClients(int server_sock, sockaddr_in addr,ClientHandler* cm) {
    //initiating timeout
    struct timeval tv;
    tv.tv_sec = 2*60;
    setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    while(true) {
        //listening and waiting to connect request
        if (listen(server_sock, 10) == -1) {
            continue;
        }
        //connecting to client
        int client_socket = accept(server_sock, (struct sockaddr *) &addr, (socklen_t *) &addr);
        if (client_socket == -1) {
            break;
        }
        //new thread to handle client
        std::thread handle(callHandler,cm,client_socket, client_socket);
        handle.join();
        close(client_socket);

    }
}

MySerialServer::MySerialServer() {}

void MySerialServer::open(int port, ClientHandler *cm) {
    int server_socket;
    //creating a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        throw "couldn't creat socket";
    }
    //binding the socket to given port
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr<<"couldn't bind";
    }
    _server_socket = server_socket;
    //initiating timeout
    struct timeval tv;
    tv.tv_sec = 2*60;
    setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

        //listening and waiting to connect request
        if (listen(server_socket, 10) == -1) {
            cerr<<"couldn't listen";
        }
        this -> openConnection = true;
        while(this->openConnection) {
            //connecting to client
            int client_socket = accept(server_socket, (struct sockaddr *) &address, (socklen_t *) &address);
            if (client_socket == -1) {
                break;
            }
            //new thread to handle client
            std::thread handle(callHandler, cm, client_socket, client_socket);
            handle.join();
            close(client_socket);
        }
    stop();
}

void MySerialServer::stop() {
    mutex().lock();
    this -> openConnection = false;
    mutex().unlock();
    close(_server_socket);
}

//-----------------------------------------------------------------------------

class MyParallelServer : public Server {
    list<thread*> listOfClients;
    bool openConnection = false;
    int allocatedPort;
public:
    void open(int  port,  ClientHandler* cm) override ;
    void stop() override ;
};

void MyParallelServer::open(int port, ClientHandler *cm) {
    this->allocatedPort = port;
    int socketIdentity = socket(AF_INET, SOCK_STREAM, 0);
    _server_socket = socketIdentity;
    int clientSocket; // Serves us in the while loop.
    if (socketIdentity == -1) {
        cerr<<"couldn't creat socket";
    }
    struct timeval timeValue;
    timeValue.tv_sec = 120; //Two minutes
    struct sockaddr_in socketAddress;
    socketAddress.sin_addr.s_addr = INADDR_ANY;
    socketAddress.sin_family = AF_INET;
    socketAddress.sin_port = htons(port);
    int lengthOfAddress = sizeof(socketAddress);
    if(bind(socketIdentity, (struct sockaddr*) &socketAddress, sizeof(socketAddress)) == -1) {
        exit (1);
    }
    setsockopt(socketIdentity, SOL_SOCKET, SO_RCVTIMEO,
               (const char*)&timeValue, sizeof timeValue);
    if(listen(socketIdentity, 10) == -1) {
        cerr<<"couldn't listen";
    }
    this -> openConnection = true;
    while (this -> openConnection == true) {
        clientSocket = accept(socketIdentity, (struct sockaddr*) &socketAddress,
                              (socklen_t*) &lengthOfAddress);
        if(clientSocket == -1) {
            cerr<<"couldn't connect";
        }
        listOfClients.push_back(new thread(callHandler,cm, clientSocket, clientSocket));
    }
    list<thread*> variables = list<thread*> (listOfClients);
    for (auto variablesIterator : variables) {
        variablesIterator -> join();
        listOfClients.remove(variablesIterator);
    }
    this->stop();
}
void MyParallelServer::stop() {
    mutex().lock();
    this -> openConnection = false;
    mutex().unlock();
    close(_server_socket);
}



//-----------------------------------------------------------------------------
class MyTestClientHandler : public ClientHandler {
    Solver<string,string> *_solver;
    CacheManager<string,string> *_cm;
public:
    MyTestClientHandler(Solver<string ,string > *solver, CacheManager<string ,string > *cm);
    void handleClient(int input, int output) override ;
    ClientHandler* clone() override ;
    ~MyTestClientHandler();
};



MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cm) {
    _solver = solver;
    _cm = cm;
}

MyTestClientHandler::~MyTestClientHandler() {
    delete(_cm);
    delete(_solver);
}

ClientHandler * MyTestClientHandler::clone() {
    return new MyTestClientHandler(_solver,_cm);
}

void MyTestClientHandler::handleClient(int input, int output) {
    std::string problem = "";
    do {
        problem = "";
        char buffer[1024];
        int valread = read(input, buffer, 1024);
        for (int i = 0; i < 1024; i++) {
            if (buffer[i] == EOF) {
                break;
            }
            problem += buffer[i];
        }
        if (_cm->Find(problem)) {
            std::string solution = _cm->get(problem);
            send(output, solution.c_str(), solution.length(), 0);
        } else {
            std::string solution = _solver->solve(problem);
            send(output, solution.c_str(), solution.length(), 0);
            _cm->save(solution,problem);
        }
    } while (problem.compare("end") != 0);
}


//-----------------------------------------------------------------------------

class MyClientHandler : public ClientHandler {
    Solver<vector<string>,Matrix*> *_solver;
    CacheManager<string,string> *_cm;
public:
    MyClientHandler(Solver<vector<string>,Matrix*> *solver, CacheManager<string, string> *cm);
    ClientHandler* clone() override;
    void handleClient(int input, int output) override;
    ~MyClientHandler();
};

MyClientHandler::MyClientHandler(Solver<vector<string>,Matrix*> *solver, CacheManager<string, string> *cm) {
    _solver = solver;
    _cm =cm;
}

ClientHandler * MyClientHandler::clone() { return new MyClientHandler(_solver,_cm); }

MyClientHandler::~MyClientHandler() {
    delete(_solver);
    delete(_cm);
}

void MyClientHandler::handleClient(int input, int output) {
    vector<string> problemLines;
    std::string problem = "";
    do {
        problem = "";
        char buffer[1024];
        int valread = read(input, buffer, 1024);
        for (int i = 0; i < 1024; i++) {
            if (buffer[i] == EOF) {
                if(problem.length() == 0)
                    break;
                problemLines.push_back(problem);
                problem = "";
                break;
            }
            problem += buffer[i];
        }
    } while (problem.compare("end") != 0);
    problem = "";
    for(string line : problemLines)
        problem += line;
    if (_cm->Find(problem)) {
        std::string solution = _cm->get(problem);
        send(output, solution.c_str(), solution.length(), 0);
    } else {
        string val = "";
        vector<double> costs;
        for(const char c : problem) {
            if(c == ',' || c==' ') {
                if(val.length() == 0)
                    continue;
                costs.push_back(stod(val));
                val = "";
            }
            else val += c;
            if(val.length() > 0)
                costs.push_back(stod(val));
        }
        vector<string> sol = _solver->solve(new Matrix(costs));
        string solution = "";
        for(string side: sol)
            solution = solution + side + ",";
        send(output, solution.c_str(), solution.length(), 0);
        _cm->save(solution,problem);
    }

}

//-----------------------------------------------------------------------------
class StringReverser : public Solver<string,string> {
public:
    StringReverser();
    string solve(string problem) override;

};

StringReverser::StringReverser() {}

string StringReverser::solve(string problem) {
    string reverse = "";
    for(int i = problem.length() - 1; i >= 0; i--) {
        reverse += problem[i];
    }
    return reverse;
}
//-----------------------------------------------------------------------------
namespace boot {
    class Main {
    public:
        int main(int argc, char **args);
    };

    int Main::main(int argc, char **args) {
        ClientHandler *clientHandler = new MyTestClientHandler(new StringReverser(),
                                                               FileCacheManager::getFileCacheManager());
        Server *server = new MySerialServer();
        server->open(stoi(args[0]), clientHandler);
        return 1;
    }
}
//-------------------------------------------------------------------------------

int main(int argc, char** argv) {
    test->testall();
    Server* server = new MyParallelServer();
    ISearcher<pair<int,int>,vector<string>>* searcher = new AStar<pair<int, int>>();
    Solver<vector<string>,Matrix*>* adapter = new SolverSearch<pair<int,int>,vector<string>,Matrix*>(searcher);
    CacheManager<string,string>* cm = FileCacheManager::getFileCacheManager();
    MyClientHandler* handler = new MyClientHandler(adapter,cm);

    //cout << "started server" << endl;
    if(argc>=2)
        server->open(atoi(argv[1]), handler);
    else
        server->open(5600, handler);
    //5State<int> state;
    //MyPriorityQueue<int> queue();
    //server->open(5600, handle);

    return 0;
}