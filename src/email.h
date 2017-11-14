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

email::email(unsigned long x, string a, string b, string c, string d, string e) {
    id=x;
    from=a;
    to=b;
    date=c;
    subject=d;
    content=e;
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