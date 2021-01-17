//
// Created by santi on 10/1/2021.
//

#ifndef TP2_BATALLA_ELEMENTOS_ARBOL_H
#define TP2_BATALLA_ELEMENTOS_ARBOL_H

#include "Nodo.h"

const string ERROR_CLAVE_NO_ENCONTRADA = "La clave no se encuentra en el diccionario";

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
    
    // Encuentra el minimo valor en el diccionario.
    void buscar_min(Nodo* raiz);
    
    // Se le pasa una clave, y devuelve un puntero a Personaje si lo encuentra con la clave proporcionada.
    Value consulta(Clave clave);
    
    // Devuelve true si el nodo es raiz, false de lo contrario.
    bool es_raiz();
    
    // Recorre el diccionario en busca de la clave, devuelve true si la encuentra, sino devuelve false.
    bool esta_clave(Clave clave);
    
    // Imprime las claves (y valores?) del diccionario, siguiendo recorrido inorden 
    void imprimir_inorden(Nodo* raiz);
    
    // Se inserta una entrada en el diccionario. La entrada esta compuesta por un par clave: string y valor: puntero a Personaje.
    void insertar_dato(Clave clave, Valor valor);
    
    // Devuelve el numero de entradas en el diccionario.
    int largo();
    
    // Encuentra el sucesor del nodo que contiene la clave pasada por parametro
    void sucesor(Nodo* raiz, Nodo*& suc, Clave clave);
    
    // Devuelve true si el diccionario esta vacio, false de lo contrario.
    bool vacio();

    // Destructor
    virtual ~Diccionario();
    
private:
    Nodo* _baja(Nodo* act, Clave clave);
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
