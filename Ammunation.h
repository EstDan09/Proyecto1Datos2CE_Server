//
// Created by dadu on 02/04/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_AMMUNATION_H
#define PROYECTO1DATOS2CE_SERVER_AMMUNATION_H

#include "Bullet.h"
#include "BulletCollector.h"
class Ammunation {
public:
    Ammunation();
    ~Ammunation();
    BulletCollector bulletCollector;
    Bullet *getHead() const;
    void setHead(Bullet *nHead);
    int getQuantity() const;
    void setQuantity(int nQuantity);
    void insertBullets(int num, int damage);
    void noImpact(Bullet* nBullet);
    void impact();
private:
    int quantity;
    Bullet* head;
};



#endif //PROYECTO1DATOS2CE_SERVER_AMMUNATION_H
