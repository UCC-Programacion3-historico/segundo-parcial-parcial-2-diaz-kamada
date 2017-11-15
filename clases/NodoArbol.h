#include "../src/email.h"

#ifndef MAILMANAGER_NODOARBOL_H
#define MAILMANAGER_NODOARBOL_H

using namespace std;

class NodoArbol {
private:

    NodoArbol *izq, *der;
    email dato;

public:

    NodoArbol(email dato);

    email getDato() const;

    void put(email d);

    void put(NodoArbol *nodo);

    email search(unsigned long d);

    void searchsubject(string &s,vector<email> &v);

    void searchcontent(string &s,vector<email> &v);

    NodoArbol *remover(email d);

    NodoArbol *remover(unsigned long d);

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

/**
 * Constructor de la clase NodoArbol
 * @param dato
 */
NodoArbol::NodoArbol(email dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}

/**
 * Agrega un nodo con el email pasado como parametro
 * @param d
 */
void NodoArbol::put(email d) {

    if (d.id == dato.id)
        throw 1;                    //no pueden haber 2 mails con el mismo id
    else if (d.id < dato.id) {      // va a la izq
        if (izq == NULL)
            izq = new NodoArbol(d);
        else
            izq->put(d);
    } else {                        // va a la der
        if (der == NULL)
            der = new NodoArbol(d);
        else
            der->put(d);
    }
}

/**
 * Agrega un puntero a un nodo como nodo
 * @param nodo
 */
void NodoArbol::put(NodoArbol *nodo) {
    if(nodo == NULL)
        return;
    if (nodo->getDato().id == dato.id)
        throw 1;
    else if (nodo->getDato().id < dato.id) {    // va a la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else {                                    // va a la der
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

/**
 * Busca un email en el arbol por su id y lo devuelve
 * @param d
 * @return email
 */
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

/**
 * Funcion que toma una palabra como parametro y la agrega al final del vector
 * si la palabra esta en el asunto del email
 * @param s
 * @param v
 */
void NodoArbol::searchsubject(string &s, vector<email> &v) {
    if (izq != NULL) izq->searchsubject(s,v);

    if(dato.subject == s)
        v.insert(v.end(),dato);
    else{
        int i,j,h,f;
        int l = dato.subject.length();
        int c = s.length();

        for(h=0; h<l; h++){
            f=0;
            if(s[0] == dato.subject[h]){
                for(i=h+1,j=1; j<c; j++,i++){
                    if(dato.subject[i] == s[j]){
                        f++;
                    }
                }
                if(f+1 == c){
                    int sizev = v.size();
                    if(v.empty())
                        v.insert(v.end(),dato);
                    else if(v[sizev-1].id != dato.id)
                        v.insert(v.end(),dato);
                }
            }
        }
    }

    if (der != NULL) der->searchsubject(s,v);
}


/**
 * Funcion que toma una palabra como parametro y la agrega al final del vector
 * si la palabra esta en el contenido del email
 * @param s palabra a buscar
 * @param v vector en el cual se agregan los emails
 */
void NodoArbol::searchcontent(string &s, vector<email> &v) {
    if (izq != NULL) izq->searchcontent(s,v);

    else{
        int i,j,h,f;
        int l = dato.content.length();
        int c = s.length();

        for(h=0; h<l; h++){
            f=0;
            if(s[0] == dato.content[h]){
                for(i=h+1,j=1; j<c; j++,i++){
                    if(dato.content[i] == s[j]){
                        f++;
                    }
                }
                if(f+1 == c){
                    int sizev = v.size();
                    if(v.empty())
                        v.insert(v.end(),dato);
                    else if(v[sizev-1].id != dato.id)
                        v.insert(v.end(),dato);
                }
            }
        }
    }

    if (der != NULL) der->searchcontent(s,v);
}

/**
 * Funcion que remueve un email y devuelve un puntero a un nodo, que corresponde al nodo que mantiene
 * el balance del arbol y reemplaza el nodo a remover
 * @param d
 * @return NodoArbol*
 */
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

/**
 * Funcion que remueve un email, ingresando su id, y devuelve un puntero a un nodo, que corresponde al nodo que mantiene
 * el balance del arbol y reemplaza el nodo a remover
 * @param d
 * @return
 */
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

/**
 * devuelve el email correspondiente al nodo
 * @return email
 */
email NodoArbol::getDato() const {
    return dato;
}


#endif //MAILMANAGER_NODOARBOL_H