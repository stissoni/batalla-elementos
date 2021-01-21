#ifndef TP2_BATALLA_ELEMENTOS_ARBOL_H
#define TP2_BATALLA_ELEMENTOS_ARBOL_H

#include "Nodo.h"
#include <string.h>

const string ERROR_CLAVE_NO_ENCONTRADA = "La clave no se encuentra en el diccionario";

class Diccionario {
private:
    Nodo* raiz;

public:
    // Constructor.
    Diccionario();

    // Agrega un par clave:valor al diccionario. Incrementa cantidad_nodos en uno.
    void alta(Clave clave, Valor valor);

    // Elimina del diccionario el nodo que contiene la clave pasada por parametro. Decrementa cantidad_nodos en uno.
    Valor baja(Clave clave);

    // Encuentra el minimo valor en el diccionario.
    Nodo* buscar_min(Nodo* raiz);

    // Se le pasa una clave, y devuelve un puntero a Personaje si lo encuentra con la clave proporcionada.
    Valor consulta(Clave clave);

    // Devuelve true si el nodo es raiz, false de lo contrario.
    bool es_raiz();

    // Recorre el diccionario en busca de la clave, devuelve true si la encuentra, sino devuelve false.
    bool esta_clave(Clave clave);

    // Imprime las claves del diccionario, siguiendo recorrido inorden
    void imprimir_inorden(Nodo* aux);

    // Se inserta una entrada en el diccionario. La entrada esta compuesta por un par clave: string y valor: puntero a Personaje.
    void insertar_dato(Clave clave, Valor valor);

    Nodo* obtener_raiz();

    // Encuentra el sucesor del nodo que contiene la clave pasada por parametro
    void sucesor(Nodo* raiz, Nodo*& suc, Clave clave);

    // Devuelve true si el diccionario esta vacio, false de lo contrario.
    bool vacio();

    // Destructor
    virtual ~Diccionario();

private:
    Valor _baja(Clave clave, Nodo* padre);
    Valor baja_nodo(Nodo* padre, Nodo* nodo_borrar, bool izq);
    Valor baja_raiz();
    void RemoveSubtree(Nodo* borrar);
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
