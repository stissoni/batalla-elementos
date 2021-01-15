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

Key Nodo::consultar_clave() {
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

void Nodo::baja(Key clave, Value valor, 

void Nodo::insertar_padre(Nodo* padre) {
    this->padre = padre;
}

//void Nodo::cambiar_dato(Value valor) {
//    this->valor = valor;
//}


void Nodo::insertar_izq(Nodo* izq){
    this->izq = izq;
}

Nodo* Nodo::obtener_der()
{
    return der->der;
}

void Nodo::insertar_der(Nodo* der){
    this->der = der;
}

Nodo* Nodo::obtener_izq(){
    return this->izq;
}

Nodo* Nodo::obtener_padre()
{
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

Value Nodo::consultar_value() {
    return value;
}


