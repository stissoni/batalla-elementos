#include "vertice.h"

Vertice::Vertice(int primera, int segunda, Casillero* casillero) {
    coordenadas = Coordenada(primera, segunda);
    lista = new Lista();
    this->casillero = casillero;
}

Coordenada Vertice::obtener_coordenadas() {
    return coordenadas;
}


Casillero* Vertice::obtener_casillero() {
    return casillero;
}