//
// Created by santi on 3/2/2021.
//

#ifndef BATALLA_ELEMENTOS_GRAFO_H
#define BATALLA_ELEMENTOS_GRAFO_H

#include "lista.h"
#include "vertice.h"

class Grafo {
private:
    Lista * lista_vertices;
public:
    void agregar_vertice(int primera, int segunda, Casillero * casillero);
};


#endif //BATALLA_ELEMENTOS_GRAFO_H
