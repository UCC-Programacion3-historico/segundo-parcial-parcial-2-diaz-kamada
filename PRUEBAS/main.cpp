#include "../src/MailManager.h"

int main(){
    MailManager M;

    email email3(3,"pedro","juan","2017-11-13","jueguito","zelda botw");
    email email1(1,"manolo","juan","2017-09-13","como andas","hola juan como estas todo bien");
    email email2(2,"juancho","juan","2017-09-15","prueba","probando");
    email email5(9,"martin","juan","2017-11-01","metal","metallica es la luz");
    email email4(7,"agus","juan","2017-11-14","viste lo que paso?","q impresionante! no?");
    email email6(8,"agus","juan","2017-11-15","oh no!","q embole no?");

    cout << "arbol date:" << endl;
    M.addMail(email3);
    M.addMail(email1);
    M.addMail(email2);
    M.addMail(email5);
    M.addMail(email4);
    M.addMail(email6);
    M.printdate();

    cout << endl << "luego de remover el nodo 9:" << endl;

    M.deleteMail(9);
    M.printdate();

    cout << endl << "si agrego 9 de nuevo:" << endl;
    M.addMail(email5);
    M.printdate();

    cout << endl << "luego de remover el nodo 7:" << endl;

    M.deleteMail(7);
    M.printdate();

    cout << endl << "si agrego 7 de nuevo:" << endl;
    M.addMail(email4);
    M.printdate();

    return 0;
}