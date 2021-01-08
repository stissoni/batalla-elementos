//
// Created by santi on 22/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_AIRE_H
#define TP2_BATALLA_ELEMENTOS_AIRE_H

#include "Personaje.h"

class Aire : public Personaje{
public:
    Aire(string _nombre, int vida, int escudo);
    void mostrar_datos();
    ~Aire();
};

#endif //TP2_BATALLA_ELEMENTOS_AIRE_H
