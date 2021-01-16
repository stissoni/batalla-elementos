//
// Created by santi on 10/1/2021.
//

#ifndef TP2_BATALLA_ELEMENTOS_ARBOL_H
#define TP2_BATALLA_ELEMENTOS_ARBOL_H

#include "Nodo.h"

class Diccionario {
private:
    Nodo* raiz;
    Nodo* actual;
    int cantidad_nodos;
public:
    // Constructor.
    Diccionario();
    
    // Agrega un par clave:valor al diccionario. Incrementa cantidad_nodos en uno.
    void alta(Clave clave, Valor valor);
    
    // Elimina del diccionario el nodo que contiene la clave pasada por parametro. Decrementa cantidad_nodos en uno.
    void baja(Clave clave);
    
    // Se le pasa una clave, y devuelve un puntero a Personaje si lo encuentra con la clave proporcionada.
    Value buscar(Clave clave);
    
    // Encuentra el minimo valor en el diccionario.
    void buscar_min(Nodo* raiz);
    
    // Devuelve true si el nodo es raiz, false de lo contrario.
    bool es_raiz();
    
    // Recorre el diccionario en busca de la clave, devuelve true si la encuentra, sino devuelve false.
    bool esta_key(Clave clave);
    
    // Devuelve true si el diccionario esta vacio, false de lo contrario.
    bool esta_vacio();
    
    // Se inserta una entrada en el diccionario. La entrada esta compuesta por un par clave: string y valor: puntero a Personaje.
    void insertar_dato(Clave clave, Valor valor);
    
    // Devuelve el numero de entradas en el diccionario.
    int largo();
    
    // Encuentra el sucesor del nodo que contiene la clave pasada por parametro
    void sucesor(Nodo* raiz, Nodo*& suc, Clave clave);


    // Destructor
    virtual ~Diccionario();
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
