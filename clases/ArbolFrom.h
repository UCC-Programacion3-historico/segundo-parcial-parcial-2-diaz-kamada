#include "NodoArbolFrom.h"

#ifndef MAILMANAGER_ARBOLFROM_H
#define MAILMANAGER_ARBOLFROM_H

class ArbolFrom {
private:
    NodoArbolFrom *raiz;
public:
    ArbolFrom();

    void put(email dato);

    void search(string &s, vector<email> &v);

    void remove(email dato);

    void inorder(vector<email> &v);

    void print();

};


/**
 * Constructor del Arbol
 */
ArbolFrom::ArbolFrom() {
    raiz = NULL;
}

/**
 * Busca y agrega a un vector todos los emails del mismo remitente
 * @param s remitente
 * @param v vector
 */
void ArbolFrom::search(string &s, vector<email> &v) {
    if (raiz == NULL) {
        return;
    } else {
        return raiz->search(s,v);
    }
}


/**
 * Agrega un email al árbol
 * @param dato email a agregar
 */
void ArbolFrom::put(email dato) {
    if (raiz == NULL) {
        raiz = new NodoArbolFrom(dato);
    } else {
        raiz->put(dato);
    }
}


/**
 * Elimina un email del árbol
 * @param dato email a borrar
 */
void ArbolFrom::remove(email dato) {
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
 * Recorre el arbol en orden y llena un vector a medida que lo hace
 * de modo que el vector queda ordenado por los remitentes
 */
void ArbolFrom::inorder(vector<email> &v) {
    if (raiz != NULL) {
        raiz->inorder(v);
    }
}

/**
 * Muestra un arbol por consola
 */
void ArbolFrom::print() {

    if (raiz != NULL) {
        raiz->print(false, "");
    }
}

#endif //MAILMANAGER_ARBOLFROM_H