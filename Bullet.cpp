//
// Created by esteban on 3/29/23.
//

#include "Bullet.h"

Bullet::Bullet(int dam) {
    Bullet::damage = dam;
    Bullet::recycled = false;
    Bullet::next = nullptr;
}
Bullet::~Bullet(){}

int Bullet::getDamage() const {
    return damage;
}

bool Bullet::getRecycled() const {
    return recycled;
}
bool Bullet::getDirection() const {
    return direction;
}
Bullet* Bullet::getNextPtr() const {
    return next;
}
void Bullet::setDamage(int nDamage) {
    Bullet::damage = nDamage;
}
void Bullet::setRecycled(bool nCondition) {
    Bullet::recycled = nCondition;
}
void Bullet::setDirection(bool nDirection) {
    Bullet::direction = nDirection;
}
void Bullet::setNextPtr(Bullet *next) {
    Bullet::next = next;
}
