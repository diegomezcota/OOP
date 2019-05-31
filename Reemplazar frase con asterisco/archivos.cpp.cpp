#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
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
    string frase, palabra;
    string fraseNueva = "";
    int idx;
    ifstream archEnt("frases.txt");
    ofstream archSal("salida.txt");
   if (archEnt.is_open()) // si pude abrir el archivo de entrada
    {
    while (!archEnt.eof())
    {   
        if (frase != "") {
            cout << "Ingrese la frase: \n";
            getline(archEnt, frase);
            cout << frase;
            cout << "Bien, ahora ingrese la palabra a sustituir: \n";
            getline(cin, palabra);

        for (int i = 0; i < frase.length(); i++){
        idx = frase.find(palabra);
         if (idx>=0){
        frase.erase(idx, palabra.length()-1);
        frase[idx] = '*';
    }
}
    archSal << frase << endl;
    cout << frase << endl;
        }
    }
        
    archEnt.close();
    }
    else cout << " NO abri el archivo" << endl;
    archSal.close();
    return 0;
}