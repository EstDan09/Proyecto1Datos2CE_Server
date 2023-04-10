//
// Created by esteban on 3/29/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_BULLET_H
#define PROYECTO1DATOS2CE_SERVER_BULLET_H


class Bullet {
public:
    Bullet();
    ~Bullet();
    bool getRecycled() const;
    Bullet* getNextPtr() const;
    void setNextPtr(Bullet* next);
    void setRecycled(bool nCondition);
    Bullet* next;
private:
    bool recycled;


};


#endif //PROYECTO1DATOS2CE_SERVER_BULLET_H
