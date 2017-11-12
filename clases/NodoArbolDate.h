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

    NodoArbolDate *remover(unsigned long d);

    NodoArbolDate *remover(email param);

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


NodoArbolDate::NodoArbolDate(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}


void NodoArbolDate::put(email d) {
    if (d.date == dato.date) {                      //si las fechas son iguales lo mando a la derecha
        if (der == NULL)
            der = new NodoArbolDate(d);
        else
            der->put(d);
    }

    else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                   //aux1 y aux2 son iguales a los años
            aux1[i] = d.date[i];
            aux2[i] = dato.date[i];
        }
        if (aux1 < aux2) {
            if (izq == NULL)
                izq = new NodoArbolDate(d);
            else
                izq->put(d);
        } else if (aux1 > aux2) {
            if (der == NULL)
                der = new NodoArbolDate(d);
            else
                der->put(d);
        }

        else if (aux1 == aux2) {                    //si los años son iguales comparo los meses
            aux1 = "";
            aux2 = "";
            for (i = 5; i < 7; i++) {               //aux1 y aux2 son iguales a los meses
                aux1[i] = d.date[i];
                aux2[i] = dato.date[i];
            }
            if (aux1 < aux2) {
                if (izq == NULL)
                    izq = new NodoArbolDate(d);
                else
                    izq->put(d);
            } else if (aux1 > aux2) {
                if (der == NULL)
                    der = new NodoArbolDate(d);
                else
                    der->put(d);
            }

            else if (aux1 == aux2) {                //si los meses son iguales comparo los dias
                aux1 = "";
                aux2 = "";
                for (i = 8; i < 10; i++) {          //aux1 y aux2 son iguales a los dias
                    aux1[i] = d.date[i];
                    aux2[i] = dato.date[i];
                }
                if (aux1 < aux2) {
                    if (izq == NULL)
                        izq = new NodoArbolDate(d);
                    else
                        izq->put(d);
                } else if (aux1 > aux2) {
                    if (der == NULL)
                        der = new NodoArbolDate(d);
                    else
                        der->put(d);
                }
            }
        }
    }
}

void NodoArbolDate::put(NodoArbolDate *nodo) {
    if (nodo->getDato().date == dato.date) {            //si las fechas son iguales lo mando a la derecha
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }

    else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                       //aux1 y aux2 son iguales a los años
            aux1[i] = nodo->getDato().date[i];
            aux2[i] = dato.date[i];
        }
        if (aux1 < aux2) {
            if (izq == NULL)
                izq = nodo;
            else
                izq->put(nodo);
        } else if (aux1 > aux2) {
            if (der == NULL)
                der = nodo;
            else
                der->put(nodo);
        }

        else if (aux1 == aux2) {                        //si los años son iguales comparo los meses
            aux1 = "";
            aux2 = "";
            for (i = 5; i < 7; i++) {                   //aux1 y aux2 son iguales a los meses
                aux1[i] = nodo->getDato().date[i];
                aux2[i] = dato.date[i];
            }
            if (aux1 < aux2) {
                if (izq == NULL)
                    izq = nodo;
                else
                    izq->put(nodo);
            } else if (aux1 > aux2) {
                if (der == NULL)
                    der = nodo;
                else
                    der->put(nodo);
            }

            else if (aux1 == aux2) {                    //si los meses son iguales comparo los dias
                aux1 = "";
                aux2 = "";
                for (i = 8; i < 10; i++) {              //aux1 y aux2 son iguales a los dias
                    aux1[i] = nodo->getDato().date[i];
                    aux2[i] = dato.date[i];
                }
                if (aux1 < aux2) {
                    if (izq == NULL)
                        izq = nodo;
                    else
                        izq->put(nodo);
                } else if (aux1 > aux2) {
                    if (der == NULL)
                        der = nodo;
                    else
                        der->put(nodo);
                }
            }
        }
    }
}

email NodoArbolDate::search(email d) { //cambiar a busqueda por id IMPORTANTE
    if (d.date == dato.date) {
        return dato;
    } else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                      //aux1 y aux2 son iguales a los años
            aux1[i] = d.date[i];
            aux2[i] = dato.date[i];
        }
        if (aux1 < aux2) {
            if (izq == NULL)
                throw 3;
            else
                return izq->search(d);
        } else if (aux1 > aux2) {
            if (der == NULL)
                throw 3;
            else
                return der->search(d);
        } else if (aux1 == aux2) {                     //si los años son iguales comparo los meses
            aux1 = "";
            aux2 = "";
            for (i = 5; i < 7; i++) {                 //aux1 y aux2 son iguales a los meses
                aux1[i] = d.date[i];
                aux2[i] = dato.date[i];
            }
            if (aux1 < aux2) {
                if (izq == NULL)
                    throw 3;
                else
                    return izq->search(d);
            } else if (aux1 > aux2) {
                if (der == NULL)
                    throw 3;
                else
                    return der->search(d);
            } else if (aux1 == aux2) {                 //si los meses son iguales comparo los dias
                aux1 = "";
                aux2 = "";
                for (i = 8; i < 10; i++) {             //aux1 y aux2 son iguales a los dias
                    aux1[i] = d.date[i];
                    aux2[i] = dato.date[i];
                }
                if (aux1 < aux2) {
                    if (izq == NULL)
                        throw 3;
                    else
                        return izq->search(d);
                } else if (aux1 > aux2) {
                    if (der == NULL)
                        throw 3;
                    else
                        return der->search(d);
                }
            }
        }
    }
}

NodoArbolDate *NodoArbolDate::remover(unsigned long d) {
    NodoArbolDate *aux;
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

NodoArbolDate *NodoArbolDate::remover(email d) {
    NodoArbolDate *aux;
    if (d.date == dato.date) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;

    } else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                      //aux1 y aux2 son iguales a los años
            aux1[i] = d.date[i];
            aux2[i] = dato.date[i];
        }
        if (aux1 < aux2) {
            if (izq == NULL)
                throw 3;
            else {
                aux = izq;
                izq = izq->remover(d);
                if (izq != aux)
                    delete aux;
            }
        } else if (aux1 > aux2) {
            if (der == NULL)
                throw 3;
            else {
                aux = der;
                der = der->remover(d);
                if (der != aux)
                    delete aux;
            }
        }

        else if (aux1 == aux2) {                        //si los años son iguales comparo los meses
            aux1 = "";
            aux2 = "";
            for (i = 5; i < 7; i++) {                   //aux1 y aux2 son iguales a los meses
                aux1[i] = d.date[i];
                aux2[i] = dato.date[i];
            }
            if (aux1 < aux2) {
                if (izq == NULL)
                    throw 3;
                else {
                    aux = izq;
                    izq = izq->remover(d);
                    if (izq != aux)
                        delete aux;
                }
            } else if (aux1 > aux2) {
                if (der == NULL)
                    throw 3;
                else {
                    aux = der;
                    der = der->remover(d);
                    if (der != aux)
                        delete aux;
                }
            }

            else if (aux1 == aux2) {                       //si los meses son iguales comparo los dias
                aux1 = "";
                aux2 = "";
                for (i = 8; i < 10; i++) {                 //aux1 y aux2 son iguales a los dias
                    aux1[i] = d.date[i];
                    aux2[i] = dato.date[i];
                }
                if (aux1 < aux2) {
                    if (izq == NULL)
                        throw 3;
                    else {
                        aux = izq;
                        izq = izq->remover(d);
                        if (izq != aux)
                            delete aux;
                    }
                } else if (aux1 > aux2) {
                    if (der == NULL)
                        throw 3;
                    else {
                        aux = der;
                        der = der->remover(d);
                        if (der != aux)
                            delete aux;
                    }
                }
            }
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
    dato.mostrar();
    cout << endl;
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

void NodoArbolDate::inorder() {
    if (izq != NULL) izq->inorder();
    dato.mostrar();
    cout << endl;
    if (der != NULL) der->inorder();
}

void NodoArbolDate::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    dato.mostrar();
    cout << endl;
}

#endif //MAILMANAGER_NODOARBOLDATE_H