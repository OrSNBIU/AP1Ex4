//
// Created by grufix on 25/01/2020.
//

#include "StringReverser.h"

StringReverser::StringReverser() {}

string StringReverser::solve(string problem) {
    string reverse = "";
    for(int i = problem.length() - 1; i >= 0; i--) { //Reversing the string using a reversed loop.
        reverse += problem[i];
    }
    return reverse;
}
