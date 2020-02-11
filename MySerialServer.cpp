//
// Created by grufix on 25/01/2020.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <unistd.h>
#include "MySerialServer.h"

void callHandler(ClientHandler *cm,int input, int output) {
    ClientHandler *cm_new = cm->clone();
    cm_new->handleClient(input, output);
}

void handleClients(int server_sock, sockaddr_in addr,ClientHandler* cm) {
    //initiating timeout
    struct timeval tv;
    tv.tv_sec = 2*60;
    setsockopt(server_sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    while(true) {
        //listening and waiting to connect request
        if (listen(server_sock, 10) == -1) {
            continue;
        }
        //connecting to client
        int client_socket = accept(server_sock, (struct sockaddr *) &addr, (socklen_t *) &addr);
        if (client_socket == -1) {
            break;
        }
        //new thread to handle client
        std::thread handle(callHandler,cm,client_socket, client_socket);
        handle.join();
        close(client_socket);

    }
}

MySerialServer::MySerialServer() {}

void MySerialServer::open(int port, ClientHandler *cm) {
    int server_socket;
    //creating a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        throw "couldn't creat socket";
    }
    //binding the socket to given port
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "coukdn't bind";
    }
    _server_socket = server_socket;
    /*
     * std::thread handle(handleClient,server_socket,address,cm);
     * handle.join;
     * stop(server_socket)
     */
    //initiating timeout
    struct timeval tv;
    tv.tv_sec = 2*60;
    setsockopt(server_socket, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
    while(true) {
        //listening and waiting to connect request
        if (listen(server_socket, 10) == -1) {
            continue;
        }
        //connecting to client
        int client_socket = accept(server_socket, (struct sockaddr *) &address, (socklen_t *) &address);
        if (client_socket == -1) {
            break;
        }
        //new thread to handle client
        std::thread handle(callHandler,cm,client_socket, client_socket);
        handle.join();
        close(client_socket);
    }
    stop();
}

void MySerialServer::stop() {
    close(_server_socket);
}