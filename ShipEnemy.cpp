//
// Created by dadu on 02/04/23.
//

#include "ShipEnemy.h"

ShipEnemy *ShipEnemy::getNextEnemy() const {
    return nextEnemy;
}

void ShipEnemy::setNextEnemy(ShipEnemy *nextEnemy) {
    ShipEnemy::nextEnemy = nextEnemy;
}

int ShipEnemy::getVida() const {
    return vida;
}

void ShipEnemy::setVida(int cVida) {
    ShipEnemy::vida = cVida;
}

bool ShipEnemy::isAlive() const {
    return alive;
}

void ShipEnemy::setAlive(bool cAlive) {
    ShipEnemy::alive = cAlive;
}
std::string ShipEnemy::getPatreon(){
    return patreon;
}

void ShipEnemy::setPatreon(const std::string nPatreon) {
    ShipEnemy::patreon = nPatreon;
}
std::string ShipEnemy::getColour() {
    return colour;
}
void ShipEnemy::setColour(std::string nColour){
    ShipEnemy::colour = nColour;
}