//
// Created by santi on 10/1/2021.
//

#include "Nodo.h"
#include <string>

Nodo::Nodo(Key _key, Value _value) {
    izq = nullptr;
    der = nullptr;
    key = _key;
    value = _value;
}

Key Nodo::consultar_key() {
    return key;
}

Nodo *Nodo::obtener_nodo(string izq_o_der) {
    if (izq_o_der == IZQUIERDO){
        return izq;
    }
    else{
        return der;
    }
}

void Nodo::asignar_dato(Key _key, Value _value, string izq_o_der) {
    auto * nodo_nuevo = new Nodo(_key, _value);
    if (izq_o_der == IZQUIERDO){
        izq = nodo_nuevo;
    }
    else {
        der = nodo_nuevo;
    }
}

Value Nodo::consultar_value() {
    return value;
}


