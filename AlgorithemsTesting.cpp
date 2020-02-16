//
// Created by grufix on 15/02/2020.
//

#include "AlgorithemsTesting.h"

void AlgorithemsTesting::testall()  {
    string filename = "matrix",type = ".txt";
    vector<double> matrixex[10];
    for(int i = 1; i <= 10 ; i++) {
        std::ifstream file("matrix1.txt", std::ios::in);
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
            if (val.length() > 0)
                costs.push_back(stod(val));
        }
        matrixex[i] = costs;
    }

    //testing Astar
    Searcher<pair<int,int>,AStarComperator<pair<int,int>>> *searcherA = new AStar<pair<int,int>>();
    for(int i = 0; i < matrixex->size() ; i++) {
        vector<string> As = searcherA->search(new Matrix(matrixex[i]));
        evaluatedNodes[0][i] = searcherA->numOfNodesEvaluated();
    }
    //testing best-first-search
    Searcher<pair<int,int>,BestFirstSearchComperator<pair<int,int>>> *searcherBe = new BestFirstSearch<pair<int,int>>();
    for(int i = 0; i < matrixex->size() ; i++) {
        vector<string> As = searcherBe->search(new Matrix(matrixex[i]));
        evaluatedNodes[1][i] = searcherBe->numOfNodesEvaluated();
    }
    ISearcher<pair<int,int>,vector<string>> *searcherBFS = new BreadthFirstSearch<pair<int,int>>();
    for(int i = 0; i < matrixex->size() ; i++) {
        vector<string> As = searcherBFS->search(new Matrix(matrixex[i]));
        evaluatedNodes[2][i] = searcherBFS->numOfNodesEvaluated();
    }
    ISearcher<pair<int,int>,vector<string>> *searcherDFS = new DepthFirstSearch<pair<int,int>>();
    for(int i = 0; i < matrixex->size() ; i++) {
        vector<string> As = searcherDFS->search(new Matrix(matrixex[i]));
        evaluatedNodes[3][i] = searcherDFS->numOfNodesEvaluated();
    }
    cout<<"num in Astar :";
    for(int i = 0; i < 10; i++) {
        cout<<" "<<matrixex[0][i];
    }
    cout<<endl<<"num in BestFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" "<<matrixex[1][i];
    }
    cout<<endl<<"num in BFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" "<<matrixex[2][i];
    }
    cout<<endl<<"num in DFS :";
    for(int i = 0; i < 10; i++) {
        cout<<" "<<matrixex[3][i];
    }
}