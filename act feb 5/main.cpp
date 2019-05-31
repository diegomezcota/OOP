#include <iostream>
#include <string>
#include "CuentaBanc.h"
using namespace std;

int main() {

  string nom;
    int opcion;
    double sal, cant;
    bool seguir = true;


    CuentaBanc UsaCtaBanc(nom, sal);

    cout << "Inserte su nombre: " << endl;
    cin >> nom;

    cout << "Inserte su saldo: " << endl;
    cin >> sal;
    UsaCtaBanc.setSaldo(sal);

    while (seguir)
    {
    cout << "\nBienvenido elija la opción que guste" << endl << "1 Deposita" << endl << "2 Retira" << endl << "3 Consulta Saldo" << endl << "4 Terminar" << endl;
        
        cin >> opcion;

    switch (opcion){
      case 1:
      cout << "Cantidad a depositar:  ";
      cin >> cant;
      UsaCtaBanc.deposita(cant);
      break;
      case 2:
      cout << "Cantidad a retirar: ";
      cin >> cant;
      UsaCtaBanc.retira(cant);
      break;
      case 3:
      sal = UsaCtaBanc.getSaldo();
      cout << "El saldo es: " << sal;
      break;
      case 4:
      seguir = false;
      default:
      cout << "Opcion incorrecta.";

    }

  
    }


}