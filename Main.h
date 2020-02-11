//
// Created by grufix on 28/01/2020.
//

#ifndef MILD2_MAIN_H
#define MILD2_MAIN_H


#include "ClientHandler.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "FileCacheManager.h"

class Main {
public:
    void main(char** args) {
        ClientHandler *clientHandler = new MyTestClientHandler( new StringReverser(), FileCacheManager::getFileCacheManager() );
        Server *server = new MySerialServer();
        server->open(stoi(args[0]),clientHandler);
    }
};


#endif //MILD2_MAIN_H
