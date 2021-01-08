//
// Created by santi on 22/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_FUEGO_H
#define TP2_BATALLA_ELEMENTOS_FUEGO_H

#include "Personaje.h"

class Fuego : public Personaje {
public:
    Fuego(string _nombre, int vida, int escudo);
    void alimentar();
    void mostrar_datos();
    ~Fuego();
};

#endif //TP2_BATALLA_ELEMENTOS_FUEGO_H
