//
//  main.cpp
//  CascaronFraccion
//
//  Ejercicio sobrecarga //
//  *      Multiplicacion de dos fracciones
//  > Compara si la primera fraccion es mayor que la segunda
//  ++  Suma el valor 1/1 a una fracciÃ³n y regresa la nueva fracciÃ³n
//  -   Operador unitario â€“ (negativo), regresa una fracciÃ³n que contiene la fracciÃ³n original con el numerador con el signo cambiado.
//  -   Operador resta 
//  *   Operador * para multiplicar una fracciÃ³n por un valor entero y regresa la nueva fracciÃ³n.

//Diego Gomez Cota
//A00824758

#include <iostream>
using namespace std;

#include "FraccionS.h"

int main()
{

    Fraccion f1(1,3), f2(3,4), f3(1,5), f4;
	
    
    // la suma de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La suma de las fracciones 1 y 2 " << endl;
	f4 = f1 + f2;
    f4.muestra();

        // la resta de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La resta de las fracciones 1 y 2 " << endl;
	f4 = f2 - f1;
    f4.muestra();

        // la Multiplicacion de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "La Multiplicacion de las fracciones 1 y 2 " << endl;
	f4 = f1 * f2;
    f4.muestra();    

        // El ++ de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "El ++ de las fracciones 1 " << endl;
	f4 = ++f1;
    f4.muestra();        

        // El -- de las fracciones 1/3 y 3/4
    cout << endl;
    cout << "El -- de las fracciones 1 " << endl;
	f4 = --f1;
    f4.muestra();        
    

  cout << endl;
  if (f1>f2){
    cout << "Fraccion 1 es mayor que f2";
  } else {
    cout << "Fraccion 2 es mayor que f1";
  }

    // el valor en decimal de la fracciÃ³n 1/3
    cout << endl;
    cout << "El valor decimal de la fraccion 1 "<< endl;
    cout << !f1;
    
    return 0;
}
