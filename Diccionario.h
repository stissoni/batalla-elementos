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
    // Constructor.
    Diccionario();
    // Devuelve el numero de entradas en el diccionario.
    int largo();
    // Se inserta una entrada en el diccionario. La entrada esta compuesta por un par key: string y value: puntero a Personaje.
    void insertar_dato(Key key, Value value);
    // Se le pasa una key, y devuelve un puntero a Personaje si lo encuentra con la key proporcionada.
    Value buscar(Key key);
    // Recorre el diccionario en busca de la key, devuelve true si encuentra la key, sino devuelve false.
    bool esta_key(Key key);
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
