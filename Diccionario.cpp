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

bool Diccionario::esta_key(Key key, Nodo* nuevo) {
    bool encontrado = false;
    if (raiz != nullptr){
        Nodo * aux = raiz;
        while (aux != nullptr && encontrado == 0){
            if (key == aux->consultar_key()){
                encontrado = true;
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

void Diccionario::findSuccessor(Node* root, Node*& succ, int key)
{
    // base case
    if (root == nullptr) {
        succ = nullptr;
        return;
    }
 
    // if node with key's value is found, the successor is minimum value
    // node in its right subtree (if any)
    if (root->data == key)
    {
        if (root->right)
            succ = findMinimum(root->right);
    }
    // if given key is less than the root node, recur for left subtree
    else if (key < root->data)
    {
        // update successor to current node before recursing in left subtree
        succ = root;
        findSuccessor(root->left, succ, key);
    }
 
    // if given key is more than the root node, recur for right subtree
    else
        findSuccessor(root->right, succ, key);
}

void Diccionario::buscar_min(Nodo* raiz) {
    while(raiz->obtener_izq()) raiz = raiz->obtener_izq();
    return raiz;
}

void Diccionario::sucesor(Nodo* raiz, Nodo*& suc, Key clave) { // revisar el *& wtf amigo
    if(!raiz->es_raiz()) {
        succ = 0;
        return;
    }
    if(raiz->obtener_clave() == clave) {
        if(raiz->obtener_der()) suc = buscar_min(raiz->obtener_der());
    } else if(clave < raiz->obtener_clave()) {
        suc = raiz;
        sucesor(raiz->obtener_izq(), suc, clave);
    else sucesor(raiz->obtener_der(), suc, clave);
}

void Diccionario::baja(Key key) {
    Nodo* act = raiz;
    _baja(act, key);

Nodo* Diccionario::_baja(Nodo* act, Key key){
    if(!act) return act;
    else if(key < act->obtener_clave()) act->obtener_izq() = _baja(act->obtener_izq(), key);
    else if(key > act->obtener_clave)) act->obtener_der() = _baja(act->obtener_der(), key);
    else {
        if(!act->obtener_izq && !act->obtener_der) {
            delete act;
            act = 0;
        } else if(!act->obtener_izq()) {
            Nodo* aux = act;
            act = act->obtener_der();
            delete aux;
        } else if(!act->obtener_der()) {
            Nodo* aux = act;
            act = act->obtener_izq();
            delete aux;
        } else {
            Nodo* aux = buscar_min(act->obtener_der());
            act->copiar_nodo(act);
            act->obtener_der() = _borrar(act->obtener_der(), act->obtener_clave());
        }
}

void Diccionario::_baja(Key key){
    if(esta_key(key)){
        if(!actual->obtener_padre() && !actual->obtener_der() && !actual->obtener_izq()){
            raiz = 0;
        } else if(!actual->obtener_padre() && actual->solo_hijo_izq()) {
            borrar = raiz;
            raiz = actual->obtener_izq();
        } else if(!actual->obtener_padre)() && actual->solo_hijo_der()) {
            borrar = raiz;
            raiz = actual->obtener_der();
        } else if(actual->es_hoja()) {
            if(actual->obter_padre->solo_hijo_izq())
                 actual->obtener_padre()->insertar_izq(0);    
            else(actual->obter_padre->solo_hijo_der())  
                actual->obtener_padre()->insertar_der(0);
        } else if(actual->solo_hijo_izq()) {
            
        }
        // The node has two children (left and right)
        else{
            // Find successor or predecessor to avoid quarrel
            Nodo* sucesor = this->sucesor(key);

             = sucesor;

            // Delete the old successor's key
            actual->insertar_der((node->get_right(), successor_data));
        }
        delete actual;
        reiniciar();
    }
    else{
        cout << "No esta." << endl;
    }   
}
