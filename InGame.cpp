//
// Created by dadu on 08/04/23.
//

#include "InGame.h"

#include <iostream>

using namespace std;

InGame::InGame() {
    *waves = new Waves[15] {
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves(),
       Waves()

    };

    waves[0]->insertShips(4);
    waves[1]->insertShips(4);
    waves[2]->insertShips(4);
    waves[3]->insertShips(4);
    waves[4]->insertShips(4);
    waves[5]->insertShips(6);
    waves[6]->insertShips(6);
    waves[7]->insertShips(6);
    waves[8]->insertShips(6);
    waves[9]->insertShips(6);
    waves[10]->insertShips(8);
    waves[11]->insertShips(8);
    waves[12]->insertShips(8);
    waves[13]->insertShips(8);
    waves[14]->insertShips(8);
    countCurrent = 0;
    currentWave = waves[0];
}

Waves *InGame::getCurrentWave() {
    return currentWave;
}

void InGame::setCurrentWave(Waves *currentWave) {
    InGame::currentWave = currentWave;
}
void InGame::changeDifficulty(char x) {
    switch(x){
        case 1:
            for (auto & wave : waves)
                wave->setGenDamage(10);

            break;
        case 2:
            for(auto & wave : waves){
                wave->setGenDamage(25);
            }
            break;
        case 3:
            for(auto & wave : waves){
                wave->setGenDamage(50);
            }
            break;
        default:
            cout<<"Oh oh caracter equivocado"<<endl;
    }
}
bool InGame::checkNextW() {
    bool value = true;
    ShipEnemy* tmp = currentWave->getHead();
    while(tmp!= nullptr){
        if(tmp->isAlive()==true){
            value = false;
            break;
        }
    }
    if(value){
        countCurrent++;
        currentWave=waves[countCurrent];
    }
    return value;
}