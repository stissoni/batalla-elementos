#include "menu.h"

Menu::Menu() {
    personajes = 0;
    esta_activo = false;
}

Menu::~Menu() {
    while(!personajes->vacia()) {
        Personaje* eliminado = personajes->baja_y_devuelve(1);
        delete eliminado;
    }
    delete personajes;
}

void Menu::cargar_personajes(string archivo) {
    personajes = new Lista();
    ifstream archivo_personajes;

    archivo_personajes.open(archivo);
    if(!archivo_personajes) {
        cout << ERROR_APERTURA << endl;
    } else {
        string elemento;
        string nombre;
        string escudo;
        string vida;

        while(getline(archivo_personajes, elemento, ',')) {
            getline(archivo_personajes, nombre, ',');
            getline(archivo_personajes, escudo, ',');
            getline(archivo_personajes, vida);
            cargar_personaje_segun_elemento(elemento, nombre, stoi(escudo), stoi(vida));
        }
    }
}

void Menu::cargar_personaje_segun_elemento(string elemento, string nombre, int escudo, int vida) {
    Personaje* nuevo;
    if(elemento == ELEMENTO_AGUA) nuevo = new Personaje_de_agua(nombre, escudo, vida);
    else if(elemento == ELEMENTO_AIRE) nuevo = new Personaje_de_aire(nombre, escudo, vida);
    else if(elemento == ELEMENTO_FUEGO) nuevo = new Personaje_de_fuego(nombre, escudo, vida);
    else if(elemento == ELEMENTO_TIERRA) nuevo = new Personaje_de_tierra(nombre, escudo, vida);
    personajes->alta(nuevo);
}

void Menu::cargar_personaje_segun_elemento(string elemento, string nombre) {
    Personaje* nuevo;
    if(elemento == ELEMENTO_AGUA) nuevo = new Personaje_de_agua(nombre);
    else if(elemento == ELEMENTO_AIRE) nuevo = new Personaje_de_aire(nombre);
    else if(elemento == ELEMENTO_FUEGO) nuevo = new Personaje_de_fuego(nombre);
    else if(elemento == ELEMENTO_TIERRA) nuevo = new Personaje_de_tierra(nombre);
    personajes->alta(nuevo);
}

void Menu::agregar_nuevo_personaje() {
    string elemento = pedir_elemento_personaje();
    string nombre = pedir_nombre_personaje();
    cargar_personaje_segun_elemento(elemento, nombre);
}

void Menu::eliminar_personaje() {
    if(!personajes->vacia()) {
        string nombre = pedir_nombre_personaje();
        Personaje* eliminado = personajes->baja_y_devuelve(nombre);
        if(eliminado) {
            delete eliminado;
            cout << "El personaje " << nombre << " fue eliminado" << endl;
        } else cout << "El personaje " << nombre << " no se encuentra en la lista" << endl;
    } else {
        cout << ERROR_LISTA_VACIA << endl;
    }
}

void Menu::mostrar_nombres_personajes() {
    if(!personajes->vacia())
        for(int i = 1; i <= personajes->obtener_cantidad(); i++) cout << personajes->consulta(i)->nombre_personaje() << endl;
    else cout << ERROR_LISTA_VACIA << endl;
}

void Menu::detalles_personaje() {
    if(!personajes->vacia()) {
        string nombre = pedir_nombre_personaje();
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado) {
            Personaje* solicitado = personajes->obtener_actual();
            solicitado->mostrar_detalles();
        } else {
            cout << "El personaje " << nombre << " no se encuentra en la lista" << endl;
        }
    } else {
        cout << ERROR_LISTA_VACIA << endl;
    }
}

void Menu::alimentar_personaje() {
    if(!personajes->vacia()) {
        string nombre = pedir_nombre_personaje();
        Personaje* solicitado = personajes->consulta(nombre);
        if(solicitado) {
            solicitado->alimentar();
        } else cout << "El personaje " << nombre << " no se encuentra en la lista" << endl;
    } else {
        cout << ERROR_LISTA_VACIA << endl;
    }
}

void Menu::salir() {
    esta_activo = false;
}

void Menu::mensaje_bienvenida() {
    cout << MENSAJE_BIENVENIDA << endl;
}

void Menu::interfaz() {
    mensaje_bienvenida();
    esta_activo = true;
    while(esta_activo){
        mostrar_opciones();
        int opcion = pedir_opcion();
        switch(opcion)
        {
            case 1:
                agregar_nuevo_personaje();
                break;
            case 2:
                eliminar_personaje();
                break;
            case 3:
                mostrar_nombres_personajes();
                break;
            case 4:
                detalles_personaje();
                break;
            case 5:
                alimentar_personaje();
                break;
            case 6:
                salir();
                break;
        }
    }
}

void Menu::mostrar_opciones() {
    cout << "Elija una opcion (ingrese el numero): " << endl;
    cout << "1. " << OPCION_1 << endl;
    cout << "2. " << OPCION_2 << endl;
    cout << "3. " << OPCION_3 << endl;
    cout << "4. " << OPCION_4 << endl;
    cout << "5. " << OPCION_5 << endl;
    cout << "6. " << OPCION_6 << endl;
}

int Menu::pedir_opcion() {
    int opcion;
    while(true) {
        cin >> opcion;
        if(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6) return opcion;
        }
}

string Menu::pedir_elemento_personaje() {
    string elemento;
    while(true) {
        cout << "Ingrese el elemento del personaje (agua, aire, fuego o tierra): ";
        cin >> elemento;
        if(elemento == ELEMENTO_AGUA || elemento == ELEMENTO_AIRE || elemento == ELEMENTO_FUEGO || elemento == ELEMENTO_TIERRA) return elemento;
    }
}

string Menu::pedir_nombre_personaje() {
    string nombre;
    cout << "Ingrese el nombre del personaje: ";
    cin >> nombre;
    return nombre;
}