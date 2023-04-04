//
// Created by dadu on 02/04/23.
//

#include "Waves.h"
#include <iostream>
using namespace std;
Waves::Waves(){
    Waves::head= nullptr;
}
Waves::~Waves(){}
ShipEnemy *Waves::getHead(){
    return head;
}

void Waves::setHead(ShipEnemy *nHead) {
    Waves::head = nHead;
}
void Waves::deleteShip(){
}

void Waves::insertShips(int numShips) {
    ShipEnemy* tempShip = new ShipEnemy();
    tempShip->setCode(0);
    setHead(tempShip);
    for(int i = 1; i<numShips;i++ ){
        ShipEnemy* tempShip = new ShipEnemy();
        tempShip->setCode(i);
        tempShip->setNextEnemy(head);
        setHead(tempShip);
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

