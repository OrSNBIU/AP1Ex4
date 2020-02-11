//
// Created by grufix on 25/01/2020.
//

#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

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