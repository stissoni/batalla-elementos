#include "vertice.h"

Vertice::Vertice(Coordenada coordenadas, ListaAdyacencia lista, Casillero* casillero) {
    this->coordenadas = coordenadas;
    this->lista = lista;
    this->casillero = casillero;
}

Coordenada obtener_coordenadas() {
    return coordenadas;
}

ListaAdyacencia obtener_lista() {
    return lista;
}

Casillero* obtener_casillero() {
    return casillero;
}