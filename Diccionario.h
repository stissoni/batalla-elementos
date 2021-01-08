//
// Created by santi on 24/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_DICCIONARIO_H
#define TP2_BATALLA_ELEMENTOS_DICCIONARIO_H

#include "Nodo.h"

class Diccionario {
private:
    // Atributos.
    Nodo* primero;
    Nodo* actual;
    int cantidad;

public:
    // constructor
    // pos: crea una cola vacia
    Diccionario();

    // pre: 0 < pos <= cantidad + 1
    // pos: inserta el dato d en la posicion pos, la 1 es la primera
    //        ademas incrementa cantidad en 1
    void alta(Dato d, string key, int pos);

    // pre: 0 < pos <= cantidad
    // pos: saca el elemento que esta en pos
    void baja(int pos);

    // pre: 0 < pos <= cantidad
    // pos: devuelve el elemento que esta en pos
    Dato consulta(int pos);

    bool vacia();

    // pos: libera la memoria
    virtual ~Diccionario();

    int obtener_cantidad();

    // reinicia el puntero actual a la primera posici�n (o nulo si la lista es vac�a).
    // PRE:
    // POS: pone el puntero a la primera posici�n o apuntando a NULL
    void reiniciar ();

    // consulta si hay un elemento siguiente (si el actual no apunta a NULL)
    // PRE:
    // POS: devuelve true si el actual no apunta a NULL, false de lo contrario
    bool hay_siguiente ();

    // devuelve el siguiente elemento (el elemento que apunta actual)
    // PRE: hay_siguiente tiene que haber devuelto true previamente
    // POS: devuelve el elemento actual y avanza
    Dato siguiente ();

    // pos: devuelve true si d esta en la lista, false de lo contrario
    bool esta(Dato d);

    // Recibe una cadena de caracteres el personaje. Encuentra el personaje en la lista y muestra sus datos.
    void buscar_y_mostrar(string nombre);

    Dato buscar(string key);

private:
    Nodo* obtener_nodo(int pos);

    string consultar_key(int pos);

};

#endif //TP2_BATALLA_ELEMENTOS_DICCIONARIO_H
