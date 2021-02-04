#ifndef TP2_BATALLA_ELEMENTOS_ARBOL_H
#define TP2_BATALLA_ELEMENTOS_ARBOL_H

#include "nodo_diccionario.h"
#include <string>

class Diccionario {
private:
    nodo_diccionario* raiz;
    nodo_diccionario* actual;

public:
    // Constructor.
    Diccionario();

    // Agrega un par clave:valor al diccionario. Incrementa cantidad_nodos en uno.
    void alta(Clave clave, Valor valor);

    // Elimina del diccionario el nodo que contiene la clave pasada por parametro. Decrementa cantidad_nodos en uno.
    void baja(Clave clave);

    // Encuentra el minimo valor en el diccionario.
    nodo_diccionario* buscar_min(nodo_diccionario* raiz);

    // Se le pasa una clave, y devuelve un puntero a Personaje si lo encuentra con la clave proporcionada.
    Valor consulta(Clave clave);

    // Devuelve true si el nodo es raiz, false de lo contrario.
    bool es_raiz();

    // Recorre el diccionario en busca de la clave, devuelve true si la encuentra, sino devuelve false.
    bool esta_clave(Clave clave);

    // Imprime las claves del diccionario, siguiendo recorrido inorden
    void imprimir_inorden(nodo_diccionario* aux);

    nodo_diccionario* obtener_raiz();

    // Devuelve true si el diccionario esta vacio, false de lo contrario.
    bool vacio();

    // Destructor
    virtual ~Diccionario();

    Clave obtener_clave_raiz();

    nodo_diccionario* crear_nodo(Clave clave, Valor valor);


    void _alta(Clave clave, Valor valor, nodo_diccionario* nodo, nodo_diccionario* padre);

    void reemplazar_nodo(nodo_diccionario* antiguo, nodo_diccionario* nuevo);

    void eliminar_nodo(nodo_diccionario* eliminar);

private:
    void _baja(nodo_diccionario* n, Clave clave);
    //Valor baja_nodo(nodo_diccionario* padre, nodo_diccionario* nodo_borrar, bool izq);
    //Valor baja_raiz();
    void eliminar_subarbol(nodo_diccionario* borrar);
    bool _esta_clave(nodo_diccionario* n, Clave clave);
};

#endif //TP2_BATALLA_ELEMENTOS_ARBOL_H
