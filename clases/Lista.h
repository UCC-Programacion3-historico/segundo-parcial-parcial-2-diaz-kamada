#ifndef MAILMANAGER_LISTA_H
#define MAILMANAGER_LISTA_H

#include "NodoLista.h"
#include <iostream>
using namespace std;

/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template<class T>
class Lista {
private:
    Nodo<T> *inicio;
public:
    Lista();

    Lista(const Lista<T> &li);

    ~Lista();

    bool esVacia();

    int getTamanio();

    void insertar(int pos, T dato);

    void insertarPrimero(T dato);

    void insertarUltimo(T dato);

    void remover(int pos);

    T getDato(int pos);

    void reemplazar(int pos, T dato);

    void vaciar();

    void insertAfter2(T, int, T);

    T buscar(T d);                      //funcion nueva

    int buscarpos(T d);

    Nodo<T> *getInicio() {
        return inicio;
    };
};


/**
 * Constructor de la clase Lista
 * @tparam T
 */
template<class T>
Lista<T>::Lista() {
    inicio = NULL;
}


/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */
template<class T>
Lista<T>::Lista(const Lista<T> &li) {
    inicio = nullptr;
    Nodo<T> *auxli = li.inicio;
    if (auxli == nullptr)
        return;

    Nodo<T> *auxnn = inicio = new Nodo<T>(auxli->getDato(), nullptr);
//    Nodo<T> *auxnn = inicio;
    auxli = auxli->getNext();

    while (auxli != nullptr) {
        auxnn->setNext(new Nodo<T>(auxli->getDato(), nullptr));

        auxnn = auxnn->getNext(); // auxnn = newNode;
        auxli = auxli->getNext();
    }
}


/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los nodos
 * utilizados en la lista
 * @tparam T
 */
template<class T>
Lista<T>::~Lista() {
    vaciar();
}

/**
 * @tparam T
 * @param d
 * @return
 */
template<class T>
T Lista<T>::buscar(T d) {
    Nodo<T> *aux = inicio;
    while(aux->getNext() != NULL && aux->getDato() != d)
        aux = aux->getNext();
    if(aux->getDato() == d)
        return aux->getDato();
    else
        throw 3;
}

template<class T>
int Lista<T>::buscarpos(T d) {
    Nodo<T> *aux = inicio;
    int cont = 0;
    if(inicio == NULL)
        return -1;
    while(aux->getNext() != NULL && aux->getDato() != d){
        aux = aux->getNext();
        cont++;
    }
    if(aux->getDato() == d)
        return cont;
    else
        return -1;
}


/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template<class T>
bool Lista<T>::esVacia() {
    return inicio == NULL;
}


/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template<class T>
int Lista<T>::getTamanio() {
    Nodo<T> *aux = inicio;
    int cont = 0;

    while (aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    return cont;
}


/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template<class T>
void Lista<T>::insertar(int pos, T dato) {
    int cont = 0;
    Nodo<T> *aux = inicio;

    if (pos == 0) {
        Nodo<T> *nn = new Nodo<T>(dato, inicio);
        inicio = nn;
        return;
    }

    while (cont < pos - 1 && aux != NULL) {
        cont++;
        aux = aux->getNext();
    }

    if (aux == NULL)
        throw 1;

    Nodo<T> *nn = new Nodo<T>(dato, aux->getNext());
    aux->setNext(nn);
}


/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarPrimero(T dato) {
    Nodo<T> *nn = new Nodo<T>(dato, inicio);
    inicio = nn;
}


/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template<class T>
void Lista<T>::insertarUltimo(T dato) {
    if (NULL == inicio) {
        inicio = new Nodo<T>(dato, NULL);
        return;
    }

    Nodo<T> *aux = inicio;
    while (aux->getNext() != NULL) {
        aux = aux->getNext();
    }
    Nodo<T> *nn = new Nodo<T>(dato, NULL);
    aux->setNext(nn);
}


/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template<class T>
void Lista<T>::remover(int pos) {
    int cont = 0;
    Nodo<T> *aux = inicio;

    if (pos == 0) {

        if (inicio == NULL)
            throw 1;

        inicio = inicio->getNext();
        delete[] aux;
        return;
    }

    while (cont < pos - 1 && aux->getNext() != NULL) {
        cont++;
        aux = aux->getNext();
    }
    if (aux->getNext() == NULL)
        throw 1;

    Nodo<T> *tmp = aux->getNext();
    aux->setNext(tmp->getNext());
    delete[] tmp;
}


/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template<class T>
T Lista<T>::getDato(int pos) {
    int i = 0;
    Nodo<T> *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    return aux->getDato();
}


/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template<class T>
void Lista<T>::reemplazar(int pos, T dato) {
    int i = 0;
    Nodo<T> *aux = inicio;
    while (i < pos && aux != NULL) {
        aux = aux->getNext();
        i++;
    }

    if (aux == NULL)
        throw 1;

    aux->setDato(dato);
}


/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template<class T>
void Lista<T>::vaciar() {
    Nodo<T> *borr;
    Nodo<T> *aux = inicio;

    while (aux != NULL) {
        borr = aux;
        aux = aux->getNext();
        delete[] borr;
    }
    inicio = NULL;
}

template<class T>
void Lista<T>::insertAfter2(T oldValue, int n, T newValue) {
    int cont = 0;
    Nodo<T> *aux = inicio;
    while (NULL != aux) {
        if (aux->getDato() == oldValue) {
            cont++;
            if (cont == n) {
                cont = 0;
                Nodo<T> *nuevoNodo = new Nodo<T>(newValue, aux->getNext());
                aux->setNext(nuevoNodo);
            }
        }
        aux = aux->getNext();
    }
}

#endif //MAILMANAGER_LISTA_H
