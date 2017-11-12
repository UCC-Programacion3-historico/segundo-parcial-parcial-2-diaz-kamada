#include <string>
#include <vector>
#include "email.h"
#include "../clases/ArbolDate.h"
#include "../clases/ArbolFrom.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;


class MailManager {
private:

    ArbolDate AD;
    ArbolFrom AF;
    //tabla de hash

public:
    MailManager();

    void addMail(email m);                                          //agregar nodos a arboles

    void deleteMail(unsigned long id);                              //borrar por id

    vector<email> getSortedByDate();                                //ordenar por date

    vector<email> getSortedByDate(string desde, string hasta);      //ordenar por date (filtrado)

    vector<email> getSortedByFrom();                                //ordenar por from

    vector<email> getByFrom(string from);                           //buscar por from

    vector<email> getByQuery(string query);                         //buscar por texto o asunto
};

#endif // MAILMANAGER_H