//
// Created by santi on 24/11/2020.
//

#include "Diccionario.h"

Diccionario::Diccionario() {
    primero = nullptr;
    actual = nullptr;
    cantidad = 0;
}

bool Diccionario::vacia() {
    return (cantidad == 0);
}

void Diccionario::alta(Dato d, string key, int pos) {
    Nodo* nuevo = new Nodo(d, key);
    if (pos == 1) {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        Nodo* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    cantidad++;
}

Nodo* Diccionario::obtener_nodo(int pos) {
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Dato Diccionario::consulta(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

string Diccionario::consultar_key(int pos){
    Nodo * aux = obtener_nodo(pos);
    return aux->obtener_key();
}

void Diccionario::baja(int pos) {
    Personaje * personaje_a_eliminar = this->consulta(pos);
    Nodo* borrar;
    if (pos == 1) {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    reiniciar();
    delete personaje_a_eliminar;
    delete borrar;
    cantidad--;
}

Diccionario::~Diccionario()  {
    while (! vacia()) {
        baja(1);
    }
}

int Diccionario::obtener_cantidad()  {
    return cantidad;
}

void Diccionario::reiniciar() {
    actual = primero;
}

bool Diccionario::hay_siguiente() {
    return (actual != 0);
}

Dato Diccionario::siguiente() {
    Nodo* aux = actual;
    actual = actual->obtener_siguiente();
    return aux->obtener_dato();
}

bool Diccionario::esta(Dato d) {
    bool encontrado = false;
    reiniciar();
    while (hay_siguiente() && ! encontrado) {
        if (siguiente() == d)
            encontrado = true;
    }
    return encontrado;
}


void Diccionario::buscar_y_mostrar(string key) {
    bool encontrado = false;
    for (int i = 1; i <= this->obtener_cantidad(); i++){
        if (this->consultar_key(i) == key && !encontrado){
            this->consulta(i)->mostrar_datos();
            encontrado = true;
        }
    }
    if (!encontrado){
        cout << "No se ha podido encontrar el personaje :(" << endl;
    }
}

Dato Diccionario::buscar(string key) {
    for (int i = 1; i <= this->obtener_cantidad(); i++){
        if (this->consultar_key(i) == key){
            return this->consulta(i);
        }
    }
    cout << "No se ha podido encontrar el personaje :(" << endl;

}

