#include <iostream>
#include <sstream>
#include "ctime"
#include "Personaje.h"
#include "Diccionario.h"
#include "funciones.h"

using namespace std;

int main() {
    srand(time(NULL));
    auto * diccionario = new Diccionario();
    cargar_personajes(diccionario);
    cout << "\nBienvenido a la Batalla de los Elementos!" << endl;
    // LO SIGUIENTE COMENTADO ERA EL MENU, PARA PROBAR EL DICCIONARIO NO SE NECESITA.
    /*int opcion_elegida = menu();
    while (opcion_elegida != OPCION_SEIS){
        ejecutar_opcion(lista, opcion_elegida);
        opcion_elegida = menu();
    }
    cout << "Desconectando...";
     */

    // PRUEBA DEL DICCIONARIO 1
    diccionario->buscar_y_mostrar("airecito"); // Busca por key y muestra los datos del personaje.
    // PRUEBA DEL DICCIONARIO 2: funcion buscar: recibe key, devuelve puntero a personaje.
    Personaje * personaje = diccionario->buscar("tierrita"); // Busco con key "tierrita" y lo guardo en puntero personaje.
    cout << "Nombre personaje:" << personaje->mostrar_nombre(); // Imprime nombre del personaje guardado en el puntero.
    delete diccionario;
    return 0;
}
