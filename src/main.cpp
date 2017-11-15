#include <iostream>
#include "MailManager.h"

#define FS fflush(stdin)
using namespace std;

int main(){
    MailManager M;
    unsigned long id=1;
    int variable, op;
    string from, to, date, subject, content, word, desde, hasta;
    vector<email> v,g,r,t,z;
    email em;
    do{

        cout << endl
             << " 1 - Agregar Mail.\n"
             << " 2 - Borrar Mail\n"
             << " 3 - Buscar Mail\n"
             << " 4 - Ordenar Mails\n"
             << " 5 - Salir\n"
             << " Ingrese su opcion y presione enter: ";
        FS;
        cin >> variable;
        FS;

        switch(variable)
        {
            case 1:
                cout << "From: "; FS; getline(cin,from); FS; cout << endl;
                cout << "To: "; FS; getline(cin,to); FS; cout << endl;
                cout << "Date: "; FS; getline(cin,date); FS; cout << endl;
                cout << "Subject: "; FS; getline(cin,subject); FS; cout << endl;
                cout << "Content: "; FS; getline(cin,content); FS; cout << endl;

                em.setId(id);
                em.setFrom(from);
                em.setTo(to);
                em.setDate(date);
                em.setSubject(subject);
                em.setContent(content);

                M.addMail(em);
                id++;
                break;

            case 2:
                cout<<"ingrese id del correo a borrar: ";
                unsigned long id2;
                FS;
                cin >> id2; cout << endl;
                FS;
                M.deleteMail(id2);
                break;

            case 3:
                cout << "1 - Buscar por remitente" <<endl;
                cout << "2 - Buscar por palabra" <<endl;
                cout << "otro - volver" << endl;
                FS;
                cin >> op;
                FS;
                switch(op){
                    case 1:
                        cout << "Ingrese remitente: "; FS; getline(cin,from); FS; cout << endl;
                        v=M.getByFrom(from);
                        for(int h=0; h<v.size(); h++)
                            v[h].mostrar();
                        break;
                    case 2:
                        cout << "Ingrese palabra: "; FS; getline(cin,word); FS; cout << endl;
                        g=M.getByQuery(word);
                        for(int h=0; h<g.size(); h++)
                            g[h].mostrar();
                    default:
                        break;
                }
                break;

            case 4:
                cout << "1 - Ordenar por fecha" <<endl;
                cout << "2 - Ordenar por fecha (filrado)" <<endl;
                cout << "3 - Ordenar por remitente" <<endl;
                cout << "otro - volver" << endl;
                FS;
                cin >> op;
                FS;
                switch(op){
                    case 1:
                        r = M.getSortedByDate();
                        for(int h=0; h<r.size(); h++)
                            r[h].mostrar();
                        break;
                    case 2:
                        cout << "Ingrese desde que fecha filtrar: "; FS; getline(cin,desde); FS; cout << endl;
                        cout << "Ingrese hasta que fecha filtrar: "; FS; getline(cin,hasta); FS; cout << endl;
                        t = M.getSortedByDate(desde,hasta);
                        for(int h=0; h<t.size(); h++)
                            t[h].mostrar();
                        break;
                    case 3:
                        z = M.getSortedByFrom();
                        for(int h=0; h<z.size(); h++)
                            z[h].mostrar();
                        break;
                }
                break;

            case 5:
                cout<<"Salir"<<endl;
                break;

        }
    }while(variable!=5);

    return 0;
}