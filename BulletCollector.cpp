//
// Created by dadu on 02/04/23.
//

#include "BulletCollector.h"
#include <iostream>
using namespace std;
BulletCollector::BulletCollector()  {
    BulletCollector::cHeadPtr = nullptr;
    BulletCollector::quantity = 0;
}

int BulletCollector::getQuantity() const {
    return quantity;
}

void BulletCollector::setQuantity(int nQuantity) {
    BulletCollector::quantity = nQuantity;
}

void BulletCollector::insertF(Bullet* x){
    if (cHeadPtr == nullptr){
        cHeadPtr = x;
        if(!x->getRecycled()) {
            cHeadPtr->setDamage((x->getDamage()) / 2);
            quantity ++;
        }
        else{
            cHeadPtr->setDamage((x->getDamage()));
            quantity ++;
        }
        cHeadPtr->setNextPtr(nullptr);
    }
    else{
        x->setNextPtr(cHeadPtr); //aca
        cHeadPtr= x;
        if(!x->getRecycled()) {
            cHeadPtr->setDamage((x->getDamage()) / 2);
        }
        else{
            cHeadPtr->setDamage((x->getDamage()));
        }
    }
}
void BulletCollector::deleteF(){
    if ( cHeadPtr->getNextPtr() == nullptr){
        cHeadPtr = nullptr;
    }
    else{
        Bullet* tmp = cHeadPtr;
        cHeadPtr = tmp->next;
        delete tmp;
    }

}
bool BulletCollector::available() const{
    if (cHeadPtr == nullptr){
        return false;
    }
    else{
        return true;
    }
}
void BulletCollector::showCol() const{
    if(cHeadPtr != nullptr){
        for(Bullet* temp = cHeadPtr; temp != nullptr; temp=temp->next){
           cout << temp << endl;
        }
    }
    else{
        cout << "estoy empty :(" << endl;
    }
}
