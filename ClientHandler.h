//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_CLIENTHANDLER_H
#define MILD2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int input, int output) = 0;
    virtual ClientHandler* clone() = 0;
};


#endif //MILD2_CLIENTHANDLER_H
