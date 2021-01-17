//
// Created by santi on 10/1/2021.
//

#ifndef TP2_BATALLA_ELEMENTOS_NODO_ABB_H
#define TP2_BATALLA_ELEMENTOS_NODO_ABB_H

#include <string>
#include "Personaje.h"

using namespace std;

typedef string Clave;
typedef Personaje* Valor;

class Nodo {
private:
    Valor valor;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
    Clave clave;
public:
    explicit Nodo(Clave clave, Valor valor);
    bool es_hoja();
    void insertar_der(Nodo* der);
    void insertar_izq(Nodo* izq);
    void insertar_padre(Nodo* padre);
    Clave obtener_clave();
    Nodo* obtener_der();
    Nodo* obtener_izq();
    Nodo* obtener_padre();
    Valor obtener_valor();
    bool solo_hijo_der();
    bool solo_hijo_izq();

};


#endif //TP2_BATALLA_ELEMENTOS_NODO_ABB_H
