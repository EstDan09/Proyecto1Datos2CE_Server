//
// Created by dadu on 02/04/23.
//
#include <iostream>
#include "Bullet.h"
#include "Ammunation.h"
#ifndef PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H
#define PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H


class ShipPlayer {
public:
    ShipPlayer(int vida);

    ~ShipPlayer();

    int getVida() const;

    void setVida(int cVida);

    const std::string &getSelecPower() const;

    void setSelecPower(const std::string nSelecPower);

    bool isAlive() const;

    void setAlive(bool cAlive);
    Ammunation ammunation;
private:
    int vida;
    std::string selecPower;
    bool alive;

};


#endif //PROYECTO1DATOS2CE_SERVER_SHIPPLAYER_H
