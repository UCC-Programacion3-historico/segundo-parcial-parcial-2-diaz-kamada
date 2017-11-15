#include "NodoArbol.h"

#ifndef MAILMANAGER_ARBOLMAIL_H
#define MAILMANAGER_ARBOLMAIL_H

class ArbolMail {
private:
    NodoArbol *raiz;
public:
    ArbolMail();

    void put(email dato);

    email search(unsigned long dato);

    void searchsubject(string &s, vector<email> &v);

    void searchcontent(string &s, vector<email> &v);

    void remove(unsigned long dato);

    void print();

};


/**
 * Constructor del Arbol
 */
ArbolMail::ArbolMail() {
    raiz = NULL;
}

/**
 * Busca un email por su id en el arbol y lo devuelve
 * @param dato
 * @return email buscado
 */
email ArbolMail::search(unsigned long dato) {
    if (raiz == NULL) {
        throw 3;
    } else {
        return raiz->search(dato);
    }
}
/**
 * Busca en los asuntos de emails del arbol la palabra s pasada como parametro y agrega el email al vector
 * si se encuentra la palabra en el mismo
 * @param s
 * @param v
 */
void ArbolMail::searchsubject(string &s, vector<email> &v) {
    if (raiz != NULL) {
        raiz->searchsubject(s,v);
    }
}
/**
 * Busca en los contenidos de los emails del arbol la palabra s pasada como parametro y agrega el email al vector
 * si se encuentra la palabra en el mismo
 * @param s
 * @param v
 */
void ArbolMail::searchcontent(string &s, vector<email> &v) {
    if (raiz != NULL) {
        raiz->searchcontent(s,v);
    }
}

/**
 * Agrega un email al árbol
 * @param dato email
 */
void ArbolMail::put(email dato) {
    if (raiz == NULL) {
        raiz = new NodoArbol(dato);
    } else {
        raiz->put(dato);
    }
}

/**
 * Elimina un email del arbol a partir de su id
 * @param dato
 */
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
 * Muestra un árbol por consola
 */
void ArbolMail::print() {

    if (raiz != NULL) {
        raiz->print(false, "");
    }
}


#endif //MAILMANAGER_ARBOLMAIL_H