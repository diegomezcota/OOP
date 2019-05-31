#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
 ifstream archEnt("metercomas.txt");
 ofstream archSal("comadas.txt");
 string numero;
 if (archEnt.is_open()){
   while (!archEnt.eof()){
    getline(archEnt, numero);
    int residuo, division, longitud;
    longitud = numero.length();
    residuo = longitud % 3;
    division = longitud / 3;
    if (longitud <= 3){
      archSal << numero;
    } else {
      for (int i = 0; i < residuo; i++){
        archSal << numero[i];
      }
      if (residuo != 0){
        archSal << ",";
      }
      for (int i = 0, comas = 0; i < longitud - residuo; i++){
        if (i%3==0 && comas < division && i != 0){
          archSal << ",";
          comas ++;
        }
        archSal << numero[i+residuo];
      }
    }

   archSal << endl;

   }

 } else {
   cout << "No abri el archivo.";
 }
 archEnt.close();
 archSal.close();
 return 0;
}
