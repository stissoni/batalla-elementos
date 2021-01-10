#include "jugador.h"

Jugador::Jugador() {
    cantidad_personajes = 0;
    personajes_elegidos = new Personaje*[MAX_PERSONAJES];
}

Jugador::~Jugador() {
    delete [] personajes_elegidos;
}

void Jugador::agregar_personaje(Personaje* nuevo) {
    personajes_elegidos[cantidad_personajes++] = nuevo;
}

bool Jugador::eligio_max_personajes() {
    return cantidad_personajes == MAX_PERSONAJES;
}

bool Jugador::jugador_perdio() {
    int personajes_muertos = 0;
    for(int i = 0; i < cantidad_personajes; i++) {
        if(personajes_elegidos[i]->esta_muerto()) personajes_muertos++;
    }
    if(peronajes_muertos == cantidad_personajes) return true;
    return false;
}
