#include <iostream>
#include <string.h>
using namespace std;

int main() {
  //Ejercicio 1
  char cNombre[50];
  char cNuevo[20];
  cout << "Ingrese su nombre completo: ";
  cin.getline(cNombre, 50);
  for (int i = 0, iPos = -1; i < 50 && iPos == -1; i++){
    if (cNombre[i] == ' '){
      iPos = i;
      strncpy(cNuevo, cNombre, i);
    }
  }
  cout << "Hola " << cNuevo << "!!\n";

  //Ejercicio 2
  char cPalabra1[50], cPalabra2[50], cPalabra3[50], cAuxiliar[50];
  int i1a2, i1a3, i2a3;

  cout << "Ingrese la primer palabra: ";
  cin >> cPalabra1;
  cout << "Ingrese la segunda palabra: ";
  cin >> cPalabra2;  
  cout << "Ingrese la tercer palabra: ";
  cin >> cPalabra3;

  i1a2 = strcmp(cPalabra1, cPalabra2);
  i1a3 = strcmp(cPalabra1, cPalabra3);
  i2a3 = strcmp(cPalabra2, cPalabra3);

  if (i1a2 < 0 && i1a3 < 0){
    cout << cPalabra1 << endl;
    if (i2a3 < 0){
      cout  << cPalabra2 << endl << cPalabra3;
    } else {
      cout << cPalabra3 << endl << cPalabra2;
    }
  } else {
    if (i1a2 < 0){
      cout << cPalabra3 << endl << cPalabra1 << endl << cPalabra2;
    } else {
      if (i2a3 < 0){
        cout << cPalabra2 << endl;
        if (i1a3 < 0){
          cout << cPalabra1 << endl << cPalabra3;
        } else {
          cout << cPalabra3 << endl << cPalabra1;
        }
      } else {
        cout << cPalabra3 << endl << cPalabra2 << endl << cPalabra1;
      }
    }
  }

  return 0;
}