//
// Created by dadu on 02/04/23.
//

#include "Waves.h"
Waves::Waves(){}
Waves::~Waves(){}
ShipEnemy *Waves::getHead(){
    return head;
}

void Waves::setHead(ShipEnemy *nHead) {
    Waves::head = nHead;
}
void Waves::deleteShip(){
    
}