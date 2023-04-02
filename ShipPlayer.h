//
// Created by dadu on 02/04/23.
//
#include <iostream>
#include "Bullet.h"
#ifndef PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H
#define PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H


class ShipPlayer {
public:
    ShipPlayer();

    ~ShipPlayer();

    int getVida() const;

    void setVida(int vida);

    const std::string &getSelecPower() const;

    void setSelecPower(const std::string &selecPower);

    bool isAlive() const;

    void setAlive(bool alive);

    Bullet *getHead() const;

    void setHead(Bullet *head);



private:
    int vida;
    std::string selecPower;
    bool alive;
    Bullet* head;

};


#endif //PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H
