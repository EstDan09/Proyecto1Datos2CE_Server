//
// Created by esteban on 3/29/23.
//

#include "Bullet.h"

Bullet::Bullet(int dam) {
    Bullet::recycled = false;
    Bullet::next = nullptr;
}
Bullet::~Bullet(){}

bool Bullet::getRecycled() const {
    return recycled;
}
bool Bullet::getDirection() const {
    return direction;
}
Bullet* Bullet::getNextPtr() const {
    return next;
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
