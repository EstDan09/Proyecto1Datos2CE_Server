//
// Created by esteban on 3/29/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_BULLET_H
#define PROYECTO1DATOS2CE_SERVER_BULLET_H


class Bullet {
public:
    Bullet(int dam);
    ~Bullet();
    bool getRecycled() const;
    bool getDirection() const;
    Bullet* getNextPtr() const;
    void setNextPtr(Bullet* next);
    void setRecycled(bool nCondition);
    void setDirection(bool nDirection);
    Bullet* next;
private:
    bool recycled;
    bool direction;

};


#endif //PROYECTO1DATOS2CE_SERVER_BULLET_H
