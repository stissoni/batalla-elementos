//
// Created by santi on 24/11/2020.
//

#include "Nodo.h"

Nodo::Nodo(Dato d, string k) {
    dato = d;
    key = k;
    siguiente = nullptr;
}

void Nodo::cambiar_dato(Dato d) {
    dato = d;
}

void Nodo::cambiar_siguiente(Nodo* s) {
    siguiente = s;
}

Dato Nodo::obtener_dato() {
    return dato;
}

string Nodo::obtener_key(){
    return key;
}

Nodo* Nodo::obtener_siguiente() {
    return siguiente;
}