#include "Diccionario.h"
#include <string>

using namespace std;

Diccionario::Diccionario() {
    raiz = 0;
}

void Diccionario::alta(Clave clave, Valor valor) {
    Nodo* nodo_nuevo = new Nodo(clave, valor);
    Nodo* aux = raiz;
    Nodo* anterior;

    // Caso diccionario vacio
    if (vacio()){
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
            anterior->insertar_izq(nodo_nuevo);
        }
        else {
            anterior->insertar_der(nodo_nuevo);
        }
    }
}

bool Diccionario::esta_clave(Clave clave) {
    bool encontrado = false;
    if(raiz) {
        Nodo * aux = raiz;
        while (aux && !encontrado) {
            if(clave == aux->obtener_clave()) {
                encontrado = true;
            }
            else if(clave.compare(aux->obtener_clave()) < 0) {
                aux = aux->obtener_izq();
            } else {
                aux = aux->obtener_der();
            }
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
        Nodo* aux = raiz;
        while(aux) {
            if (clave == aux->obtener_clave()){
                v = aux->obtener_valor();
                return v;
            } else if (clave.compare(aux->obtener_clave()) < 0){
                aux = aux->obtener_izq();
            } else {
                aux = aux->obtener_der();
            }
        }
    }
    return v;
}

Diccionario::~Diccionario() {
    RemoveSubtree(raiz);
}

void Diccionario::RemoveSubtree(Nodo* borrar) {
    if(borrar) {
       if(borrar->obtener_izq()) {
            RemoveSubtree(borrar->obtener_izq());
       }
       if(borrar->obtener_der()) {
            RemoveSubtree(borrar->obtener_der());
       }
       delete borrar;
    }
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

Nodo* Diccionario::buscar_min(Nodo* raiz) {
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

/*Valor Diccionario::baja(Clave clave) {
    Valor dato = 0;
    if(esta_clave(clave)) {
        dato = consulta(clave);
        act = _baja(clave);
    }
    return dato;
}


Nodo* Diccionario::_baja(Clave clave){
    if(!act) return act;
    else if(clave < act->obtener_clave()) act->obtener_izq() = _baja(clave);
    else if(clave > act->obtener_clave)) act->obtener_der() = _baja(clave);
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
            act->obtener_der() = _baja(aux->obtener_clave());
        }
}
*/

Valor Diccionario::baja(Clave clave) {
	return _baja(clave, raiz);
}

Valor Diccionario::_baja(Clave clave, Nodo* padre) {
    Valor v = 0;
	if(raiz) {
		if(raiz->obtener_clave() == clave) {
			v = baja_raiz();
		} else {
			if(clave < padre->obtener_clave() && padre->obtener_izq()) {
				if(padre->obtener_izq()->obtener_clave() == clave) {
					v = baja_nodo(padre, padre->obtener_izq(), true);
				} else {
					v = _baja(clave, padre->obtener_izq());
				}
			} else if(clave > padre->obtener_clave() && padre->obtener_der()) {
				if(padre->obtener_der()->obtener_clave() == clave) {
					v = baja_nodo(padre, padre->obtener_der(), false);
				} else {
					v = _baja(clave, padre->obtener_der());
				}
			} else {
				cout << "clave no encontrada" << endl;
			}
		}
	} else {
		cout << "el dicc esta vacio brooo" << endl;
	}
	return v;
}

Valor Diccionario::baja_raiz() {
    Valor v = 0;
    Nodo* borrar = 0;
	if (raiz) { // if statement de mas? -> ya se contempla en removeNode (frank: yes)

		borrar = raiz; // nodo que queremos borrar del arbol

		// Caso 0 hijos
		if (!raiz->obtener_izq() && !raiz->obtener_der()) {
			raiz = 0;
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}

		// Caso 1 hijo
		else if (!raiz->obtener_izq() && raiz->obtener_der()) {// solo tiene hijo derecho
			raiz = raiz->obtener_der();
			//borrar->obtener_der() = 0; // aparentemente no es necesario
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}

		else if (!raiz->obtener_der() && raiz->obtener_izq()) {
			raiz = raiz->obtener_izq();
			//borrar->obtener_izq() = 0;
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}


		// Caso 2 hijos
		else {
			Nodo* menor_valor = buscar_min(raiz->obtener_der());
			_baja(menor_valor->obtener_clave(), raiz); // lo que seria RemoveNodePrivate() en el video
			// borro el nodo con menor valor y lo copio en la raiz
			raiz->copiar_nodo(menor_valor); // esto hay que ver si funca
		}
	}

	else {
		cout << "El arbol esta vacio." << endl; // extra if statement?
	}
	return v;
}

Valor Diccionario::baja_nodo(Nodo* padre, Nodo* nodo_borrar, bool izq) {
    Nodo* borrar = 0;
    Valor v = 0;
	if (raiz) { // extra if statement?
		Clave dato_nodo_borrar = nodo_borrar->obtener_clave();


		// Caso 0 hijos
		if (!nodo_borrar->obtener_izq() && !nodo_borrar->obtener_der()) {
			borrar = nodo_borrar;
			if (izq) padre->cambiar_izq(0);
			else padre->cambiar_der(0);
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}

		else if (!nodo_borrar->obtener_izq() && nodo_borrar->obtener_der()) { // el nodo a borrar tiene solo hijo der
			if (izq) padre->cambiar_izq(nodo_borrar->obtener_der()); // nodo_borrar es hijo izq de padre
			else padre->cambiar_der(nodo_borrar->obtener_der()); // nodo_borrar es hijo der de padre

			nodo_borrar->cambiar_der(0);
			borrar = nodo_borrar;
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}


		else if (!nodo_borrar->obtener_der() && nodo_borrar->obtener_izq()) { // el nodo a borrar tiene solo hijo izq
			if (izq) padre->cambiar_izq(nodo_borrar->obtener_izq()); // nodo_borrar es hijo izq de padre
			else padre->cambiar_der(nodo_borrar->obtener_izq()); // nodo_borrar es hijo der de padre

			nodo_borrar->cambiar_izq(0);
			borrar = nodo_borrar; // esto es extra but queda lindo xd
			v = borrar->obtener_valor();
			delete borrar;
			return v;
		}

		// Caso 2 hijos
		else {
			Nodo* menor_valor = buscar_min(nodo_borrar->obtener_der()); // encuentro el menor valor en el subarbol der
			_baja(menor_valor->obtener_clave(), nodo_borrar); // RemoveNodePrivate(), borro ese menor valor
			nodo_borrar->copiar_nodo(menor_valor); // "borro" el nodo a borrar reemplazando sus datos por los del menor_valor
		}
	}

	else { // extra if statement?
		cout << "El arbol esta vacio" << endl;
	}
	return v;
}

Nodo* Diccionario::obtener_raiz() {
    return raiz;
}

void Diccionario::imprimir_inorden(Nodo* aux) {
    // recorrido inorden: subarbol izquierdo - raiz - subarbol derecho
    if (aux != 0) { // caso base: raiz = 0, subarbol vacio, corta la recursividad
        imprimir_inorden(aux->obtener_izq());
        cout << aux->obtener_clave() << endl;
        imprimir_inorden(aux->obtener_der());
    }
}
