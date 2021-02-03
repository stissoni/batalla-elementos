#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include "personaje.h"
#include "personaje_de_fuego.h"
#include "personaje_de_agua.h"
#include "personaje_de_aire.h"
#include "personaje_de_tierra.h"

const int COSTO_VACIO = 15;
const int COSTO_LAGO = 1;
const int COSTO_PRECIPICIO = 1;
const int COSTO_MONTANIA = 1;
const int COSTO_VOLCAN = 1;
const int COSTO_CAMINO = 1;

const string VACIO = "vacio";

class Casillero {
protected:
    Personaje* personaje;
    Casillero();
public:
    virtual ~Casillero();
    bool hay_personaje();
    void posicionar_personaje(Personaje* nuevo);
    virtual int calcular_costo() = 0;
    virtual string tipo_casillero() = 0;
};



#endif // CASILLERO_H_INCLUDED
