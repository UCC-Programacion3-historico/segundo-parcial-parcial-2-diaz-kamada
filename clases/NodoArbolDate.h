#include "../src/email.h"

#ifndef MAILMANAGER_NODOARBOLDATE_H
#define MAILMANAGER_NODOARBOLDATE_H

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

    NodoArbolDate *remover(email d);

    void preorder();

    void inorder(vector<email> &v);

    void inorderfiltrado(vector<email> &v, string &desde, string &hasta);

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
            aux1 += d.date[i];
            aux2 += dato.date[i];
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
                aux1 += d.date[i];
                aux2 += dato.date[i];
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
                    aux1 += d.date[i];
                    aux2 += dato.date[i];
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
    if(nodo == NULL)
        return;

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
            aux1 += nodo->getDato().date[i];
            aux2 += dato.date[i];
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
                aux1 += nodo->getDato().date[i];
                aux2 += dato.date[i];
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
                    aux1 += nodo->getDato().date[i];
                    aux2 += dato.date[i];
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

email NodoArbolDate::search(email d) { //cambiar a busqueda por id IMPORTANTE PARA CUANDO SE IMPLEMENTE LA BUSQUEDA
    if (d.date == dato.date && d.id == dato.id)
        return dato;
    if(d.date == dato.date){
        if (der == NULL)                              //si son iguales sigo buscando por derecha
            throw 3;
        else
            return der->search(d);
    } else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                      //aux1 y aux2 son iguales a los años
            aux1 += d.date[i];
            aux2 += dato.date[i];
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
                aux1 += d.date[i];
                aux2 += dato.date[i];
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
                    aux1 += d.date[i];
                    aux2 += dato.date[i];
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
    if (d.date == dato.date && d.id == dato.id) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;

    }else if(d.date == dato.date){
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }
    }

    else {

        int i;
        string aux1, aux2;

        for (i = 0; i < 4; i++) {                      //aux1 y aux2 son iguales a los años
            aux1 += d.date[i];
            aux2 += dato.date[i];
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
        } else if (aux1 > aux2 ) {
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
                aux1 += d.date[i];
                aux2 += dato.date[i];
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
                    aux1 += d.date[i];
                    aux2 += dato.date[i];
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

void NodoArbolDate::inorder(vector<email> &v) {
    if (izq != NULL) izq->inorder(v);
    v.insert(v.end(),dato);
    if (der != NULL) der->inorder(v);
}

void NodoArbolDate::inorderfiltrado(vector<email> &v, string &desde, string &hasta) {   //REVISAR REVISAR REVISAR
    if (izq != NULL) izq->inorderfiltrado(v, desde, hasta);

    if (desde == dato.date || hasta == dato.date) {
        v.insert(v.end(), dato);
    } else {
        int i;
        string aux1 = "", aux2 = "", aux3 = "";

        for (i = 0; i < 4; i++) {                    //aux1, aux2 y aux3 son iguales a los años
            aux1 += desde[i];
            aux2 += dato.date[i];
            aux3 += hasta[i];
        }

        if (aux1 <= aux2 && aux2 <= aux3) {           //supongamos que los años no generan problema, pasamos a los meses
            aux1 = "";
            aux2 = "";
            aux3 = "";
            for (i = 5; i < 7; i++) {                 //aux1, aux2 y aux3 son iguales a los meses
                aux1 += desde[i];
                aux2 += dato.date[i];
                aux3 += hasta[i];
            }

            if (aux1 <= aux2 && aux2 <= aux3) {  //supongamos que los meses no generan problema
                if (aux1 == aux2) {              //si el mes del dato es igual al mes del limite inferior
                    aux1 = "";
                    aux2 = "";
                    aux3 = "";
                    for (i = 8; i < 10; i++) {      //comparamos los dias
                        aux1 += desde[i];
                        aux2 += dato.date[i];
                        aux3 += hasta[i];
                    }
                    if (aux1 <= aux2)               //si el dia del lim inferior es menor o igual al dato, agrego al vec
                        v.insert(v.end(), dato);

                } else if (aux3 == aux2) {      //si el mes del dato es igual al mes del limite superior
                    aux1 = "";
                    aux2 = "";
                    aux3 = "";
                    for (i = 8; i < 10; i++) {      //comparamos los dias
                        aux1 += desde[i];
                        aux2 += dato.date[i];
                        aux3 += hasta[i];
                    }
                    if (aux2 <= aux3)           //si el dia del lim superior es mayor o igual al dato, agrego al vec
                        v.insert(v.end(), dato);

                } else if(aux2!=aux1 && aux2!=aux3)
                    v.insert(v.end(), dato);        //si el mes no es igual a ninguno de los meses limites agrego
            }
        }
    }
    if (der != NULL) der->inorderfiltrado(v, desde, hasta);
}

void NodoArbolDate::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    dato.mostrar();
    cout << endl;
}

#endif //MAILMANAGER_NODOARBOLDATE_H