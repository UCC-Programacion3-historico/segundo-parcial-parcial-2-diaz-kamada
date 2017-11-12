#ifndef MAILMANAGER_NODOAVL_H
#define MAILMANAGER_NODOAVL_H

#include <iostream>
#include <string>
#include "../src/email.h"

using namespace std;

template <class T>
class NodoAvl{
protected:

    T dato;
    NodoAvl *izq;
    NodoAvl *der;
    int fe;

public:

    NodoAvl(T valor){

        dato =valor;
        izq = der = NULL;
        fe = 0;
    }

    NodoAvl(T valor, int vfe){
        dato=valor;
        izq = der = NULL;
        fe = vfe;
    }

    NodoAvl(NodoAvl* RamaIzq, T valor, NodoAvl* RamaDer){
        dato = valor;
        izq = RamaIzq;
        der = RamaDer;
        fe = 0;
    }

    NodoAvl(NodoAvl* RamaIzq, int vfe, T valor, NodoAvl* RamaDer){
        dato = valor;
        izq = RamaIzq;
        der = RamaDer;
        fe = vfe;
    }

    T valorNodo(){
        return dato;
    }
    NodoAvl* subarbizq() {
        return izq;
    }
    NodoAvl* subarbder() {
        return der;
    }
    void nuevovalor(T d) {
        dato = d;
    }
    void ramaIzq(NodoAvl* n) {
        izq = n;
    }
    void ramaDer(NodoAvl* n) {
        der = n;
    }
    void visitar() {
        cout << dato << endl;
    }
    void Pfe(int vfe) {
        fe = vfe;
    }
    int Ofe() {
        return fe;
    }

};



#endif //MAILMANAGER_NODOAVL_H
