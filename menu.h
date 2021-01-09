#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "personaje.h"
#include "personaje_de_agua.h"
#include "personaje_de_aire.h"
#include "personaje_de_fuego.h"
#include "personaje_de_tierra.h"
#include <fstream>
#include "diccionario.h"

const string ERROR_APERTURA = "No se pudo abrir el archivo de personajes";
const string ERROR_LISTA_VACIA = "No hay personajes en la lista";

const string MENSAJE_BIENVENIDA = "¡Bienvenido!";

const string OPCION_1 = "Agregar un nuevo personaje a la lista";
const string OPCION_2 = "Eliminar un personaje de la lista";
const string OPCION_3 = "Mostrar todos los nombres de los personajes";
const string OPCION_4 = "Buscar por nombre los detalles de un personaje en particular";
const string OPCION_5 = "Alimentar un personaje";
const string OPCION_6 = "Salir";

class Menu {
private:
    /*
    Atributos
    */
    Diccionario* personajes;
    bool esta_activo;
    Juego* juego;

public:
    /*
    Constructor:
    Crea un menu con la lista de personajes vacia, inicialmente desactivado
    */
    Menu();

    /*
    Destructor:
    Libera memoria
    */
    ~Menu();

    /*
    PRE: El archivo debe ser de tipo csv con el formato elemento,nombre,escudo,vida
    POS: Lee el archivo con el nombre recibido por parametro y, si pudo abrirse, crea personajes con los datos del mismo y los carga a la lista de personajes
    */
    void cargar_personajes(string archivo);

    /*
    Activa el menu
    Este metodo se encarga de interactuar con el usuario, mostrando las opciones y ejecutando las tareas que el usuario elija
    */
    void interfaz();
    
    /*
    Activa el submenu
    Este metodo se encarga de interactuar con el usuario, mostrando las opciones y ejecutando las tareas que el usuario elija
    */
    void interfaz_submenu();

private:
    /*
    Crea un personaje segun el elemento, nombre, valor de escudo y valor de vida ingresados
    */
    void cargar_personaje_segun_elemento(string elemento, string nombre, int escudo, int vida);

    /*
    PRE: Elemento debe ser agua, aire tierra o fuego
    POS: Crea un personaje segun el elemento y nombre, el resto de los atributos son aleatorios manteniendose en sus cotas
    */
    void cargar_personaje_segun_elemento(string elemento, string nombre);

    /*
    PRE: Elemento debe ser agua, aire tierra o fuego
    POS: Agrega un nuevo personaje a la lista de personajes
    */
    void agregar_nuevo_personaje();

    /*
    Elimina el personaje del nombre ingresado por el usuario
    */
    void eliminar_personaje();

    /*
    Imprime por pantalla los nombres de los personajes de la lista
    */
    void mostrar_nombres_personajes();

    /*
    Muestra los detalles del personaje del cual el usuario solicita por nombre (si es que hay un personaje con dicho nombre en la lista)
    */
    void detalles_personaje();

    /*
    Alimenta al personaje del nombre que ingresa el usuario, si es que este esta en la lista
    */
    void alimentar_personaje();

    /*
    Apaga el menu, cortando con el ciclo y libera memoria
    */
    void salir();

    /*
    Imprime por pantalla el mensaje de bienvenida
    */
    void mensaje_bienvenida();

    /*
    Imprime por pantalla las opciones del menu
    */
    void mostrar_opciones();
    
    /*
    Imprime por pantalla las opciones del submenu
    */
    void mostrar_opciones_submenu();

    /*
    Pide al usuario un numero entero, que representara una opcion del menu, y lo devuelve
    */
    int pedir_opcion();

    /*
    Pide al usuario que ingrese un elemento (debe ser agua, aire, fuego o tierra) y lo devuelve
    */
    string pedir_elemento_personaje();

    /*
    Pide al usuario un nombre y lo devuelve
    */
    string pedir_nombre_personaje();
    
    void comenzar_juego();
    
    void seleccionar_personaje();

};


#endif // MENU_H_INCLUDED
