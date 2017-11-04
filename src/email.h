#include <string>

#ifndef EMAIL_H
#define EMAIL_H

using namespace std;

/**
 * Clase con los datos del mail
 */
class email {
public:
    email();
    //email(const email &em);
    unsigned long id;
    string from;
    string to;
    string date;
    string subject;
    string content;
};

email::email() {
    id=0;
    from="";
    to="";
    date="";
    subject="";
    content="";
}

//email::email(const email &em) {
//
//}

#endif // EMAIL_H