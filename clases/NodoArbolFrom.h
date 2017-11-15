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

    void search(string &s, vector<email> &v);

    NodoArbolFrom *remover(unsigned long d);

    NodoArbolFrom *remover(email d);

    void inorder(vector<email> &v);

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

/**
 * Constructor de NodoArbolFrom
 * @param dato email
 */
NodoArbolFrom::NodoArbolFrom(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}

/**
 * Iserta un nuevo nodo con el email pasado como parametro
 * @param d email
 */
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

/**
 * Agrega un puntero a un nodo como nodo
 * @param *nodo
 */
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

/**
 * Busca y agrega a un vector todos los mails correspondientes a un remitente
 * @param s remitente
 * @param v vector
 */
void NodoArbolFrom::search(string &s, vector<email> &v) {
    if(s == dato.from){
        v.insert(v.end(),dato);
        if(der == NULL)
            return;
        else
            der->search(s,v);
    }
    else{
        if(s < dato.from)
            if(izq == NULL)
                return;
            else
                izq->search(s,v);
        else{
            if(der == NULL)
                return;
            else
                der->search(s,v);
        }
    }
}

/**
 * Funcion que remueve un email y devuelve un puntero a un nodo, que corresponde al nodo que mantiene
 * el balance del arbol y reemplaza el nodo a remover
 * @param d
 * @return *nodo
 */
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

/**
 * Funcion que remueve un email y devuelve un puntero a un nodo, que corresponde al nodo que mantiene
 * el balance del arbol y reemplaza el nodo a remover
 * @param d email
 * @return *nodo
 */
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

/**
 * devuelve el email correspondiente al nodo
 * @return email
 */
email NodoArbolFrom::getDato() const {
    return dato;
}

/**
 * Recorre el arbol en orden llenando un vector para que queden los mails ordenados por remitente en el vector
 * @param v vector
 */
void NodoArbolFrom::inorder(vector<email> &v) {
    if (izq != NULL) izq->inorder(v);
    v.insert(v.end(),dato);
    if (der != NULL) der->inorder(v);
}

#endif //MAILMANAGER_NODOARBOLFROM_H