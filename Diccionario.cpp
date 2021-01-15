//
// Created by santi on 10/1/2021.
//

#include "Diccionario.h"
#include <string>

using namespace std;

Diccionario::Diccionario() {
    raiz = nullptr;
    cantidad_nodos = 0;
}

void Diccionario::alta(Key key, Value value) {
    auto * nodo_nuevo = new Nodo(key, value);
    Nodo * aux = raiz;
    Nodo * anterior;
    
     if (vacio()){
        // Caso diccionario vacio
        raiz = nodo_nuevo;
     }
    
    // Caso diccionario no vacio
    else{
        while (aux){
            anterior = aux;
            if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
        }
            else {
                aux = aux->obtener_der();
            }
        }
        
        if (key.compare(anterior->consultar_key()) < 0){
            anterior->asignar_dato(key, value, IZQUIERDO);
        }
        else {
            anterior->asignar_dato(key, value, DERECHO);
        }
    }
    cantidad_nodos++;
}

bool Diccionario::esta_key(Key key) {
    bool encontrado = false;
    if (raiz != nullptr){
        Nodo * aux = raiz;
        while (aux != nullptr && encontrado == 0){
            if (key == aux->consultar_key()){
                encontrado = true;
                this->actual = aux;
            }
            else if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
   
    return encontrado;
}

int Diccionario::largo() {
    return cantidad_nodos;
}

Value Diccionario::buscar(Key key) {
    if (!esta_key(key)){
        cout << "No se puede encontrar la key. Devolviendo puntero nulo";
    }
    else {
        Nodo * aux = raiz;
        while (aux != nullptr){
            if (key == aux->consultar_key()){
                return aux->consultar_value();
            }
            else if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
    return nullptr;
}

Diccionario::~Diccionario() {

}

void Diccionario::baja(Key key){
    if(!esta_key(key)){
        cout << "No esta." << endl;
    }
    else{
        
    }
    
}

