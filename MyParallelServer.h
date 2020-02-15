//
// Created by orsn on 15/02/2020.
//

#ifndef EX4290120_MYPARALLELSERVER_H
#define EX4290120_MYPARALLELSERVER_H

#include <thread>
#include <list>
#include <bits/socket.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


using namespace std;
using namespace std::chrono;
class ClientHandlerInterface {
public:
    virtual int handleTheClient(int clientSocket) = 0;
};

class ServerInterface {
private:
    int portNumber;
public:
    virtual int openServer(int portNumber, ClientHandlerInterface* client) = 0;
    virtual int closeTheServer() = 0;
};
class MyParallelServer {
private:
    list<thread*> listOfClients;
    bool openConnection = false;
    int allocatedPort;
public:
    int openServer(int  port,  ClientHandlerInterface* clientHandler) {
        this->allocatedPort = port;
        int socketIdentity = socket(AF_INET, SOCK_STREAM, 0);
        int clientSocket; // Serves us in the while loop.
        if (socketIdentity == -1) {
            throw ("Error: We couldn't open the server using the given socket");
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
            throw("Error: Listening Parallel Server failed.");
        }
        this -> openConnection = true;
        while (this -> openConnection == true) {
            clientSocket = accept(socketIdentity, (struct sockaddr*) &socketAddress,
                    (socklen_t*) &lengthOfAddress);
            if(clientSocket == -1) {
                throw("Error: Connection to Client-Socket Serial Server failed, or took too long to respond.");
            }
            listOfClients.push_back(new thread(&ClientHandlerInterface::handleTheClient, clientHandler, clientSocket));
        }
        list<thread*> variables = list<thread*> (listOfClients);
        for (auto variablesIterator : variables) {
            variablesIterator -> join();
            listOfClients.remove(variablesIterator);
        }
        this->closeServer();
        close(socketIdentity);
    }
    int closeServer() {
        this -> openConnection = false;
        return 0;
    }
};




#endif //EX4290120_MYPARALLELSERVER_H
