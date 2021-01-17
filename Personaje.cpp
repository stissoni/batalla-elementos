//
// Created by santi on 18/11/2020.
//

#include "Personaje.h"
#include <cstdlib>

Personaje::Personaje(string _nombre, int _vida, int _escudo) {
    nombre = _nombre;
    vida = _vida;
    escudo = _escudo;
    energia = rand() % 21;
}

void Personaje::recargar_energia(int _energia) {
    if ((energia + _energia) > 20) {
        cout << "Limite de energia excedido. Energia +" << 20 - energia << endl;
        energia = 20;
    }
    else {
        cout << "Energia +" << _energia << endl;
        energia = energia + _energia;
    }
}

void Personaje::recargar_vida(int _vida) {
    if ((vida + _vida) > 100) {
        cout << "Vida maxima alcanzada. Vida +" << 100 - vida << endl;
        vida = 100;
    }
    else {
        cout << "Vida +" << _vida << endl;
        vida = vida + _vida;
    }
}

void Personaje::mostrar_datos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Vida: " << vida << endl;
    cout << "Energia: " << energia << endl;
    cout << "Escudo: " << escudo << endl;
}


void Personaje::alimentar() {
    cout << "Este personaje no se puede alimentar!" << endl;
}


bool esta_vivo() {
    return vida != 0;
}

string Personaje::mostrar_nombre() {
    return nombre;
}

Personaje::~Personaje() {

}
/*
int Personaje::mostrar_vida() {
    return vida;
}

int Personaje::mostrar_escudo() {
    return escudo;
}

int Personaje::mostrar_energia() {
    return energia;
}
*/
