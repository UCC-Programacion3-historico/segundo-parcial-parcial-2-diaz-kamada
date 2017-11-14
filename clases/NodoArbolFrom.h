#include "../src/email.h"

#ifndef MAILMANAGER_NODOARBOLFROM_H
#define MAILMANAGER_NODOARBOLFROM_H

using namespace std;

class NodoArbolFrom {
private:

    NodoArbolFrom *izq, *der;
    email dato;

public:

    NodoArbolFrom(email dato);

    email getDato() const;

    void put(email d);

    void put(NodoArbolFrom *nodo);

    email search(email d);

    NodoArbolFrom *remover(unsigned long d);

    NodoArbolFrom *remover(email d);

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
        cout << dato.from << endl;
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

    if (d.from == dato.from){
        if (der == NULL)
            der = new NodoArbolFrom(d);     // mando los iguales a la derecha
        else
            der->put(d);
    }
    else if (d.from < dato.from) {          // va a la izq
        if (izq == NULL)
            izq = new NodoArbolFrom(d);
        else
            izq->put(d);
    } else {                                // va a la der
        if (der == NULL)
            der = new NodoArbolFrom(d);
        else
            der->put(d);
    }
}

void NodoArbolFrom::put(NodoArbolFrom *nodo) {
    if (nodo == NULL)
        return;
    if (nodo->getDato().from == dato.from){
        if (der == NULL)
            der = nodo;                                 // mando los iguales a la derecha
        else
            der->put(nodo);
    }
    else if (nodo->getDato().from < dato.from) {        // va a la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else {                                            // va a la der
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

email NodoArbolFrom::search(email d) { //CAMBIAR A BUSQUEDA POR ID PARA AGILIZAR LA BUSQUEDA
    if (d.from == dato.from && d.id == dato.id)
        return dato;
    if(d.from == dato.from){
        if (der == NULL)
            throw 3;
        else
            return der->search(d);
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


//REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR

NodoArbolFrom *NodoArbolFrom::remover(email d) {
    NodoArbolFrom *aux;
    if (d.from == dato.from && d.id == dato.id) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;

    }else if(d.from == dato.from){
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }

    } else if (d.from < dato.from) {
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

using std::cout;

void NodoArbolFrom::preorder() {
    cout << dato.from << endl;
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

void NodoArbolFrom::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato.from << endl;
    if (der != NULL) der->inorder();
}

void NodoArbolFrom::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << dato.from << endl;
}

#endif //MAILMANAGER_NODOARBOLFROM_H