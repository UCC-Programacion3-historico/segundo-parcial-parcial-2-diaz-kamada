#ifndef MAILMANAGER_NODOMAIL_H
#define MAILMANAGER_NODOMAIL_H

#include "../src/email.h"

class NodoMail{
private:
    email mail;
    NodoMail *next;
public:
    NodoMail(){
        next=NULL;
    }

    NodoMail(email d, NodoMail *n){
        mail=d;
        next=n;
    }

    email getMail() {
        return mail;
    }

    void setMail(const email &mail) {
        NodoMail::mail = mail;
    }

    NodoMail *getNext() const {
        return next;
    }

    void setNext(NodoMail *next) {
        NodoMail::next = next;
    }
};

#endif //MAILMANAGER_NODOMAIL_H