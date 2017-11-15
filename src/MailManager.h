#include <vector>
#include "../clases/ArbolFrom.h"
#include "../clases/ArbolDate.h"
#include "../clases/ArbolMail.h"

#ifndef MAILMANAGER_H
#define MAILMANAGER_H

using namespace std;

class MailManager {
private:

    ArbolMail Aid;
    ArbolDate Adate;
    ArbolFrom Afrom;
    //Lista<email>* Tabla = new  Lista [3001];

public:
    MailManager();

    void addMail(email m);                                          //agregar nodos a arboles

    void deleteMail(unsigned long id);                              //borrar por id

    vector<email> getSortedByDate();                                //ordenar por date

    vector<email> getSortedByDate(string desde, string hasta);      //ordenar por date (filtrado)

    vector<email> getSortedByFrom();                                //ordenar por from

    vector<email> getByFrom(string from);                           //buscar por from

    vector<email> getByQuery(string query);                         //buscar por texto o asunto

    void printid();

    void printfrom();

    void printdate();
};

void MailManager::printfrom() {Afrom.print();}

void MailManager::printdate() {Adate.print();}

void MailManager::printid() {Aid.print();}

/**
 * Constructor
 */
MailManager::MailManager() {
}

using std::cout;
/**
 * Agrega un mail al gestor
 * @param m mail a agregar
 */
void MailManager::addMail(email m) {
    Aid.put(m);
    Adate.put(m);
    Afrom.put(m);
}


/**
 * Elimina un mail del gestor
 * @param id identificador del mail a borrar
 */
void MailManager::deleteMail(unsigned long id) {
    email aux = Aid.search(id);
    Aid.remove(id);
    Adate.remove(aux);
    Afrom.remove(aux);
}


/**
 * Devuelve una lista de mails ordenados por fecha
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate() {
    vector<email> ret;
    Adate.inorder(ret);
    return ret;
}


/**
 * Devuelve una lista de mails oredenados por fecha que estan en el rango
 * desde - hasta
 * @param desde Fecha desde donde buscar
 * @param hasta Fecha hasta donde buscar
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByDate(string desde, string hasta) { //REVISAR REVISAR REVISAR REVISAR REVISAR
    vector<email> ret;
    Adate.inorderfiltrado(ret,desde,hasta);
    return ret;
}


/**
 * Devuelve una lista de mails ordenados por Remitente
 * @return lista de mails ordenados
 */
vector<email> MailManager::getSortedByFrom() { //REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR REVISAR
    vector<email> ret;
    Afrom.inorder(ret);
    return ret;
}


/**
 * Devuelve una lista de mails de un determinado remitente
 * @param from String con direccion del remitente
 * @return lista de mails del remitente
 */
vector<email> MailManager::getByFrom(string from) {
    vector<email> ret;
    return ret;
}


/**
 * Devuelve una lista de mails que contengan las palabras de 'query'
 * en su asunto o en su contenido
 * @param query String con palabra/s a buscar
 * @return lista de mails que contienen dicha/s palabra/s
 */
vector<email> MailManager::getByQuery(string query) {
    vector<email> ret;
    return ret;
}

#endif // MAILMANAGER_H