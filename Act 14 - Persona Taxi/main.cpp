#include <iostream>
#include <persona.h>
#include <taxi.h>
#include <string>
using namespace std;

void consultarTaxista(taxi arrTaxi[], int iCont){
  string sNombre;
  bool bExiste = true;
  cout << "Ingrese el nombre del taxista: ";
  cin.ignore();
  getline(cin, sNombre);
  for (int i = 0; i < iCont; i++){
    if (sNombre == arrTaxi[i].getPersona().getNombre()){
      if (bExiste){
        cout << "Lista de IDs de taxis:\n";
        bExiste = false;
      }
      cout << "ID: " << arrTaxi[i].getIdent() << endl;
    }
  }
}

void desplegarTaxis(taxi arrTaxi[], int iCont){
  for (int i = 0; i < iCont; i++){
    cout << "Taxista: " << arrTaxi[i].getPersona().getNombre() << endl << "Numero celular: " << arrTaxi[i].getPersona().getNumero() << endl << "ID: " << arrTaxi[i].getIdent() << endl;
  }
}

char desplegarMenu(){
  char cOpcion;
  cout << "1.- Consulta lista de taxis disponibles." << endl << "2.- Consultar lista de taxis de responsable. " << endl << "3.- Agregar taxi." << endl << "4.- Terminar." << endl << "Ingrese el numero de la opcion que desee: ";
  cin >> cOpcion;
  return cOpcion;
}

void agregarTaxi(taxi arrTaxi[], int &iCont){
 persona pPersona;
 string sNombre, sNumCel;
 int iIdent;
  cout << "Nombre del responsable: ";
  cin.ignore();
  getline(cin, sNombre);
  cout << "Numero celular del responsable: ";
  cin.ignore();
  getline(cin, sNumCel);
  cout << "Numero de identificacion: ";
  cin >> iIdent;
  pPersona.setNombre(sNombre);
  pPersona.setNumero(sNumCel);
  arrTaxi[iCont].setPersona(pPersona);
  arrTaxi[iCont].setIdent(iIdent);
  iCont++;
}

int main() {
  taxi arrTaxi[1000];
  int iCont = 0;
 
  char cOpcion = ' ';

  while (cOpcion != 'n'){
    cout << "Desea agregar un taxi nuevo? (s/n): ";
    cin >> cOpcion;
    if (cOpcion == 's'){
      agregarTaxi(arrTaxi, iCont);
    } else if (cOpcion != 'n'){
      cout << "(s/n): ";
    }
  }

  while (cOpcion != '4'){
    cOpcion = desplegarMenu();
    switch (cOpcion) {
      case '1':
      desplegarTaxis(arrTaxi, iCont);
      break;
      case '2':
      consultarTaxista(arrTaxi, iCont);
      break;
      case '3':
      agregarTaxi(arrTaxi, iCont);
      break;
      case '4':
      cout << "Adios.";
      break;
      default:
      cout << "Opcion incorrecta." << endl;
      break;
    }
  }

return 0;
}