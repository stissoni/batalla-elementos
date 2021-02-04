//
// Created by santi on 3/2/2021.
//

#include "grafo.h"
#include "vertice.h"

void Grafo::agregar_vertice(int primera, int segunda, Casillero * casillero) {
    Vertice * vertice = new Vertice(primera, segunda, casillero);
    lista_vertices->alta(vertice);

}
