#include "../src/MailManager.h"

int main(){
    MailManager M;

    email email3(3,"pedro","juan","2017-11-13","jueguito","zelda botw");
    email email1(1,"manolo","juan","2017-09-13","como andas","hola juan como estas todo bien");
    email email2(2,"juancho","juan","2017-09-15","prueba como","como probando");
    email email5(9,"martin","juan","2017-11-01","metal como","metallica es la luz");
    email email4(7,"agus","juan","2017-11-14","viste lo que paso?","q impresionante! no?");
    email email6(8,"agus","juan","2017-11-14","oh no!","q embole no?");

    cout << "arbol date:" << endl;
    M.addMail(email3);
    M.addMail(email1);
    M.addMail(email2);
    M.addMail(email5);
    M.addMail(email4);
    M.addMail(email6);
    M.printid();

    cout << endl << "luego de remover el nodo 9:" << endl;

    M.deleteMail(9);
    M.printid();

    cout << endl << "si agrego 9 de nuevo:" << endl;
    M.addMail(email5);
    M.printid();

    cout << endl << "luego de remover el nodo 7:" << endl;

    M.deleteMail(7);
    M.printid();

    cout << endl << "si agrego 7 de nuevo:" << endl;
    M.addMail(email4);
    M.printid();


    vector<email> v, h;
    v = M.getSortedByDate();
    cout << endl << "todos los mails" << endl;
    for(int i=0; i<v.size(); i++){
        cout << "///////////////////////////////////////////////////////////////////////" << endl << i << " :" << endl;
        v[i].mostrar();
    }

    cout << endl << endl << endl << endl << endl<< "mails filtrados" << endl;

    string desde="2017-09-12";
    string hasta="2017-11-13";

    h=M.getSortedByDate(desde,hasta);

    for(int i=0; i<h.size(); i++){
        cout << "///////////////////////////////////////////////////////////////////////" << endl << i << " :" << endl;
        h[i].mostrar();
    }

    cout << endl << endl << endl << endl << endl<< "mails por from" << endl;\

    vector<email> g;
    g = M.getSortedByFrom();
    for(int i=0; i<g.size(); i++){
        cout << "///////////////////////////////////////////////////////////////////////" << endl;
        g[i].mostrar();
    }

    cout << endl << endl << endl << endl << endl;

    vector<email> j;
    j = M.getByFrom("agus");
    cout << endl << "todos los mails de agus" << endl;
    for(int i=0; i<j.size(); i++){
        cout << "///////////////////////////////////////////////////////////////////////" << endl;
        j[i].mostrar();
    }

    cout << endl << endl << endl << endl << endl<< "busqueda de 'como'" << endl;

    vector<email> z;
    string text="como";
    z = M.getByQuery(text);
    for(int i=0; i<z.size(); i++){
        cout << "///////////////////////////////////////////////////////////////////////" << endl;
        z[i].mostrar();
    }

    return 0;
}