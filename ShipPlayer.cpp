//
// Created by dadu on 02/04/23.
//

#include "ShipPlayer.h"

ShipPlayer::ShipPlayer() {}
ShipPlayer::~ShipPlayer() {}

int ShipPlayer::getVida() const {
    return vida;
}

void ShipPlayer::setVida(int vida) {
    ShipPlayer::vida = vida;
}

const std::string &ShipPlayer::getSelecPower() const {
    return selecPower;
}

void ShipPlayer::setSelecPower(const std::string &selecPower) {
    ShipPlayer::selecPower = selecPower;
}

bool ShipPlayer::isAlive() const {
    return alive;
}

void ShipPlayer::setAlive(bool alive) {
    ShipPlayer::alive = alive;
}

Bullet *ShipPlayer::getHead() const {
    return head;
}

void ShipPlayer::setHead(Bullet *head) {
    ShipPlayer::head = head;
}



