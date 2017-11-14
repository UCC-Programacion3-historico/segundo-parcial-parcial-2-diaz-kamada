#ifndef MAILMANAGER_NODOARBOLFROM_H
#define MAILMANAGER_NODOARBOLFROM_H

#include <iostream>
#include <string>
#include "../src/email.h"
#include "Lista.h"

using namespace std;

class NodoArbolFrom {
private:

    NodoArbolFrom *izq, *der;
    Lista<email> dato;          //lista de emails del mismo remitente
    string remitente;

public:

    NodoArbolFrom(email dato);

    Lista<email> getDato() const;

    void put(email d);

    void put(NodoArbolFrom *nodo);

    email search(email d);

    //NodoArbolFrom *remover(unsigned long d);

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
        cout << remitente << endl;
        if (izq != NULL) {
            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }

};


NodoArbolFrom::NodoArbolFrom(email d) {
    izq = NULL;
    der = NULL;
    remitente = d.from;                     //el remitente es igual al remitente del mail correspondiente al nodo
    dato.insertarUltimo(d);                 //se agrega a la lista el mail correspondiente al nodo
}

void NodoArbolFrom::put(email d) {

    if (d.from == remitente)
        dato.insertarUltimo(d);             //se agrega el mail a la lista del remitente
    else if (d.from < remitente) {          // va a la izq
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

    if (nodo->remitente == remitente)
        throw 3;
        //dato.insertarUltimo(nodo->getDato());       //se agrega el mail, correspondiente al ptr a nodo, a la lista
    else if (nodo->remitente < remitente) {    // va a la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else {                                        // va a la der
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

email NodoArbolFrom::search(email d) {
    if (d.from == remitente) {
        return dato.buscar(d);              //REVISARRRRRRRRRRRRRRRRRRRRR
    } else if (d.from < remitente) {
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
/*
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
*/

//REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR

NodoArbolFrom *NodoArbolFrom::remover(email d) {
    NodoArbolFrom *aux;
    if (d.from == remitente) {
        if(dato.getInicio() == NULL)                    //si no hay mails q tire error
            throw 3;
        dato.remover(dato.buscarpos(dato.buscar(d)));   //buscar(d) busca el email en la lista, buscarpos(email) busca la
                                                        //pos del email en la lista, y remover remueve el elemento de esa pos

        if(dato.getInicio() == NULL){                   //la logica aca es, si ya no hay mails, borrar el nodo
            if (der != NULL) {
                der->put(izq);
                return der;
            }
            return izq;
        }

    } else if (d.from < remitente) {
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

Lista<email> NodoArbolFrom::getDato() const {
    return dato;
}

using std::cout;

void NodoArbolFrom::preorder() {
    cout << remitente << endl;
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

void NodoArbolFrom::inorder() {
    if (izq != NULL) izq->inorder();
    cout << remitente << endl;
    if (der != NULL) der->inorder();
}

void NodoArbolFrom::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << remitente << endl;
}

#endif //MAILMANAGER_NODOARBOLFROM_H