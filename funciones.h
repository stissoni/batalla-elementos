//
// Created by santi on 28/11/2020.
//

#ifndef TP2_BATALLA_ELEMENTOS_FUNCIONES_H
#define TP2_BATALLA_ELEMENTOS_FUNCIONES_H

#include "Diccionario.h"

using namespace std;

const int PRIMERA_POSICION = 1;
const string ARCHIVO_PERSONAJES = "personajes.csv";
const string TIPO_AGUA = "agua";
const string TIPO_AIRE = "aire";
const string TIPO_FUEGO = "fuego";
const string TIPO_TIERRA = "tierra";
const int OPCION_UNO = 1;
const int OPCION_DOS = 2;
const int OPCION_TRES = 3;
const int OPCION_CUATRO = 4;
const int OPCION_CINCO = 5;
const int OPCION_SEIS = 6;
const char SEPARADOR_CSV = ',';
const char SALTO_DE_LINEA = '\n';

/*
 * Recibe una lista donde los personajes seran guardados. Carga desde el archivo personajes.csv los personajes del juego, siempre en la primera
 * posicion de la lista.
 */
void cargar_personajes(Diccionario * lista);

/*
 * Recibe los atributos necesarios para crear un objeto herado de Personaje, de la clase indicada, y lo carga en la memoria dinamica.
 */
void crear_personaje(const string& tipo, const string& nombre, int vida, int escudo, Diccionario * dicc);

/*
 * Permite cargar el menu, mostrarlo por pantalla. Retorna la opcion elegida por el jugador.
 */
int menu();

/*
 * A partir de la opcion elegida por el jugador, ejecuta el comando deseado.
 */
void ejecutar_opcion(Diccionario * lista, int opcion_elegida);

#endif //TP2_BATALLA_ELEMENTOS_FUNCIONES_H
