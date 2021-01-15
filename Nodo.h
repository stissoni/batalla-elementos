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

const string IZQUIERDO = "izquierdo";
const string DERECHO = "derecho";

class Nodo {
private:
    Value value;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
    Key key;
public:
    explicit Nodo(Key _key, Value _value);
    Nodo* obtener_nodo(string izq_o_der);
    Key consultar_key();
    Value consultar_value();
    void asignar_dato(Key _key, Value _value, string izq_o_der);
};


#endif //TP2_BATALLA_ELEMENTOS_NODO_ABB_H
