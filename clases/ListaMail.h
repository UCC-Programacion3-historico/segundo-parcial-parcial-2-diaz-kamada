#ifndef MAILMANAGER_LISTAMAIL_H
#define MAILMANAGER_LISTAMAIL_H

#include "NodoMail.h"

class ListaMail{
private:
    NodoMail *inicio;
public:
    ListaMail();

    ListaMail(const ListaMail &li);

    ~ListaMail();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, email mail);

    void insertarPrimero(email mail);

    void insertarUltimo(email mail);

    void remover(int pos);

    email getMail(int pos);

    void reemplazar(int pos, email mail);

    void vaciar();

};

/**
 *
 */
ListaMail::ListaMail() {
    inicio=NULL;
}

/**
 *
 * @param li
 */
ListaMail::ListaMail(const ListaMail &li) {

}

/**
 *
 */
ListaMail::~ListaMail() {
    vaciar();
}

bool ListaMail::esVacia() {
    return inicio == NULL;
}

email ListaMail::getMail(int pos) {
    int i = 0;
    NodoMail *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    return aux->getMail();
}


void ListaMail::reemplazar(int pos, email mail) {
    int i = 0;
    NodoMail *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    aux->setMail(mail);
}


void ListaMail::vaciar() {
    NodoMail *borr;
    NodoMail *aux = inicio;

    while (aux != NULL) {
        borr = aux;
        aux = aux->getNext();
        delete[] borr;
    }
    inicio = NULL;
}

#endif //MAILMANAGER_LISTAMAIL_H