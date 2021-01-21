#include <iostream>
#include "menu.h"
#include "personaje.h"
#include "personaje_de_agua.h"
#include "personaje_de_aire.h"
#include "personaje_de_fuego.h"
#include "personaje_de_tierra.h"

using namespace std;

int main()
{
    /*Menu nuevo_menu;
    nuevo_menu.cargar_personajes("personajes.csv");
    nuevo_menu.interfaz();*/
    Diccionario* nuevo = new Diccionario;
    Personaje* p_nuevo_3 = new Personaje_de_agua("a", 2, 1);
    Personaje* p_nuevo = new Personaje_de_agua("cami", 2, 1);
    Personaje* p_2 = new Personaje_de_fuego("frank", 2, 100);
    nuevo->alta(p_nuevo->nombre_personaje(), p_nuevo);
    nuevo->alta(p_nuevo_3->nombre_personaje(), p_nuevo_3);
    nuevo->alta(p_2->nombre_personaje(), p_2);
    nuevo->imprimir_inorden(nuevo->obtener_raiz());
    Nodo* minimo = nuevo->buscar_min(nuevo->obtener_raiz());
    cout << "el minimo es " << minimo->obtener_clave() << endl;
    while(!nuevo->vacio()) {
        Personaje* borrar = nuevo->baja(nuevo->obtener_raiz()->obtener_clave());
        delete borrar;
    }
    delete nuevo;
}
