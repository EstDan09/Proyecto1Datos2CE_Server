//
// Created by esteban on 3/29/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_BULLET_H
#define PROYECTO1DATOS2CE_SERVER_BULLET_H


class Bullet {
public:
    Bullet(int dam);
    ~Bullet();
    int getDamage() const;
    bool getRecycled() const;
    bool getDirection() const;
    Bullet* getNext() const;
    void setNext(Bullet* next);
    void setDamage(int nDamage);
    void setRecycled(bool nCondition);
    void setDirection(bool nDirection);
private:
    int damage;
    bool recycled;
    bool direction;
    Bullet* next;
};


#endif //PROYECTO1DATOS2CE_SERVER_BULLET_H
