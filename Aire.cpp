//
// Created by santi on 22/11/2020.
//

#include "Aire.h"

Aire::Aire(string _nombre, int vida, int escudo) : Personaje(_nombre, vida, escudo) {

}

void Aire::mostrar_datos() {
    cout << "Tipo de personaje: AIRE" << endl;
    Personaje::mostrar_datos();
}

Aire::~Aire() {

}

