#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "Strategys.h"
#include "ShipPlayer.h"
#include "InGame.h"
using namespace std;
string solve(bool input){
    if (input == 0){
        return "false";
    }
    if (input == 1){
        return "verdadero";
    }
}
int main()
{
    /*
    Strategys strategys;
    ShipPlayer shipPlayer(100);
    shipPlayer.ammunation.setDamage(20);
    Waves waves;
    waves.setGenDamage(5);
    cout<<strategys.activateP(2,shipPlayer.getVida(),shipPlayer.ammunation.getDamage(),waves.getGenDamage(),100)<<endl;
    cout<<strategys.activateP(2,shipPlayer.getVida(),shipPlayer.ammunation.getDamage(),waves.getGenDamage(),100)<<endl;
    cout<<strategys.deactivateP(2)<<endl;
     */



    ShipPlayer* shipPlayer = new ShipPlayer(100);

    shipPlayer->ammunation->insertBullets(2);

    InGame* inGame = new InGame();

    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return -1;
    }

// Bind the ip address and port to a socket
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr*)&hint, sizeof(hint));

// Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);

// Wait for a connection
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

    char host[NI_MAXHOST];      // Client's remote name
    char service[NI_MAXSERV];   // Service (i.e. port) the client is connect on

    memset(host, 0, NI_MAXHOST); // same as memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

// Close listening socket
    close(listening);

// While loop: accept and echo message back to client
    char buf[4096];



    while (true)
    {

        memset(buf, 0, 4096);

// Wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        string recibido = string(buf, 0, bytesReceived);

        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }

        if(recibido=="C"){
            shipPlayer->setVida(shipPlayer->getVida()-inGame->getCurrentWave()->getGenDamage());
            string response = solve(shipPlayer->isAlive());
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }
        if (recibido.substr(0)=="A"){
            string response;
            if(shipPlayer->ammunation->getQuantity()>0) {
                shipPlayer->ammunation->impact();
                if (inGame->getCurrentWave()->colShip(stoi(recibido.substr(1, 2)),shipPlayer->ammunation->getDamage())) {
                    response = "No destruido";
                }
                else {
                    response = "destruido";
                }
            }
            else{
                shipPlayer->ammunation->bulletCollector->deleteF();
                if (inGame->getCurrentWave()->colShip(stoi(recibido.substr(1, 2)),shipPlayer->ammunation->bulletCollector->getDamage())) {
                    response = "No destruido";
                }
                else {
                    response = "destruido";
                }
            }
            //string response = "Start";
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }
        if(recibido=="E"){
           string response = solve(inGame->checkNextW());
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }
        if(recibido=="D"){
            if(shipPlayer->ammunation->getQuantity()>0){
                shipPlayer->ammunation->noImpact();
            }
        }
        if(recibido=="W"){
            bool value = false;
            if(shipPlayer->ammunation->getQuantity()>0 or shipPlayer->ammunation->bulletCollector->getQuantity()>0){
                value = true;
            }
            string response = solve(value);
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }
        if(recibido=="S"){
            string response = to_string(shipPlayer->ammunation->getQuantity());
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }
        if (string(buf, 0, bytesReceived) == "adios"){
            string response = "End";
            send(clientSocket, response.c_str(), response.size() + 1, 0);
        }

        cout << string(buf, 0, bytesReceived) << endl;

// Echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0);
    }

// Close the socket
    close(clientSocket);

    return 0;
}
