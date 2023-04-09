//
// Created by dadu on 02/04/23.
//

#include "Waves.h"
#include <iostream>
using namespace std;
Waves::Waves(){
    Waves::head= nullptr;
    size = 0;
}
Waves::~Waves(){}
ShipEnemy *Waves::getHead(){
    return head;
}

void Waves::setHead(ShipEnemy *nHead) {
    Waves::head = nHead;
}
int Waves::getGenDamage() {
    return genDamage;
}

void Waves::setGenDamage(int genDamage) {
    Waves::genDamage = genDamage;
}


void Waves::insertShips(int numShips) {
    ShipEnemy* tempShip = new ShipEnemy();
    tempShip->setCode(0);
    setHead(tempShip);
    size ++;
    for(int i = 1; i<numShips;i++ ){
        ShipEnemy* tempShip = new ShipEnemy();
        tempShip->setCode(i);
        tempShip->setNextEnemy(head);
        setHead(tempShip);
        size ++;
    }
}
void Waves::colShip(int sCode, int damage){
    ShipEnemy* tmp = head;
    while(tmp!= nullptr){
        if(tmp->getCode()==sCode){
            tmp->setVida(tmp->getVida()-damage);
            if(tmp->getVida()<=0){
                tmp->setAlive(false);
            }
            break;
        }
        else{
            tmp = tmp->getNextEnemy();
        }
    }
}



