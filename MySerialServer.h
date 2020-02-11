//
// Created by grufix on 25/01/2020.
//

#ifndef MILD2_MYSERIALSERVER_H
#define MILD2_MYSERIALSERVER_H


#include "Server.h"


class MySerialServer : public Server {
public:
    MySerialServer();
    void open(int port, ClientHandler *cm) override ;
    void stop() override ;
};


#endif //MILD2_MYSERIALSERVER_H
