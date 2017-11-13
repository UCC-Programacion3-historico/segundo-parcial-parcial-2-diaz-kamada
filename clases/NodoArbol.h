#ifndef MAILMANAGER_NODOARBOL_H
#define MAILMANAGER_NODOARBOL_H

#include <iostream>
#include <string>
#include "../src/email.h"

using namespace std;

class NodoArbol {
private:

    NodoArbol *izq, *der;
    email dato;

public:

    NodoArbol(email dato);

    email getDato() const;

    void setDato(email dato);

    void put(email d);

    void put(NodoArbol *nodo);

    email search(email d);

    email search(unsigned long d);

    NodoArbol *remover(email d);

    NodoArbol *remover(unsigned long d);

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


NodoArbol::NodoArbol(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}


void NodoArbol::put(email d) {

    if (d.id == dato.id)
        throw 1;
    else if (d.id < dato.id) { // va a la izq
        if (izq == NULL)
            izq = new NodoArbol(d);
        else
            izq->put(d);
    } else { // va a la der
        if (der == NULL)
            der = new NodoArbol(d);
        else
            der->put(d);
    }
}


void NodoArbol::put(NodoArbol *nodo) {

    if (nodo->getDato().id == dato.id)
        throw 1;
    else if (nodo->getDato().id < dato.id) { // va a la izq
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


email NodoArbol::search(email d) {
    if (d.id == dato.id) {
        return dato;
    } else if (d.id < dato.id) {
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

email NodoArbol::search(unsigned long d) {
    if (d == dato.id) {
        return dato;
    } else if (d < dato.id) {
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

NodoArbol *NodoArbol::remover(email d) {
    NodoArbol *aux;
    if (d.id == dato.id) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (d.id < dato.id) {
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

NodoArbol *NodoArbol::remover(unsigned long d) {
    NodoArbol *aux;
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

email NodoArbol::getDato() const {
    return dato;
}


void NodoArbol::setDato(email dato) {
    NodoArbol::dato = dato;
}


void NodoArbol::preorder() {
    dato.mostrar();
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}


void NodoArbol::inorder() {
    if (izq != NULL) izq->inorder();
    dato.mostrar();
    if (der != NULL) der->inorder();
}


void NodoArbol::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    dato.mostrar();
}


#endif //MAILMANAGER_NODOARBOL_H