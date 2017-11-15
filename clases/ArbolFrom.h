#include "NodoArbolFrom.h"

#ifndef MAILMANAGER_ARBOLFROM_H
#define MAILMANAGER_ARBOLFROM_H

class ArbolFrom {
private:
    NodoArbolFrom *raiz;
public:
    ArbolFrom();

    void put(email dato);

    email search(email dato);

    void remove(email dato);

    void preorder();

    void inorder(vector<email> &v);

    void postorder();

    ~ArbolFrom();

    bool esVacio();

    void print();

};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */

ArbolFrom::ArbolFrom() {
    raiz = NULL;
}


/**
 * Destructor del Arbol
 */
ArbolFrom::~ArbolFrom() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */

email ArbolFrom::search(email dato) {

    if (raiz == NULL) {
        throw 3;
    } else {
        return raiz->search(dato);
    }
}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
void ArbolFrom::put(email dato) {
    if (raiz == NULL) {
        raiz = new NodoArbolFrom(dato);
    } else {
        raiz->put(dato);
    }
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
void ArbolFrom::remove(email dato) {        //REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR
    NodoArbolFrom *aux;
    if (raiz == NULL) {
        throw 6;
    } else {
        aux = raiz;
        raiz = raiz->remover(dato);
        if (raiz != aux)
            delete aux;
    }
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
bool ArbolFrom::esVacio() {
    return raiz == NULL;
}


/**
 * Recorre un árbol en preorden
 */
void ArbolFrom::preorder() {
    if (raiz != NULL) {
        raiz->preorder();
    }
}


/**
 * Recorre un árbol en orden
 */
void ArbolFrom::inorder(vector<email> &v) {
    if (raiz != NULL) {
        raiz->inorder(v);
    }
}


/**
 * Recorre un árbol en postorden
 */
void ArbolFrom::postorder() {
    if (raiz != NULL) {
        raiz->postorder();
    }
}

void ArbolFrom::print() {

    if (raiz != NULL) {
        raiz->print(false, "");
    }
}

#endif //MAILMANAGER_ARBOLFROM_H