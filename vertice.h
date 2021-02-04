#include "casillero.h"
#include "coordenada.h"
#include "lista.h"

class Vertice {
private:
    Coordenada coordenadas; // el ID
    Lista * lista; // la lista de adyacencia
    Casillero* casillero; // el datazo

public:
    Vertice(int primera, int segunda, Casillero * casillero);
    Coordenada obtener_coordenadas();
    Casillero* obtener_casillero();
};