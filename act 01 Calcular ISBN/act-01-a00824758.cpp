#include <iostream>
#include <string>

using namespace std;

int main(){
   int iResiduo;
   string sNumero, sSeguir="S";
   do {
     if (sSeguir == "S"){
       int iSuma = 0;
   cout << "Teclee el numero de 9 digitos: ";
   getline(cin, sNumero);
   if (sNumero.length() != 9) {
       cout << "Termino incorrecto.\n";
   }
   else {
       for (int i = 0; i < 9; i++){
           iSuma += (int(sNumero[i]) - 48) * (i+1);
       }
    iResiduo = iSuma % 11;
    if (iResiduo != 10){
        cout << "El ISBN es " << sNumero << "-" << iResiduo << endl;
    } else {
        cout << "El ISBN es " << sNumero << "-X\n";
    }

     }

   }

    cout << "Continuar?(S/N): ";
    getline(cin, sSeguir);

   } while (sSeguir != "N");

   return 0;
}
