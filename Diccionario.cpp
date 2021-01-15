//
// Created by santi on 10/1/2021.
//

#include "Diccionario.h"
#include <string>

using namespace std;

Diccionario::Diccionario() {
    raiz = nullptr;
    cantidad_nodos = 0;
}

void Diccionario::alta(Key key, Value value) {
    auto * nodo_nuevo = new Nodo(key, value);
    Nodo * aux = raiz;
    Nodo * anterior;
    
     if (vacio()){
        // Caso diccionario vacio
        raiz = nodo_nuevo;
     }
    
    // Caso diccionario no vacio
    else{
        while (aux){
            anterior = aux;
            if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
        }
            else {
                aux = aux->obtener_der();
            }
        }
        
        if (key.compare(anterior->consultar_key()) < 0){
            anterior->asignar_dato(key, value, IZQUIERDO);
        }
        else {
            anterior->asignar_dato(key, value, DERECHO);
        }
    }
    cantidad_nodos++;
}

bool Diccionario::esta_key(Key key) {
    bool encontrado = false;
    if (raiz != nullptr){
        Nodo * aux = raiz;
        while (aux != nullptr && encontrado == 0){
            if (key == aux->consultar_key()){
                encontrado = true;
                this->actual = aux;
            }
            else if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
   
    return encontrado;
}

int Diccionario::largo() {
    return cantidad_nodos;
}

Value Diccionario::buscar(Key key) {
    if (!esta_key(key)){
        cout << "No se puede encontrar la key. Devolviendo puntero nulo";
    }
    else {
        Nodo * aux = raiz;
        while (aux != nullptr){
            if (key == aux->consultar_key()){
                return aux->consultar_value();
            }
            else if (key.compare(aux->consultar_key()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
    return nullptr;
}

Diccionario::~Diccionario() {

}

void Diccionario::baja(Key key){
    if(esta_key(key)){

        if(!actual->obtener_padre() && !actual->obtener_der() && !actual->obtener_izq()){
            raiz = 0;
        }
       
        else if(actual->es_hoja()){
            if(actual->obter_padre->solo_hijo_izq())
                 actual->obtener_padre()->insertar_izq(0);    
            else(actual->obter_padre->solo_hijo_der())  
                actual->obtener_padre()->insertar_der(0);
        }
        
        else if(actual->es_padre()){
            if(actual->solo_hijo_izq()){
                actual->obtener_izq()->insertar_padre(actual->obtener_padre());
            }
            else if(actual->solo_hijo_der()){
                actual->obtener_der()->insertar_padre(actual->obtener_padre());
            }
            else{
                actual->obtener_der()->insertar_padre(actual->obtener_padre());
                actual->obtener_der()->insertar_izq(atual->obtener_izq());
            }
        }
        
        delete actual;
        reiniciar();
            
    else{
        cout << "No esta." << endl;
    }   
}
    
Nodo* Diccionario::remove(Nodo* node, Key key)
{
        // The node has two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            T successor_data = this->successor(data);

            // Replace node's key with successor's key
            node->set_data(successor_data);

            // Delete the old successor's key
            node->set_right(remove(node->get_right(), successor_data));
        }
    }

    else if (node->get_data() < data)
        node->set_right(remove(node->get_right(), data));

    else
        node->set_left(remove(node->get_left(), data));

    return node;
}
