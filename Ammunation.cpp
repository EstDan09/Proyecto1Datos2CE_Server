//
// Created by dadu on 02/04/23.
//

#include "Ammunation.h"
Ammunation::Ammunation(){
    Ammunation::quantity=0;
    Ammunation::bulletCollector = BulletCollector();
    Ammunation::head = nullptr;

}
Ammunation::~Ammunation(){}

Bullet *Ammunation::getHead() const {
    return head;
}

void Ammunation::setHead(Bullet *nHead) {
    Ammunation::head = nHead;
}

int Ammunation::getQuantity() const {
    return quantity;
}

void Ammunation::setQuantity(int nQuantity) {
    Ammunation::quantity = nQuantity;
}

void Ammunation::insertBullets(int num, int damage) {
    if (getQuantity() ==0 && num==1){
        Ammunation::setHead(new Bullet(damage));
        quantity++;
    }
    else if (getQuantity()==0 && num!=1){
        Ammunation::setHead(new Bullet(damage));
        quantity++;
        for(int i = 1; i<num;i++){
            Bullet* nBullet = new Bullet(damage);
            nBullet->setNextPtr(head);
            head = nBullet;
            quantity++;
        }
    }
    else{
        for(int i = 0; i<num;i++){
            Bullet* nBullet = new Bullet(damage);
            nBullet->setNextPtr(head);
            head = nBullet;
            quantity++;
        }
    }
}
void Ammunation::noImpact(Bullet *nBullet) {
    Ammunation::bulletCollector.insertF(nBullet);
}
void Ammunation::impact(){
    if ( head->getNextPtr() == nullptr){
        head = nullptr;
    }
    else{
        Bullet* tmp = head;
        head = head->next;
        delete tmp;
    }
}
