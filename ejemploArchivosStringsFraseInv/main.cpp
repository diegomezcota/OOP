#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void volteaLaFrase(string frase, string &fraseInv)
{
    string nuevoStr[20]={""}; //arreglo de strings
    int i=0;
    long lugar;
    fraseInv="";
    lugar=frase.find(".");
    if (lugar >= 0) frase.erase(lugar, 1);
    lugar=frase.find("\r");
    if (lugar >= 0) frase.erase(lugar, 1);
    lugar = frase.find(" "); // encuentro el primer espacio
    while (lugar>=0) {
        nuevoStr[i] = frase.substr(0,lugar); // copio la primer palabra
        frase.erase(0,lugar+1); // borro la palabra que ya copie
        lugar=frase.find(" "); // encuentro el siguiente espacio
        i++;
    }
    long tamano = frase.length();
    nuevoStr[i] = frase.substr(0,tamano); // copio la ultima palabra qutandole el \r
    while (i>=0)  {
        fraseInv += (nuevoStr[i] + " ");
        i--;
    }
}

int main() {
    string frase;
    
// Sección de archivo
//    string ruta = "/Users/L00305755/Documents/TC2016/ActividadesSalon/Archivos/Archivos/";
// ya no ocupé la ruta porque la especifiqué en Product Scheme editScheme Options
    
    ifstream archEnt("frases.txt"); // declaro y abro los archivos de entrada y salida
    ofstream archSal("salida.txt");

    if (archEnt.is_open()) // si pude abrir el archivo de entrada
    {
    while (!archEnt.eof())
    {
        getline(archEnt,frase);
        if (frase != "") {
            volteaLaFrase(frase, fraseInv);
            archSal << fraseInv << endl; // escribo la frase en el arch de salida
            cout << fraseInv << endl;
        }
    }
        
    archEnt.close();
    }
    else cout << " NO abri el archivo" << endl;
    archSal.close();
    return 0;
}