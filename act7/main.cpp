#include <iostream>
#include "fraccion.h"

using namespace std;

int main() {
  fraccion fFrac1;
  fraccion fFrac2(3, 4);

  cout << "El valor de la fraccion " << fFrac1.getNumerador() << "/" << fFrac1.getDenominador() << " es de " << fFrac1.calcValorReal() << endl;

  cout << "El valor de la fraccion " << fFrac2.getNumerador() << "/" << fFrac2.getDenominador() << " es de " << fFrac2.calcValorReal();


  return 0; 
}