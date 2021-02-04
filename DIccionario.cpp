#include "Diccionario.h"
#include <string>

using namespace std;

Diccionario::Diccionario() {
    raiz = nullptr;
    actual = raiz;
}

void Diccionario::alta(Clave clave, Valor valor) {
    actual = raiz;
    if(!esta_clave(clave)) {
        _alta(clave, valor, raiz, 0);
    } else cout << "La clave ya existe en el diccionario" << endl;
}

void Diccionario::_alta(Clave clave, Valor valor, nodo_diccionario* nodo, nodo_diccionario* padre){
    if(!nodo && !padre) {
        raiz = new nodo_diccionario(clave, valor, padre);
    } else if(nodo != raiz && padre -> es_hoja()) {
        if(padre -> obtener_clave() > clave) {
            padre -> insertar_izq(new nodo_diccionario(clave, valor, padre));
        } else {
            padre -> insertar_der(new nodo_diccionario(clave, valor, padre));
        }
    } else {
        if(clave < nodo -> obtener_clave()) {
            _alta(clave, valor, nodo -> obtener_izq(), nodo);
        } else {
            _alta(clave, valor, nodo -> obtener_der(), nodo);
        }
    }
}

bool Diccionario::esta_clave(Clave clave) {
    actual = raiz;
    return _esta_clave(raiz, clave);
}

bool Diccionario::_esta_clave(nodo_diccionario* n, Clave clave) {
    bool encontrado = false;
    if(n) {
       if(n->obtener_clave() == clave) {
           encontrado = true;
           actual = n;
       } else if(clave < n->obtener_clave()) {
           return _esta_clave(n->obtener_izq(), clave);
       } else {
           return _esta_clave(n->obtener_der(), clave);
       }
    }
    return encontrado;
}

bool Diccionario::es_raiz() {
    return this->raiz->obtener_padre() == 0;
}


bool Diccionario::vacio() {
    return !raiz;
}

Valor Diccionario::consulta(Clave clave) {
    Valor v = 0;
    if(esta_clave(clave)) {
        v = actual->obtener_valor();
    }
    return v;
}

Diccionario::~Diccionario() {
    eliminar_subarbol(raiz); // va a borrar la raiz y todos los nodos abajo de esta, o sea todo el arbol lmao
}

void Diccionario::eliminar_subarbol(nodo_diccionario* nodo) { // helper function
    // si le pasas la raiz, borra la raiz y todo lo que esta abajo de la raiz
    if (nodo) {
        if (nodo->obtener_izq()) eliminar_subarbol(nodo->obtener_izq()); // vas hasta el final del subarbol izq
        if (nodo->obtener_der()) eliminar_subarbol(nodo->obtener_der()); // vas hasta el final del subarbol der
    }
    Valor eliminar = nodo->obtener_valor();
    delete eliminar;
    delete nodo;
}


nodo_diccionario* Diccionario::buscar_min(nodo_diccionario* n) {
    if(!n) return 0;
    if(n->obtener_izq()) return buscar_min(n->obtener_izq());
    else return n;
}


void Diccionario::baja(Clave clave) {
    actual = raiz;
    if(esta_clave(clave)) {
        _baja(raiz, clave);
    } else cout << "clave no encontrada" << endl;
}

void Diccionario::_baja(nodo_diccionario* n, Clave clave) {
    if(!n) {
        cout << "diccionario vacio" << endl;
    } else if(clave < n->obtener_clave()) {
        _baja(n->obtener_izq(), clave);
    } else if(clave > n->obtener_clave()) {
        _baja(n->obtener_der(), clave);
    } else {
        eliminar_nodo(n);
    }
}

void Diccionario::reemplazar_nodo(nodo_diccionario* antiguo, nodo_diccionario* nuevo) {
    if(antiguo->obtener_padre()) {
        if(antiguo->obtener_clave() == antiguo->obtener_padre()->obtener_izq()->obtener_clave()) {
            antiguo->obtener_padre()->insertar_izq(nuevo);

        } else if(antiguo->obtener_clave() == antiguo->obtener_padre()->obtener_der()->obtener_clave()) {
            antiguo->obtener_padre()->insertar_der(nuevo);
        }
    }
    if(nuevo) {
        nuevo->insertar_padre(antiguo->obtener_padre());
    }
}

void Diccionario::eliminar_nodo(nodo_diccionario* eliminar) {
    if(eliminar->obtener_izq() && eliminar->obtener_der()) {
        nodo_diccionario* menor = buscar_min(eliminar->obtener_der());
        eliminar->asignar_clave(menor->obtener_clave());
        eliminar_nodo(menor);
    } else if(eliminar->obtener_izq()) {
        reemplazar_nodo(eliminar, eliminar->obtener_izq());
        eliminar->insertar_der(0);
        eliminar->insertar_izq(0);
        delete eliminar;
    } else if(eliminar->obtener_der()) {
        reemplazar_nodo(eliminar, eliminar->obtener_der());
        eliminar->insertar_der(0);
        eliminar->insertar_izq(0);
        delete eliminar;
    } else {
        reemplazar_nodo(eliminar, 0);
        eliminar->insertar_der(0);
        eliminar->insertar_izq(0);
        delete eliminar;
    }
}

nodo_diccionario* Diccionario::obtener_raiz() {
    return raiz;
}

Clave Diccionario::obtener_clave_raiz() {
    return raiz->obtener_clave();
}

void Diccionario::imprimir_inorden(nodo_diccionario* aux) {
    // recorrido inorden: subarbol izquierdo - raiz - subarbol derecho
    if (aux != 0) { // caso base: raiz = 0, subarbol vacio, corta la recursividad
        imprimir_inorden(aux->obtener_izq());
        cout << aux->obtener_clave() << endl;
        imprimir_inorden(aux->obtener_der());
    }
}
