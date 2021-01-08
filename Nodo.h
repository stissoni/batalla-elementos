//
// Created by santi on 24/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_NODO_H
#define TP2_BATALLA_ELEMENTOS_NODO_H

#include "Personaje.h"

typedef Personaje * Dato;

class Nodo {
private:
    string key;
    Dato dato;
    Nodo * siguiente;
public:
    explicit Nodo(Dato d, string k);
    void cambiar_dato(Dato d);
    void cambiar_siguiente(Nodo * s);
    Dato obtener_dato();
    Nodo * obtener_siguiente();
    string obtener_key();
};


#endif //TP2_BATALLA_ELEMENTOS_NODO_H
