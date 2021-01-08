//
// Created by santi on 20/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_AGUA_H
#define TP2_BATALLA_ELEMENTOS_AGUA_H

#include "Personaje.h"

class Agua : public Personaje{
private:
    int alimento_disponible;
public:
    Agua(string _nombre, int vida, int escudo);
    void alimentar();
    void mostrar_datos();
    ~Agua();
};

#endif //TP2_BATALLA_ELEMENTOS_AGUA_H
