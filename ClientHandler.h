//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_CLIENTHANDLER_H
#define MILD2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int input, int output) = 0; //Handling the clinet
    virtual ClientHandler* clone() = 0; // Since I need to use a few clients parallely, I required a method that clone my clientHandle
};


#endif //MILD2_CLIENTHANDLER_H
