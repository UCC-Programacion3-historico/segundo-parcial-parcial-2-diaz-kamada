#ifndef MAILMANAGER_NODOARBOLDATE_H
#define MAILMANAGER_NODOARBOLDATE_H

#include <iostream>
#include <string>
#include "../src/email.h"

using namespace std;

class NodoArbolDate {
private:

    NodoArbolDate *izq, *der;
    email dato;

public:

    NodoArbolDate(email dato);

    email getDato() const;

    void setDato(email dato);

    void put(email d);

    void put(NodoArbolDate *nodo);

    email search(email d);

    NodoArbolDate *remover(email param);

    void preorder();

    void inorder();

    void postorder();

    /*
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
        cout << dato << endl;
        if (izq != NULL) {
            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }
     */
};


NodoArbolDate::NodoArbolDate(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}


void NodoArbolDate::put(email d) {

    if (d == dato)
        throw 1;
    else if (d < dato) { // va a la izq
        if (izq == NULL)
            izq = new NodoArbolDate(d);
        else
            izq->put(d);
    } else { // va a la der
        if (der == NULL)
            der = new NodoArbolDate(d);
        else
            der->put(d);
    }
    //balanceo
}

void NodoArbolDate::put(NodoArbolDate *nodo) {

    if (nodo->getDato() == dato)
        throw 1;
    else if (nodo->getDato() < dato) { // va a la izq
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

email NodoArbolDate::search(email d) {
    if (d == dato) {
        return dato;
    } else if (d < dato) {
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

NodoArbolDate *NodoArbolDate::remover(email d) {
    NodoArbolDate *aux;
    if (d == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (d < dato) {
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

email NodoArbolDate::getDato() const {
    return dato;
}

void NodoArbolDate::setDato(email dato) {
    NodoArbolDate::dato = dato;
}

void NodoArbolDate::preorder() {
    cout << dato << ", ";
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

void NodoArbolDate::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato << ", ";
    if (der != NULL) der->inorder();
}

void NodoArbolDate::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << dato << ", ";
}

#endif //MAILMANAGER_NODOARBOLDATE_H