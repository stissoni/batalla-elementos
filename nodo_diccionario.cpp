
#include "nodo_diccionario.h"
#include <string>

nodo_diccionario::nodo_diccionario(Clave clave, Valor valor, nodo_diccionario* padre) {
    izq = nullptr;
    der = nullptr;
    this->padre = padre;
    this->clave = clave;
    this->valor = valor;
}

Clave nodo_diccionario::obtener_clave() {
    return this->clave;
}

void nodo_diccionario::asignar_clave(Clave clave) {
    this->clave = clave;
}


void nodo_diccionario::insertar_padre(nodo_diccionario* padre) {
    this->padre = padre;
}

//void nodo_diccionario::cambiar_dato(Value valor) {
//    this->valor = valor;
//}


void nodo_diccionario::insertar_izq(nodo_diccionario* izq) {
    this->izq = izq;
}

nodo_diccionario* nodo_diccionario::obtener_der() {
    return this->der;
}

void nodo_diccionario::insertar_der(nodo_diccionario* der) {
    this->der = der;
}

nodo_diccionario* nodo_diccionario::obtener_izq() {
    return this->izq;
}

nodo_diccionario* nodo_diccionario::obtener_padre() {
    return this->padre;
}

bool nodo_diccionario::es_hoja() {
    return (!this->obtener_izq() && !this->obtener_der());
}

bool nodo_diccionario::solo_hijo_der() {
    return (!this->obtener_izq() && this->obtener_der());
}

bool nodo_diccionario::solo_hijo_izq() {
    return (this->obtener_izq() && !this->obtener_der());
}

Valor nodo_diccionario::obtener_valor() {
    return valor;
}

void nodo_diccionario::copiar_nodo(nodo_diccionario* n) {
    this->izq = n->obtener_izq();
    this->der = n->obtener_izq();
    this->padre = n->obtener_padre();
    this->clave = n->obtener_clave();
    this->valor = n->obtener_valor();
}
