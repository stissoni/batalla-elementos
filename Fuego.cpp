//
// Created by santi on 22/11/2020.
//

#include "Fuego.h"

Fuego::Fuego(string _nombre, int vida, int escudo) : Personaje(_nombre, vida, escudo) {

}

void Fuego::alimentar() {
    cout << "Alimentando a " << nombre << "..." << endl;
    Personaje::recargar_vida(15);
    cout << "Vida: " << vida << endl;
}

void Fuego::mostrar_datos() {
    cout << "Tipo de personaje: FUEGO" << endl;
    Personaje::mostrar_datos();
}

Fuego::~Fuego() {

}
