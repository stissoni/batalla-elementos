#include "coordenada.h"

Coordenada::Coordenada(int _primera, int _segunda) {
    primera = _primera;
    segunda = _segunda;
}

int Coordenada::obtener_primera() {
    return this->primera;
}

int Coordenada::obtener_segunda() {
    return this->segunda;
}

void Coordenada::cambiar_primera(int nueva) {
    this->primera = nueva;
}

void Coordenada::cambiar_segunda(int nueva) {
    this->segunda = nueva;
}

