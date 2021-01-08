//
// Created by santi on 28/11/2020.
//

#include <fstream>
#include "funciones.h"
#include "Agua.h"
#include "Tierra.h"
#include "Fuego.h"
#include "Aire.h"

using namespace std;

void cargar_personajes(Diccionario * lista){
    ifstream archivo_csv;
    archivo_csv.open(ARCHIVO_PERSONAJES,ios::in);
    string line;
    string tipo;
    string nombre;
    string escudo;
    string vida;
    cout << "Cargando personajes en el juego...\n" << endl;
    while (!archivo_csv.eof()){
        getline(archivo_csv, tipo, SEPARADOR_CSV);
        getline(archivo_csv, nombre, SEPARADOR_CSV);
        getline(archivo_csv, escudo, SEPARADOR_CSV);
        getline(archivo_csv, vida, SALTO_DE_LINEA);
        crear_personaje(tipo, nombre, stoi(vida), stoi(escudo), lista);
        lista->consulta(PRIMERA_POSICION)->mostrar_datos();
        cout << "--------------------------------" << endl;
    }
    cout << "Carga completa!" << endl;
}

void crear_personaje(const string& tipo, const string& nombre, int vida, int escudo, Diccionario * dicc){
    cout << "Cargando personaje..." << endl;
    if (tipo == TIPO_AGUA){
        Personaje * personaje = new Agua(nombre, vida, escudo);
        dicc->alta(personaje, nombre, PRIMERA_POSICION);
    }
    else if (tipo == TIPO_FUEGO){
        Personaje * personaje = new Fuego(nombre, vida, escudo);
        dicc->alta(personaje, nombre, PRIMERA_POSICION);
    }
    else if (tipo == TIPO_TIERRA){
        Personaje * personaje = new Tierra(nombre, vida, escudo);
        dicc->alta(personaje, nombre, PRIMERA_POSICION);
    }
    else if (tipo == TIPO_AIRE){
        Personaje * personaje = new Aire(nombre, vida, escudo);
        dicc->alta(personaje, nombre, PRIMERA_POSICION);
    }
}

/*
 * Imprime el menu principal del juego por pantalla.
 */
void imprimir_menu(){
    cout << "\n\t1) Agregar un nuevo personaje" << endl;
    cout << "\t2) Eliminar un personaje" << endl;
    cout << "\t3) Mostrar todos los nombres de los personajes" << endl;
    cout << "\t4) Buscar por nombre los detalles de un personaje en particular" << endl;
    cout << "\t5) Alimentar un personaje" << endl;
    cout << "\t6) Salir\n" << endl;
    cout << "Elija una opcion por favor:";
}

void crear_personaje_usuario(Diccionario * lista){
    string tipo;
    string nombre;
    int vida;
    int escudo;
    cout << "Que tipo de personajes desea crear? [agua, tierra, fuego, aire]:";
    cin >> tipo;
    cout << "\nIngrese el nombre de su personaje:";
    cin >> nombre;
    cout << "Ingrese la vida de su personaje:";
    cin >> vida;
    cout << "Ingrese el escudo de su personaje:";
    cin >> escudo;
    cout << endl;
    crear_personaje(tipo, nombre, vida, escudo, lista);
}

void mostrar_personajes(Diccionario * lista){
    for (int i = 1; i <= lista->obtener_cantidad(); i++){
        cout << i << ") " << lista->consulta(i)->mostrar_nombre() << endl;
    }
    cout << endl;
}

void ejecutar_opcion(Diccionario * lista, int opcion_elegida){
    if (opcion_elegida == OPCION_UNO){
        crear_personaje_usuario(lista);
    }
    if (opcion_elegida == OPCION_DOS){
        mostrar_personajes(lista);
        int personaje_a_eliminar;
        cout << "Elija un personaje para eliminar " << "(1-" << lista->obtener_cantidad() << "):";
        cin >> personaje_a_eliminar;
        if (personaje_a_eliminar > lista->obtener_cantidad() && personaje_a_eliminar < 0){
            cout << "No se ha podido eliminar ningun personaje." << endl;
        }
        else {
            cout << lista->consulta(personaje_a_eliminar)->mostrar_nombre() << " ha sido eliminado" << endl;
        }
        lista->baja(personaje_a_eliminar);
    }
    if (opcion_elegida == OPCION_TRES){
        mostrar_personajes(lista);
    }
    if (opcion_elegida == OPCION_CUATRO){
        cout << "Ingrese el nombre del personaje:";
        string nombre_a_buscar;
        cin >> nombre_a_buscar;
        lista->buscar_y_mostrar(nombre_a_buscar);
    }
    if (opcion_elegida == OPCION_CINCO){
        mostrar_personajes(lista);
        int personaje_a_alimentar;
        cout << "Elija un personaje para alimentar " << "(1-" << lista->obtener_cantidad() << "):";
        cin >> personaje_a_alimentar;
        lista->consulta(personaje_a_alimentar)->alimentar();
    }
}

int menu(){
    imprimir_menu();
    int opcion_elegida;
    cin >> opcion_elegida;
    cout << endl;
    return opcion_elegida;
}