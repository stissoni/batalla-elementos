#include "casillero.h"
#include "coordenada.h"

class Vertice {
    private:
    Coordenada coordenadas; // el ID
    ListaAdyacencia lista; // la lista de adyacencia
    Casillero* casillero; // el datazo

    public:
    Vertice(Coordenada coordenadas, ListaAdyacencia lista, Casillero* casillero);
    Coordenada obtener_coordenadas();
    ListaAdyacencia obtener_lista();
    Casillero* obtener_casillero();
};