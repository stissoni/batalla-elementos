//
// Created by santi on 10/1/2021.
//

#include "Nodo.h"
#include <string>

Nodo::Nodo(Key key, Value value) {
    izq = nullptr;
    der = nullptr;
    this->key = key;
    this->value = value;
}

Key Nodo::obtener_clave() {
    return key;
}


void Nodo::insertar_padre(Nodo* padre) {
    this->padre = padre;
}

//void Nodo::cambiar_dato(Value valor) {
//    this->valor = valor;
//}


void Nodo::insertar_izq(Nodo* izq) {
    this->izq = izq;
}

Nodo* Nodo::obtener_der() {
    return der->der;
}

void Nodo::insertar_der(Nodo* der) {
    this->der = der;
}

Nodo* Nodo::obtener_izq() {
    return this->izq;
}

Nodo* Nodo::obtener_padre() {
    return this->padre;
}

bool Nodo::es_hoja() {
    return (this->obtener_izq() == NULL && this->obtener_der() == NULL);
}

bool Nodo::solo_hijo_der() {
    return (this->obtener_izq() == NULL && this->obtener_der() != NULL);
}

bool Nodo::solo_hijo_izq() {
    return (this->obtener_izq() != NULL && this->obtener_der() == NULL);
}

Value Nodo::obtener_valor() {
    return value;
}

                

