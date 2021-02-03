#include "vertice.h"

Vertice::Vertice(Coordenada coordenadas, ListaAdyacencia lista, Casillero* casillero) {
    this->coordenadas = coordenadas;
    this->lista = lista;
    this->casillero = casillero;
}

Coordenada Vertice::obtener_coordenadas() {
    return coordenadas;
}

ListaAdyacencia Vertice::obtener_lista() {
    return lista;
}

Casillero* Vertice::obtener_casillero() {
    return casillero;
}