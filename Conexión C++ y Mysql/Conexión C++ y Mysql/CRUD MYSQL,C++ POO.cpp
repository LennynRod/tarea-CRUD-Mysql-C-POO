#include<iostream>
#include "Cliente.h"


using namespace std;

int main(){
    string nombres, apellidos, direccion, fecha_nacimiento, nit,id;
    int telefono = 0, op = 0, op1=0;
  
    cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
    cout << "Crear registro.......................1" << endl;
    cout << "Leer registro........................2" << endl;
    cout << "Actualizar registro..................3" << endl;
    cout << "Borrar registro......................4" << endl;
    cout << "Salir................................5" << endl << endl;
    cin >> op;

    switch (op) {

    case 1:{
        system("cls");
      
        cout << "Ingrese Nit: ";
        getline(cin, nit);
        cout << "Ingrese Nombres: ";
        getline(cin, nombres);
        cout << "Ingrese Apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese Direccion: ";
        getline(cin, direccion);
        cout << "Ingrese Telefono: ";
        cin >> telefono;
        cin.ignore();
        cout << "Ingrese Fecha Nacimiento en formato AA-MM-DD:  ";
        cin >> fecha_nacimiento;


        Cliente  c = Cliente(id,nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

        c.crear();
        c.leer();
        system("pause");
        cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
        cin >> op1;
    switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
    }break;

    case 2: {
        system("cls");
        Cliente  c = Cliente();
        c.leer();
        cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
        cin >> op1;
    switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
    }break;

   case 3: {
       system("cls");

        Cliente  c = Cliente();
        c.leer();
        cout << endl << "-------------------------------------------------------------------" << endl;
        cout <<endl<< "Ingrese la ID del cliente que desea actualizar: ";
        cin >> id;
        cout << endl;
        cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl<<endl;
        cin.ignore();
        cout << "Ingrese Nit: ";
        getline(cin, nit);
        cout << "Ingrese Nombres: ";
        getline(cin, nombres);
        cout << "Ingrese Apellidos: ";
        getline(cin, apellidos);
        cout << "Ingrese Direccion: ";
        getline(cin, direccion);
        cout << "Ingrese Telefono: ";
        cin >> telefono;
        cin.ignore();
        cout << "Ingrese Fecha Nacimiento en formato AA-MM-DD:  ";
        cin >> fecha_nacimiento;

        Cliente  c2 = Cliente(id,nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

        c2.actualizar();
        cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
        cin >> op1;
   switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
    }break;
   case 4: {
       system("cls");

       Cliente  c = Cliente();
       c.leer();
       cout << endl << "-------------------------------------------------------------------" << endl;
       cout << endl << "Ingrese la ID del cliente que desea eliminar: ";
       cin >> id;

       Cliente  c2 = Cliente(id,nombres, apellidos, direccion, telefono, fecha_nacimiento, nit);

       c2.eliminar();

       cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
       cin >> op1;
   switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
   }break;

   case 5:  system("exit");
    break;
    


    default:cout << "Usted ah ingresado una opcion no valida, por favor ingurese una opcion valida" << endl;
    }

   
    return 0;



   
   /*
     conectar = mysql_init(0);
     conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_empresa", 3306, NULL, 0);



     if (conectar) {
         //cout << "conexion exitosa..." << endl;

        string puesto;
         cout << "Ingrese puesto:" << endl;
         cin >> puesto;
         string insert = "insert into puestos(puesto) values('"+puesto+"')";
         const char * i = insert.c_str();
         q_estado = mysql_query(conectar,i);
         if (!q_estado) {
             cout << "Ingreso exitoso..." << endl;
         }
         else {
             cout << "error al ingresar..." << endl;
         }
         

         
        







     }




     


   

    system("pause");
    return 0;*/

}

