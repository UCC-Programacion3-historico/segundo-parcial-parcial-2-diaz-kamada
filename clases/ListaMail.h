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
//para hacerlo hay q hacer el constructor por copia de email tambien
}

/**
 *
 */
ListaMail::~ListaMail() {
    vaciar();
}

/**
 *
 * @return
 */
bool ListaMail::esVacia() {
    return inicio == NULL;
}

/**
 *
 * @return
 */
int ListaMail::getTamanio() {
    NodoMail *aux = inicio;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}

/**
 *
 * @param pos
 * @param mail
 */
void ListaMail::insertar(int pos, email mail) {
    int cont = 0;
    NodoMail *aux = inicio;

    if (pos == 0) {
        NodoMail *nn = new NodoMail(mail, inicio);
        inicio = nn;
        return;
    }

    while (cont < pos - 1 && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL)
        throw 1;

    NodoMail *nn = new NodoMail(mail, aux->getNext());
    aux->setNext(nn);
}

/**
 *
 * @param mail
 */
void ListaMail::insertarPrimero(email mail) {
    NodoMail *nn = new NodoMail(mail, inicio);
    inicio = nn;
}

/**
 *
 * @param mail
 */
void ListaMail::insertarUltimo(email mail) {
    if (NULL == inicio) {
        inicio = new NodoMail(mail, NULL);
        return;
    }

    NodoMail *aux = inicio;
    while (aux->getNext() != NULL) {
        aux = aux->getNext();
    }
    NodoMail *nn = new NodoMail(mail, NULL);
    aux->setNext(nn);
}

 /**
  *
  * @param pos
  */
void ListaMail::remover(int pos) {
    int cont = 0;
    NodoMail *aux = inicio;

    if (pos == 0) {

        if (inicio == NULL)
            throw 1;

        inicio = inicio->getNext();
        delete[] aux;
        return;
    }

    while (cont < pos - 1 && aux->getNext() != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux->getNext() == NULL)
        throw 1;

    NodoMail *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete[] tmp;
}

/**
 *
 * @param pos
 * @return
 */
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

/**
 *
 * @param pos
 * @param mail
 */
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

/**
 *
 */
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