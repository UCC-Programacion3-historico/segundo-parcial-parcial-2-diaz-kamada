#ifndef MAILMANAGER_ARBOLAVL_H
#define MAILMANAGER_ARBOLAVL_H

#include <iostream>
#include <string>
#include "NodoAvl.h"
using namespace std;

template <class T>
class ArbolAvl{
private:
    NodoAvl<T> *raiz;
public:
    ArbolAvl(){
        raiz=NULL;
    }
    ArbolAvl(NodoAvl *r){
        raiz = r;
    }

    NodoAvl *rotacionII(NodoAvl* n, NodoAvl* n1);

    NodoAvl *rotacionDD(NodoAvl* n, NodoAvl* n1);

    NodoAvl *rotacionDI(NodoAvl* n, NodoAvl* n1);

    NodoAvl *rotacionID(NodoAvl* n, NodoAvl* n1);

    NodoAvl *insertarAvl(NodoAvl* raiz, NodoAvl* dt, bool &hc);

};

NodoAvl* ArbolAvl::rotacionII(NodoAvl* n, NodoAvl* n1){
    n->ramaIzq(n1->subarbder());
    n1->ramaDer(n);

    if(n1->Ofe() ==-1){
        n->Pfe(0);
        n1->Pfe(0);
    } else{
        n->Pfe(-1);
        n1->Pfe(1);
    }
    return n1;
}

NodoAvl* ArbolAvl::rotacionDD(NodoAvl* n, NodoAvl* n1){
    n->ramaDer(n1->subarbizq());
    n1->ramaIzq(n);

    if(n1->Ofe()==1){
        n->Pfe(0);
        n1->Pfe(0);
    } else{
        n->Pfe(1);
        n1->Pfe(-1);
    }
    return n1;
}

NodoAvl* ArbolAvl::rotacionDI(NodoAvl* n, NodoAvl* n1){
    NodoAvl* n2;

    n2=n1->subarbizq();
    n->ramaDer(n2->subarbizq());
    n2->ramaIzq(n);
    n1->ramaIzq(n2->subarbder());
    n2->ramaDer(n1);

    if(n2->Ofe()== 1)
        n->Pfe(-1);
    else
        n1->Pfe(0);

    if(n2->Ofe()==-1)
        n1->Pfe(1);
    else
        n1->Pfe(0);
    n2->Pfe(0);
    return n2;
}

NodoAvl* ArbolAvl::rotacionID(NodoAvl* n,NodoAvl* n1){
    NodoAvl* n2;
    n2=n1->subarbder();
    n->ramaIzq(n2->subarbder());
    n2->ramaDer(n);
    n1->ramaDer(n2->subarbizq());

    if(n2->Ofe()==1)
        n1->Pfe(-1);
    else
        n1->Pfe(0);
    if(n2->Ofe() == -1)
        n->Pfe(1);
    else
        n->Pfe(0);
    n2->Pfe(0);
    return n2;
}

NodoAvl* ArbolAvl::insertarAvl(NodoAvl* raiz, NodoAvl* dt, bool &hc){
    NodoAvl *n1;

    if(raiz==NULL){
        raiz = new NodoAvl(dt);
        hc = true;
    }
    else if (dt<raiz->valorNodo()){
        NodoAvl *iz;
        iz = insertarAvl(raiz->subarbizq(), dt, hc);
        raiz->ramaIzq(iz);

        if(hc){
            switch (raiz->Ofe()){
                case 1:
                    raiz->Pfe(0);
                    hc = false;
                    break;
                case 0:
                    raiz->Pfe(-1);
                    break;
                case -1:
                    n1 = raiz->subarbizq();
                    if(n1->Ofe() ==-1)
                        raiz = rotacionII(raiz, n1);
                    else
                        raiz = rotacionID(raiz, n1);
                    hc = false;
                default:
                    break;
            }
        }
    }
    else if (dt > raiz->valorNodo()){
        NodoAvl *dr;
        dr = insertarAvl(raiz->subarbder(), dt, hc);
        raiz->ramaDer(dr);
        if(hc){
            switch (raiz->Ofe()){
                case 1:
                    n1 = raiz->subarbder();
                    if(n1->Ofe() == 1)
                        raiz=rotacionDD(raiz, n1);
                    else
                        raiz=rotacionDI(raiz, n1);
                    hc = false;
                    break;
                case 0:
                    raiz->Pfe(1);
                    break;
                case -1:
                    raiz->Pfe(0);
                    hc = false;
                default:
                    break;
            }
        }
    }
    else
        throw 1;
    return raiz;
}


#endif //MAILMANAGER_ARBOLAVL_H
