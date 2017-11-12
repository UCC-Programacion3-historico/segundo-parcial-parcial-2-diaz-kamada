#include <string>
#include <iostream>

#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

/**
 * Clase con los datos del mail
 */
class email {
public:
    email();
    email(const email &em);
    unsigned long id;
    string from;
    string to;
    string date; //a-m-d
    string subject;
    string content;
    void mostrar();
};

email::email() {
    id=0;
    from="";
    to="";
    date="";
    subject="";
    content="";
}

void email::mostrar() {
    cout << "id: " << id << endl;
    cout << "from: " << from << endl;
    cout << "to: " << to << endl;
    cout << "date: " << date << endl;
    cout << "subject: " << subject << endl;
    cout << "content: " << content << endl;
}

email::email(const email &em) {
    id=em.id;
    from=em.from;
    to=em.to;
    date=em.date;
    subject=em.subject;
    content=em.content;
}

#endif // EMAIL_H