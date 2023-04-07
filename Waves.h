//
// Created by dadu on 02/04/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_WAVES_H
#define PROYECTO1DATOS2CE_SERVER_WAVES_H
#include "ShipEnemy.h"

class Waves {
public:
    Waves();

    ~Waves();

    ShipEnemy* head;

    ShipEnemy *getHead();

    void setHead(ShipEnemy *nHead);

    void insertShips(int numShips);

    void colShip(int rCode, int damage);

    int getGenDamage();

    void setGenDamage(int genDamage);

private:
    int genDamage;
};



#endif //PROYECTO1DATOS2CE_SERVER_WAVES_H
