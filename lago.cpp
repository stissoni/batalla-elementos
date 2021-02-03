#include "Lago.h"

Lago::Lago(): Casillero() {
}

int Lago::calcular_costo(Personaje* nuevo) {
    int nuevo_costo = 0;
    if(nuevo->de_que_elemento_soy() == ELEMENTO_FUEGO) {
        nuevo_costo = 2;
    }
    else if(nuevo->de_que_elemento_soy() == ELEMENTO_TIERRA || nuevo->de_que_elemento_soy() == ELEMENTO_AIRE) {
        nuevo_costo = 1;
    }
    return nuevo_costo;
}

string Lago::tipo_casillero() {
    return LAGO;
}
