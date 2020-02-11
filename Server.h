//
// Created by grufix on 25/01/2020.
//
//Header file for Server class
#ifndef MILD2_SERVER_H
#define MILD2_SERVER_H

#include "ClientHandler.h"

class Server {
    protected:
        int _server_socket;

    public:
        virtual void open(int port, ClientHandler *cm) = 0;
        virtual void stop() = 0;
    };

#endif //MILD2_SERVER_H
