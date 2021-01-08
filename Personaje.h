//
// Created by santi on 18/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_PERSONAJE_H
#define TP2_BATALLA_ELEMENTOS_PERSONAJE_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Personaje {
protected:
    // Atributos.
    int vida;
    int escudo;
    int energia;
    string nombre;
    // Metodos protegidos. Solo son utilizados en funciones dentro de clases derivadas.
    void recargar_energia(int _energia);
    void recargar_vida(int _vida);
public:
    // Metodos publicos
    // Constructor: recibe nombre, vida y escudo de personaje.
    // Crea un personaje con esos valores, y le inicializa una energia de valor aleatorio.
    Personaje(string _nombre, int _vida, int _escudo);
    // Devuelve el nombre en forma de cadena de caracteres.
    string mostrar_nombre();
    //int mostrar_vida();
    //int mostrar_escudo();
    //int mostrar_energia();
    // Muestra los datos del personaje: nombre, vida, escudo y energia.
    virtual void mostrar_datos();
    // Alimenta al personaje. Gracias a la polimorfia, clases derivadas redefinen esta funcion.
    virtual void alimentar();
    virtual ~Personaje();
};

#endif //TP2_BATALLA_ELEMENTOS_PERSONAJE_H
