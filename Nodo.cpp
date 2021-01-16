//
// Created by santi on 10/1/2021.
//

#include "Nodo.h"
#include <string>

Nodo::Nodo(Clave clave, Valor valor) {
    izq = nullptr;
    der = nullptr;
    this->clave = clave;
    this->valor = valor;
}

Clave Nodo::obtener_clave() {
    return clave;
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
    return (!this->obtener_izq() && !this->obtener_der());
}

bool Nodo::solo_hijo_der() {
    return (!this->obtener_izq() && this->obtener_der());
}

bool Nodo::solo_hijo_izq() {
    return (this->obtener_izq() && !this->obtener_der());
}

Valor Nodo::obtener_valor() {
    return valor;
}

void Nodo::copiar_nodo(Nodo* n) {
    this->clave = n->clave;
    this->valor = n->valor;
}

