//
// Created by santi on 10/1/2021.
//

#ifndef TP2_BATALLA_ELEMENTOS_ARBOL_H
#define TP2_BATALLA_ELEMENTOS_ARBOL_H

#include "Nodo.h"

class Diccionario {
private:
    Nodo * raiz;
    int cantidad_nodos;
public:
    Diccionario();
    int largo();
    void insertar_dato(Key key, Value value);
    Value buscar(Key key);
    bool esta_key(Key key);
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
