#include <iostream>

#include <cmath>

using namespace std;

//Diego Gomez Cota
//A00824758

#include "Cuadratica.h"

Cuadratica operator-(Cuadratica c1, Cuadratica c2){
  Cuadratica cResult;
  cResult.iCoefA = c1.iCoefA - c2.iCoefA;
  cResult.iCoefB = c1.iCoefB - c2.iCoefB;
  cResult.iCoefC = c1.iCoefC - c2.iCoefC;
  return cResult;
}

Cuadratica operator+=(Cuadratica &c1, Cuadratica c2){
  c1.iCoefA += c2.iCoefA;
  c1.iCoefB += c2.iCoefB;
  c1.iCoefC += c2.iCoefC;
  return c1;
}

Cuadratica operator++(Cuadratica &c1){
  c1.iCoefC = c1.iCoefC + 1;
  return c1;
}

int main()

{

int iA, iB, iC;

Cuadratica ec1(5,3,2), ecRes;

Cuadratica ec3 = ec1; // ec1 y ec3 tienen los mismos valores.

cout << "Teclea los coeficientes para la segunda ecuación" << endl;

cin >> iA >> iB >> iC;

Cuadratica ec2(iA, iB, iC);

/*********************************/

cout << endl;

cout << "=== Suma de Ecuaciónes 1 y 2" << endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :";

ec2.muestra();

// Usa la sobrecarga para hacer la suma
ecRes = ec1 + ec2;

cout << "Resultado :";

ecRes.muestra();

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :";

ec2.muestra();

cout << endl;

/*********************************/

cout << endl;

cout << "=== Resta de Ecuaciónes 1 y 2" << endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :" ;

ec2.muestra();

// Usa la sobrecarga para hacer la resta
ecRes = ec1 - ec2;

cout << "Resultado :";

ecRes.muestra();

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :";

ec2.muestra();

cout << endl;

/*********************************/

cout << endl;

cout << "=== Multiplica Ecuación 1 por valor entero 2" << endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

// Usa la sobrecarga para hacer la multiplicación
ecRes = ec1 * 2;

cout << "Resultado :";

ecRes.muestra();

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << endl;

/*********************************/

cout << endl;

//"=== Compara con == ecuación 1 y ecuación 2, deben ser diferentes" 

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :" ;

ec2.muestra();

if (ec1 == ec2){
  cout << "Son iguales" << endl;
} else {
  cout << "Son diferentes " << endl;
}
/*********************************/

cout << endl;

cout << "=== Compara con == ecuación 1 y ecuación 3, deben ser iguales"

<< endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 3 :" ;

ec3.muestra();

if (ec1 == ec3) {
  cout << "Son iguales" << endl;
} else {
  cout << "Son diferentes " << endl;
}

/*********************************/

cout << endl;

cout << "=== Aplica += para sumar Ecuaciónes 1 y 2" << endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :";

ec2.muestra();

// Usa la sobrecarga para hacer el +=
ec1 += ec2;

cout << "Ecuación 1 :" ;

ec1.muestra();

cout << "Ecuación 2 :";

ec2.muestra();

cout << endl;

/*********************************/

cout << endl;

cout << "=== Aplica ++ a Ecuación 1 " << endl;

cout << "Ecuación 1 :" ;

ec1.muestra();

// Usa la sobrecarga para hacer el incremento
ecRes = ++ec1;

cout << "Regresa :";

ecRes.muestra();

cout << "Ecuación 1 :" ;

ec1.muestra();

return 0;

}