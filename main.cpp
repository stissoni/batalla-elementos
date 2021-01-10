//
// Created by santi on 10/1/2021.
//

#include "Diccionario.h"
#include "Personaje.h"
#include "Tierra.h"
#include "Fuego.h"
#include "Agua.h"
#include <iostream>

using namespace std;

int main(){
    // Crear diccionario y algunos personajes (en el tp los personajes se crean desde el archivo csv).
    auto * diccionario = new Diccionario();
    auto * tierrita = new Tierra("tierrita", 100, 2);
    auto * fueguito = new Fuego("fueguito", 100, 2);
    auto * aguita = new Agua("aguita", 100, 2);

    // Inserto los personajes personajes al diccionario.
    diccionario->insertar_dato("tierrita", tierrita);
    diccionario->insertar_dato("fueguito", fueguito);
    diccionario->insertar_dato("aguita", aguita);

    // PRUEBAS

    string KEY = "aguita"; // Probar diferentes nombres de key cambiando el valor de KEY.
    Personaje * personaje = diccionario->buscar(KEY); // El metodo buscar devuelve puntero a personaje si encuentra una key asociada.
    // Si el metodo buscar funciono, los siguientes metodos deberian funcionar tambien.
    personaje->alimentar();
    cout << "-------------" << endl;
    personaje->mostrar_datos();
    cout << "-------------" << endl;
    // Numero de entradas en el diccionario.
    cout << "Numero de entradas: " << diccionario->largo() << endl;
    cout << "-------------" << endl;
    // Para verificar que las entradas sean unicas se puede usar el siguiente metodo. Devuelve si la key se encuentra en el diccionario.
    // 1 para true, 0 para false (la funcion retorna valores booleanos pero cout los convierte a 0 o 1).
    cout << "Se encuentra " << KEY << "?: " << diccionario->esta_key(KEY);

    return 0;
}