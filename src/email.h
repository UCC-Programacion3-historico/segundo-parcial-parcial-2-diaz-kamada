#include <string>
#include <iostream>
using namespace std;

#ifndef EMAIL_H
#define EMAIL_H

/**
 * Clase con los datos del mail
 */
class email {
public:
    email();
    email(unsigned long, string, string, string, string, string);
    email(const email &em);
    unsigned long id;
    string from;
    string to;
    string date; //a-m-d
    string subject;
    string content;

    void setId(unsigned long id);

    void setFrom(const string &from);

    void setTo(const string &to);

    void setDate(const string &date);

    void setSubject(const string &subject);

    void setContent(const string &content);

    void mostrar();
};

/**
 * COnstructor por defecto
 */
email::email() {
    id=0;
    from="";
    to="";
    date="";
    subject="";
    content="";
}

/**
 * Constructor con parametros
 * @param x
 * @param a
 * @param b
 * @param c
 * @param d
 * @param e
 */
email::email(unsigned long x, string a, string b, string c, string d, string e) {
    id=x;
    from=a;
    to=b;
    date=c;
    subject=d;
    content=e;
}

/**
 * muestra los datos del email
 */
void email::mostrar() {
    cout << "id: " << id << endl;
    cout << "from: " << from << endl;
    cout << "to: " << to << endl;
    cout << "date: " << date << endl;
    cout << "subject: " << subject << endl;
    cout << "content: " << content << endl;
}

/**
 * constructor por copia
 * @param em
 */
email::email(const email &em) {
    id=em.id;
    from=em.from;
    to=em.to;
    date=em.date;
    subject=em.subject;
    content=em.content;
}

void email::setId(unsigned long id) {
    email::id = id;
}

void email::setFrom(const string &from) {
    email::from = from;
}

void email::setTo(const string &to) {
    email::to = to;
}

void email::setDate(const string &date) {
    email::date = date;
}

void email::setSubject(const string &subject) {
    email::subject = subject;
}

void email::setContent(const string &content) {
    email::content = content;
}

#endif // EMAIL_H