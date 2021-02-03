#include "camino.h"

Camino::Camino(): Casillero() {
}

int Camino::calcular_costo(Personaje* nuevo) {
    return COSTO_CAMINO;
}

string Camino::tipo_casillero() {
    return CAMINO;
}
