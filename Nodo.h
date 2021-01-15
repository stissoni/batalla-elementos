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
    void asignar_dato(Key _key, Value _value, string izq_o_der);
    Key consultar_clave();
    Value consultar_value();
    void insertar_izq(Nodo* izq);
    void insertar_der(Nodo* der);
    void insertar_padre(Nodo* padre);
    Nodo* obtener_izq();
    Nodo* obtener_der();
    Nodo* obtener_padre();
    // Nodo* obtener_nodo(string izq_o_der);

};


#endif //TP2_BATALLA_ELEMENTOS_NODO_ABB_H
