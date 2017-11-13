#ifndef MAILMANAGER_ARBOLMAIL_H
#define MAILMANAGER_ARBOLMAIL_H


#include "NodoArbol.h"

class ArbolMail {
private:
    NodoArbol *raiz;
public:
    ArbolMail();

    void put(email dato);

    email search(email dato);

    email search(unsigned long dato);

    void remove(email dato);

    void remove(unsigned long dato);

    void preorder();

    void inorder();

    void postorder();

    ~ArbolMail();

    bool esVacio();

    void print();

};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
ArbolMail::ArbolMail() {
    raiz = NULL;
}


/**
 * Destructor del Arbol
 */
ArbolMail::~ArbolMail() {

}


/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
email ArbolMail::search(email dato) {

    if (raiz == NULL) {
        throw 3;
    } else {
        return raiz->search(dato);
    }
}

email ArbolMail::search(unsigned long dato) {

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
void ArbolMail::put(email dato) {
    if (raiz == NULL) {
        raiz = new NodoArbol(dato);
    } else {
        raiz->put(dato);
    }
}


/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
void ArbolMail::remove(email dato) {
    NodoArbol *aux;
    if (raiz == NULL) {
        throw 6;
    } else {
        aux = raiz;
        raiz = raiz->remover(dato);
        if (raiz != aux)
            delete aux;
    }
}

void ArbolMail::remove(unsigned long dato) {
    NodoArbol *aux;
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
bool ArbolMail::esVacio() {
    return raiz == NULL;
}


/**
 * Recorre un árbol en preorden
 */
void ArbolMail::preorder() {
    if (raiz != NULL) {
        raiz->preorder();
    }
}


/**
 * Recorre un árbol en orden
 */
void ArbolMail::inorder() {
    if (raiz != NULL) {
        raiz->inorder();
    }
}


/**
 * Recorre un árbol en postorden
 */
void ArbolMail::postorder() {
    if (raiz != NULL) {
        raiz->postorder();
    }
}


/**
 * Muestra un árbol por consola
 */
void ArbolMail::print() {

    if (raiz != NULL) {
        raiz->print(false, "");
    }
}


#endif //MAILMANAGER_ARBOLMAIL_H