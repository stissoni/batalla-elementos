//
// Created by santi on 10/1/2021.
//

#include "Diccionario.h"
#include <string>

using namespace std;

Diccionario::Diccionario() {
    raiz = 0;
    cantidad_nodos = 0;
}

void Diccionario::alta(Clave clave, Valor valor) {
    auto* nodo_nuevo = new Nodo(clave, valor);
    Nodo* aux = raiz;
    Nodo* anterior;
    
    // Caso diccionario vacio
     if (esta_vacio()){
        raiz = nodo_nuevo;
     }
    
    // Caso diccionario no vacio
    else{
        while (aux){
            anterior = aux;
            if (clave.compare(aux->obtener_clave()) < 0){       
                aux = aux->obtener_izq();
             }
            else {
                aux = aux->obtener_der();
            }
        }
        
        if (clave.compare(anterior->obtener_clave()) < 0){
            anterior->insertar_izq(nuevo_nodo);
        }
        else {
            anterior->insertar_der(nuevo_nodo);
        }
    }
    cantidad_nodos++;
}

bool Diccionario::esta_clave(Clave clave, Nodo* nuevo) {
    bool encontrado = false;
    if (raiz){
        Nodo * aux = raiz;
        while (aux && !encontrado){
            if (clave == aux->obtener_clave()){       
                encontrado = true;
            }
            else if (clave.compare(aux->obtener_clave()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
   
    return encontrado;
}


bool Diccionario::es_raiz() {
    return this->obtener_padre() == 0;
}

        
bool Diccionario::esta_vacio() {
    return cantidad_nodos == 0;
}


int Diccionario::largo() {
    return cantidad_nodos;
}

Valor Diccionario::consulta(Clave clave) {
    if (!esta_clave(clave)){
        cout << ERROR_CLAVE_NO_ENCONTRADA << endl;
    }
    else {
        Nodo * aux = raiz;
        while (aux){
            if (clave == aux->obtener_clave()){             
                return aux->obtener_valor();
            }
            else if (clave.compare(aux->obtener_clave()) < 0){
                aux = aux->obtener_izq();
            }
            else {
                aux = aux->obtener_der();
            }
        }
    }
    return 0;
}

Diccionario::~Diccionario() {

}

/* CREO QUE NO LO USAMOS...
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
*/

void Diccionario::buscar_min(Nodo* raiz) {
    while(raiz->obtener_izq()) raiz = raiz->obtener_izq();
    return raiz;
}

/*  CREO QUE NO LO USAMOS...
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
 */   


/*void Diccionario::baja(Clave clave) { //este es el baja que no devuelve
    if(esta_clave(clave)) {
        Nodo* act = raiz;
        _baja(act, clave);
    } else {
        cout << ERROR_CLAVE_NO_ENCONTRADA << endl;
    }
}*/
    
/*Nodo* Diccionario::_baja(Nodo* act, Clave clave){
    if(!act) return act;
    else if(clave < act->obtener_clave()) act->obtener_izq() = _baja(act->obtener_izq(), clave);
    else if(clave > act->obtener_clave)) act->obtener_der() = _baja(act->obtener_der(), clave);
    else {
        if(!act->obtener_izq() && !act->obtener_der()) {
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
            act->copiar_nodo(aux);
            act->obtener_der() = _baja(act->obtener_der(), aux->obtener_clave());
        }
}
*/
    
Valor Diccionario::baja(Clave clave) {
    Nodo* act = 0;
    if(esta_clave(clave)) {
        act = raiz;
        Valor dato = consulta(clave);
        _baja(act, clave);
        return dato;
    }
    return act;
}
    
    
Valor Diccionario::_baja(Nodo* act, Clave clave){
    if(!act) return act;
    else if(clave < act->obtener_clave()) act->obtener_izq() = _baja(act->obtener_izq(), clave);
    else if(clave > act->obtener_clave)) act->obtener_der() = _baja(act->obtener_der(), clave);
    else { // acá lo encontró
        if(!act->obtener_izq() && !act->obtener_der()) { // acá es hoja
            delete act;
            act = 0;
        } else if(!act->obtener_izq()) { // solo hijo derecho
            Nodo* aux = act;
            act = act->obtener_der();
            delete aux;
        } else if(!act->obtener_der()) { // solo hijo izquierdo
            Nodo* aux = act;
            act = act->obtener_izq();
            delete aux;
        } else { // tiene 2 hijos
            Nodo* aux = buscar_min(act->obtener_der());
            act->copiar_nodo(aux);
            act->obtener_der() = _baja(act->obtener_der(), aux->obtener_clave());
        }
}
    
    
void imprimir_inorden(Nodo* raiz) {
    // recorrido inorden: subarbol izquierdo - raiz - subarbol derecho
    if (raiz != 0) { // caso base: raiz = 0, subarbol vacio, corta la recursividad
        imprimir_inorden(raiz->obtener_izq()); 
        cout << raiz->obtener_clave() << " ";
        imprimir_inorden(raiz->obtener_der());
    }
}
