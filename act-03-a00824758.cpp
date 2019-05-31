#include <iostream>
#include <string>


using namespace std;

int main(){
/*

  //EXERCISE 1

  string sPhrase;

  cout << "Teclee una phrase: ";

  getline(cin, sPhrase);
  string fraseOG = sPhrase;

  bool esPalindromo = true;

 //Borrar espacio
  int idxEspacio = 0;
  while (idxEspacio >= 0) {
  idxEspacio = sPhrase.find(" ");
  if (idxEspacio >= 0){
    sPhrase.erase(idxEspacio, 1);
    }
  }

  //Valida palindromos
  int longitudFrase = sPhrase.length();
  int j = longitudFrase - 1;
  for (int i = 0; i < longitudFrase/2 && esPalindromo; i++){
    if (tolower(sPhrase[i]) != tolower(sPhrase[j])) {
      esPalindromo = false;
    } else {
      j--;
    }
  }

  if (esPalindromo){
    cout << "La phrase " << fraseOG << " SI es un palindromo";
  } else {
    cout << "La frase " << fraseOG << " NO es un palindromo";
  }

  return 0;
*/

 /*
 EJERCICIO 2
  string frase;
  cout << "Favor de teclear una frase: " << endl;
  getline(cin, frase);

  string fraseFinal;

  if (frase[0] != ' '){
    fraseFinal = toupper(frase[0]);
  }

  for (int i = 1; i < frase.length(); i++){

    if (frase[i]==' ' && frase[i+1] != ' ') {
      fraseFinal += toupper(frase[i+1]);
    }
  }
  cout << "La frase resultante es: " << fraseFinal;

*/

/*
EJERCICIO 3
Escribe un programa que pida al usuario una frase.
El programa debe construir un string que contenga la frase con las palabras al rev�s. Por ejemplo:
Si el usuario teclea la frase:    Esta es la frase del ejemplo.
El programa construir� el string:   ejemplo. del frase la es Esta
*/

/*
string frase;
cout << "Favor de teclear una frase: " << endl;
getline(cin, frase);
string fraseFinal;
for (int i = frase.length()-1; i >= 0; i--)
{
   if (frase[i]==' '){
     fraseFinal += frase.substr(i+1) + " ";
     frase.erase(i);
   }

 }

 fraseFinal += frase;

cout << fraseFinal;

*/

/*
EJERCICIO 4
Escribe un programa que pida una frase y una palabra. El programa debe construir un string que contenga la frase original pero sustituyendo la palabra especificada por el caracter *. Por ejemplo:
Si el usuario teclea la frase:
Este es un ejemplo con un conjunto de palabras que tienen la palabra un varias veces.
Y la palabra: un
El programa construir� el string:
Este es * ejemplo con * conj*to de palabras que tienen la palabra * varias veces.
*/

/*string palabra, frase, fraseNueva;
int idx = 0;
cout << "Ingrese la frase: \n";
getline(cin, frase);
cout << "Bien, ahora ingrese la palabra a sustituir: \n";
getline(cin, palabra);

for (int i = 0; i < frase.length(); i++){
    idx = frase.find(palabra);
    if (idx>=0){
        frase.erase(idx, palabra.length()-1);
        frase[idx] = '*';
    }
}
cout << frase;
*/

/*
EJERCICIO 5
Escribe un programa que pida al usuario un n�mero flotante positivo, pero lo debe leer en una variable string.
El programa debe verificar que se trata de un n�mero de punto flotante.
Es decir, debe verificar que solamente contiene d�gitos (caracteres del �0� al �9�) y puede contener o no punto decimal (solo uno).
*/

/*
string posibleNumero;
bool digito = true;
int puntos = 0;
cout << "Ingrese el numero: ";
getline(cin, posibleNumero);
for (int i = 0; i < posibleNumero.length() && puntos < 2 && digito; i++){

    if (isdigit(posibleNumero[i]) == false){
        digito = false;
        if (posibleNumero[i] == '.'){
        puntos++;
        digito = true;
    }
    }
}

if (puntos > 1 || digito == false){
    cout << "No es digito";
} else {
    cout << "Es digito";
}

*/

/*
EJERCICIO 6
Escribe un programa que pida al usuario una frase. Esta frase puede contener espacios en blanco de
más (al inicio, al final y entre las palabras). Tu programa debe eliminar los espacios en blanco que sobren,
de manera que no queden espacios en blanco ni al inicio ni al final y que haya solamente un espacio separando cada palabra.
*/

string frase;
cout << "Teclee una frase: ";
getline (cin, frase);

for (int i = 0, idx; i < frase.length(); i++){
  if (frase[0]==' '||frase[frase.length()-1] == ' '){
      if (frase[0]==' '){
      frase.erase(0, 1);
      }
      if (frase[frase.length()-1] == ' ') {
        frase.erase(frase.length()-1, 1);
  }
  } else {
    idx = frase.find(' ');
    if (idx >= 0){
      if (frase[idx-1] == ' ' || frase[idx+1] == ' '){
        frase.erase(idx, 1);
      }
    }
  }

}

cout << frase;

}
