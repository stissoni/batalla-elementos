//
// Created by santi on 21/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_TIERRA_H
#define TP2_BATALLA_ELEMENTOS_TIERRA_H

#include "Personaje.h"

class Tierra : public Personaje {
public:
    Tierra(string _nombre, int vida, int escudo);
    void alimentar();
    void mostrar_datos();
    ~Tierra();
};

#endif //TP2_BATALLA_ELEMENTOS_TIERRA_H
