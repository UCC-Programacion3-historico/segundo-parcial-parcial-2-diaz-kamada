#ifndef MAILMANAGER_NODOARBOLFROM_H
#define MAILMANAGER_NODOARBOLFROM_H

#include <iostream>
#include <string>
#include "../src/email.h"

using namespace std;

class NodoArbolFrom {
private:

    NodoArbolFrom *izq, *der;
    email dato;

public:

    NodoArbolFrom(email dato);

    email getDato() const;

    void setDato(email dato);

    void put(email d);

    void put(NodoArbolFrom *nodo);

    email search(email d);

    NodoArbolFrom *remover(unsigned long d);

    void preorder();

    void inorder();

    void postorder();

    void print(bool esDerecho, string identacion) {
        if (der != NULL) {
            der->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << dato.id << endl;
        if (izq != NULL) {
            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

};


NodoArbolFrom::NodoArbolFrom(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}

void NodoArbolFrom::put(email d) {

    if (d.from == dato.from)
        throw 1;
    else if (d.from < dato.from) { // va a la izq
        if (izq == NULL)
            izq = new NodoArbolFrom(d);
        else
            izq->put(d);
    } else { // va a la der
        if (der == NULL)
            der = new NodoArbolFrom(d);
        else
            der->put(d);
    }
}

void NodoArbolFrom::put(NodoArbolFrom *nodo) {

    if (nodo->getDato().from == dato.from)
        throw 1;
    else if (nodo->getDato().from < dato.from) { // va a la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else { // va a la der
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

email NodoArbolFrom::search(email d) {
    if (d.from == dato.from) {
        return dato;
    } else if (d.from < dato.from) {
        if (izq == NULL)
            throw 3;
        else
            return izq->search(d);
    } else {
        if (der == NULL)
            throw 3;
        else
            return der->search(d);
    }
}

NodoArbolFrom *NodoArbolFrom::remover(unsigned long d) {
    NodoArbolFrom *aux;
    if (d == dato.id) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (d < dato.id) {
        if (izq == NULL)
            throw 3;
        else {
            aux = izq;
            izq = izq->remover(d);
            if (izq != aux)
                delete aux;
        }
    } else {
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }
    }
    return this;
}

email NodoArbolFrom::getDato() const {
    return dato;
}

void NodoArbolFrom::setDato(email dato) {
    NodoArbolFrom::dato = dato;
}

void NodoArbolFrom::preorder() {
    dato.mostrar();
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

void NodoArbolFrom::inorder() {
    if (izq != NULL) izq->inorder();
    dato.mostrar();
    if (der != NULL) der->inorder();
}

void NodoArbolFrom::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    dato.mostrar();
}

#endif //MAILMANAGER_NODOARBOLFROM_H