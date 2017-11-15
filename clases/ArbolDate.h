#include "NodoArbolDate.h"

#ifndef MAILMANAGER_ARBOLDATE_H
#define MAILMANAGER_ARBOLDATE_H

class ArbolDate {
private:
    NodoArbolDate *raiz;
public:
    ArbolDate();

    void put(email dato);

    void remove(email dato);

    void inorder(vector<email> &v);

    void inorderfiltrado(vector<email> &v, string &desde, string &hasta);

    void print();

};


/**
 * Constructor del Arbol
 */
ArbolDate::ArbolDate() {
    raiz = NULL;
}

/**
 * Agrega un email al árbol
 * @param dato email
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
 * Recorre el arbol en orden, de modo que llena un vector con los emails y quedan ordenados
 * @param v vector
 */
void ArbolDate::inorder(vector<email> &v) {
    if (raiz != NULL) {
        raiz->inorder(v);
    }
}

/**
 * Recorre el arbol en orden, de modo que llena un vector con los emails y quedan ordenados
 * solo pone en el vector los emails que cumplen con el rango de fechas
 * @param v vector
 * @param desde
 * @param hasta
 */
void ArbolDate::inorderfiltrado(vector<email> &v, string &desde, string &hasta) {
    if (raiz != NULL) {
        raiz->inorderfiltrado(v,desde,hasta);
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