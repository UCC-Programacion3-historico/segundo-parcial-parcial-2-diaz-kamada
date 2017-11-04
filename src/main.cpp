#include <iostream>
#include "MailManager.h"

using namespace std;

int main(){
    int variable;
    do{

        cout << endl
             << " 1 - Agregar Mail.\n"
             << " 2 - Borrar Mail\n"
             << " 3 - Buscar Mail\n"
             << " 4 - Mostrar Mails\n"
             << " 5 - Salir\n"
             << " Ingrese su opcion y presione enter: ";
        cin >> variable;

        switch(variable)
        {
            case 1:
                cout<<"Agregar"<<endl;

                break;

            case 2:
                cout<<"ingrese id del correo a borrar"<<endl;

                break;

            case 3:
                cout<<"ingrese remitente o palabra clave"<<endl;

                break;

            case 4:
                cout<<"Mostrar"<<endl;

                break;

            case 5:
                cout<<"Salir"<<endl;
                break;

        }
    }while(variable!=5);

    return 0;
}