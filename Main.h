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
        //Creates a new static instance of *clientHandler with a dynamic type of MyTestClientHandler.
        Server *server = new MySerialServer();
        //Creates a new static instance of *server with a dynamic type of MySerialServer.
        server->open(stoi(args[0]),clientHandler);
        //Calling open method using value given in the arguments.
    }
};


#endif //MILD2_MAIN_H
