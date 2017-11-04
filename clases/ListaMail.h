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

    email getDato(int pos);

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

#endif //MAILMANAGER_LISTAMAIL_H