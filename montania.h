#ifndef MONTANIA_H_INCLUDED
#define MONTANIA_H_INCLUDED

#include <string>
#include "Personaje.h"

using namespace std;

class Montania: public Casillero
{
public:
    Montania();
    string tipo_casillero();
    int calcular_costo(Personaje* nuevo);
};

#endif // MONTANIA_H_INCLUDED
