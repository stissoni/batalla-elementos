#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <string>
#include "personaje.h"

using namespace std;

typedef string Clave;
typedef Personaje* Valor;

class nodo_diccionario {
private:
    Valor valor;
    nodo_diccionario* der;
    nodo_diccionario* izq;
    nodo_diccionario* padre;
    Clave clave;
public:
    nodo_diccionario(Clave clave, Valor valor, nodo_diccionario* padre);
    void copiar_nodo(nodo_diccionario* n);
    bool es_hoja();
    void insertar_der(nodo_diccionario* der);
    void insertar_izq(nodo_diccionario* izq);
    void insertar_padre(nodo_diccionario* padre);
    Clave obtener_clave();
    nodo_diccionario* obtener_der();
    nodo_diccionario* obtener_izq();
    nodo_diccionario* obtener_padre();
    Valor obtener_valor();
    bool solo_hijo_der();
    bool solo_hijo_izq();
    void asignar_clave(Clave clave);

};


#endif // NODO_H_INCLUDED
