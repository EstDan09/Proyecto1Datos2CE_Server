//
// Created by dadu on 04/04/23.
//

#ifndef PROYECTO1DATOS2CE_SERVER_STRATEGYS_H
#define PROYECTO1DATOS2CE_SERVER_STRATEGYS_H
#include <iostream>
#include "Ammunation.h"

using namespace std;

class Strategys {
public:
    Strategys();
    ~Strategys();

    string xmlReader(string sCode);
    int lastVida;
    int activaded;
    int escudo();
    int curacion();

};


#endif //PROYECTO1DATOS2CE_SERVER_STRATEGYS_H
