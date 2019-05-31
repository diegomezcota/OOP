#include <iostream>
#include "fraccion.h"

using namespace std;

int main() {

  int n, num, den;

  cout << "Ingrese la cantidad de fracciones a ingresar: "; 
  cin >> n;

  fraccion arr[n];

  for (int i = 0; i < n; i++){
    cout << i + 1 << ".- Ingrese el numerador: ";
    cin >> num;
    arr[i].setNumerador(num);
    cout << i + 1 << ".- Ingrese el denominador: ";
    cin >> den;
    arr[i].setDenominador(den);
  }

  for (int i = 0; i < n; i++){
    cout << "El valor de la fraccion " << arr[i].getNumerador() << "/" << arr[i].getDenominador() << " es de " << arr[i].calcValorReal() << endl;
  }
}