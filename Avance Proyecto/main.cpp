/**
@progName Opciones Varias
@desc Puedes elegir entre calcular factorial de un numero, verificar si es par o ver si una palabra es palindromo
@author Diegomez
@date 7 de febrero de 2019
*/
#include <iostream>
#include <string>

using namespace std;

/**
@funcName palindromo
@desc Verifica si una palabra se lee igual de derecha a izquierda como de izquierda a derecha
@param variable booleana por referencia en la que se guardara si es verdadero o falso el caso que sea palindromo
@return el valor de verdad del caso
*/
bool palindromo(bool &espalindromo){

  espalindromo = true;
  string sPalabra = "";
  cout << "Ingrese la palabra: ";
  cin >> sPalabra;

  for (int iK = 0, iJ = sPalabra.length() - 1;
      iK < sPalabra.length() / 2;
      iK++, iJ--){
    if (sPalabra[iK] != sPalabra[iJ]){
      espalindromo = false;
      return espalindromo;
    }
  }
  return espalindromo;
}

/**
@funcName multiplo
@desc Verifica si un numero es par o impar sin usar mod %
@return el valor de verdad del caso
*/
bool multiplo(){

  bool bParidad = true;
  int iNum;

  cout << "Ingresa el número: ";
  cin >> iNum;

  if (iNum != iNum/2*2){
    bParidad = false;
  }

  return bParidad;
}

/**
@funcName factorial
@desc Calcula el factorial de un numero
*/
void factorial(){
  long int iNum, iSuma;
  cout << "\nIngresa el numero: ";
  cin >> iNum;
  iSuma = iNum;
  if (iNum > 0){
    for (int iK = iNum - 1; iK > 0; iK--){
      iSuma *= iK; 
    }
    cout << "El factorial de " << iNum << " es: " << iSuma << "\n\n";
  } else if (iNum < 0) {
    cout << "No existe factorial para numeros negativos.\n\n";
  } else {
    cout << "El factorial de 0 es: " << 1 << "\n\n";
  }    
}

/**
@funcName main
@desc Pregunta al usuario la opcion que desee para asi realizarla, se termina cuando el usuario teclea 0
@return 0 al terminar el programa para finalizar
*/
int main() {
  
int iOpcion = 1;
bool bPar = true;
bool bPalindromo;

while (iOpcion != 0){
  
  cout << "1.- Calcular factorial de un numero.\n2.- Verificar si un numero es multiplo de 2\n3.- Verificar si una palabra es palindromo\nTeclee 0 para salir.\n\nIngresa la opción que desees: ";
  
  cin >> iOpcion;
  
  switch (iOpcion){
    case 1:
    factorial();
    break;
    case 2:
    bPar = multiplo();
    if (bPar){
      cout << "El numero es par.\n\n";
    } else {
      cout << "El numero es impar.\n\n";
    }
    break;
    case 3:
    palindromo(bPalindromo);
    if (bPalindromo){
      cout << "La palabra es palindromo.\n\n";
    } else {
      cout << "La palabra no es palindromo\n\n";
    }
    break;
    case 0:
      cout << "Adios\n";
    break;
    default:
    cout << "Opcion incorrecta.";
  }
}

return 0;

}