//
// Created by santi on 21/11/2020.
//

#include "Tierra.h"

Tierra::Tierra(string _nombre, int vida, int escudo) : Personaje(_nombre, vida, escudo) {

}

void Tierra::mostrar_datos() {
    cout << "Tipo de personaje: TIERRA" << endl;
    Personaje::mostrar_datos();
}

void Tierra::alimentar() {
    cout << "Alimentando a " << nombre << "..." << endl;
    Personaje::recargar_energia(8);
    cout << "Energia disponible: " << energia << endl;
}

Tierra::~Tierra() {

}
