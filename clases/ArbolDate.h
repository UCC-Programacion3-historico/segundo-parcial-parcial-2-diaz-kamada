#include "NodoArbolDate.h"

#ifndef MAILMANAGER_ARBOLDATE_H
#define MAILMANAGER_ARBOLDATE_H

class ArbolDate {
private:
    NodoArbolDate *raiz;
public:
    ArbolDate();

    void put(email dato);

    email search(email dato);

    void remove(unsigned long dato);

    void remove(email dato);

    void preorder();

    void inorder(vector<email> &v);

    void inorderfiltrado(vector<email> &v, string &desde, string &hasta);

    void postorder();

    ~ArbolDate();

    bool esVacio();

    void print();

};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
ArbolDate::ArbolDate() {
    raiz = NULL;
}


/**
 * Destructor del Arbol
 */
ArbolDate::~ArbolDate() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
email ArbolDate::search(email dato) {

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
void ArbolDate::put(email dato) {
    if (raiz == NULL) {
        raiz = new NodoArbolDate(dato);
    } else {
        raiz->put(dato);
    }
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
void ArbolDate::remove(unsigned long dato) {
    NodoArbolDate *aux;
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
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
void ArbolDate::remove(email dato) {
    NodoArbolDate *aux;
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
bool ArbolDate::esVacio() {
    return raiz == NULL;
}


/**
 * Recorre un árbol en preorden
 */
void ArbolDate::preorder() {
    if (raiz != NULL) {
        raiz->preorder();
    }
}


/**
 * Recorre un árbol en orden
 */
void ArbolDate::inorder(vector<email> &v) {
    if (raiz != NULL) {
        raiz->inorder(v);
    }
}

void ArbolDate::inorderfiltrado(vector<email> &v, string &desde, string &hasta) {
    if (raiz != NULL) {
        raiz->inorderfiltrado(v,desde,hasta);
    }
}


/**
 * Recorre un árbol en postorden
 */
void ArbolDate::postorder() {
    if (raiz != NULL) {
        raiz->postorder();
    }
}

/**
 * Muestra un árbol por consola
*/
void ArbolDate::print() {

    if (raiz != NULL) {
        raiz->print(false, "");
    }
}

#endif //MAILMANAGER_ARBOLDATE_H