//
// Created by santi on 10/1/2021.
//

#ifndef TP2_BATALLA_ELEMENTOS_NODO_ABB_H
#define TP2_BATALLA_ELEMENTOS_NODO_ABB_H

#include <string>
#include "Personaje.h"

using namespace std;

typedef string Key;
typedef Personaje* Value;

class Nodo {
private:
    Value value;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
    Key key;
public:
    explicit Nodo(Key _key, Value _value);
    bool es_hoja();
    void insertar_der(Nodo* izq);
    void insertar_izq(Nodo* der);
    void insertar_padre(Nodo* padre);
    Key obtener_clave();
    Nodo* obtener_der();
    Nodo* obtener_izq();
    Nodo* obtener_padre();
    Value obtener_valor();
    bool solo_hijo_der();
    bool solo_hijo_izq();

};


#endif //TP2_BATALLA_ELEMENTOS_NODO_ABB_H
