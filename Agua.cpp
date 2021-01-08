//
// Created by santi on 20/11/2020.
//

#include "Agua.h"

void Agua::alimentar() {
    if (alimento_disponible > 0){
        cout << "Alimentando a " << nombre << "..." << endl;
        Personaje::recargar_energia(10);
        alimento_disponible--;
        cout << "Energia disponible: " << energia << endl;
        cout << "Plancton disponible: " << alimento_disponible << endl;
    }
    else {
        cout << "Nos hemos quedado sin plancton! Imposible alimentar a " << nombre << endl;
        cout << "Energia disponible: " << energia << endl;
    }
}

Agua::Agua(string _nombre, int vida, int escudo):Personaje(_nombre, vida, escudo){
    alimento_disponible = 3;
}

void Agua::mostrar_datos() {
    cout << "Tipo de personaje: AGUA" << endl;
    Personaje::mostrar_datos();
}

Agua::~Agua() {

}




