
#include "Nodo.h"
#include <string>

Nodo::Nodo(Clave clave, Valor valor) {
    padre = 0;
    izq = 0;
    der = 0;
    this->clave = clave;
    this->valor = valor;
}

Clave Nodo::obtener_clave() {
    return clave;
}


void Nodo::insertar_padre(Nodo* padre) {
    this->padre = padre;
}

void Nodo::cambiar_izq(Nodo* nuevo) {
    this->izq = 0;
}

void Nodo::cambiar_der(Nodo* nuevo) {
    this->der = 0;
}

//void Nodo::cambiar_dato(Value valor) {
//    this->valor = valor;
//}


void Nodo::insertar_izq(Nodo* izq) {
    this->izq = izq;
}

Nodo* Nodo::obtener_der() {
    return this->der;
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
