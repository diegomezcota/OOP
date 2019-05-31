#include <iostream>
#include <string>

using namespace std;

#include "computadora.h"
#include "salon.h"

void showList(salon arrSal[], int iNum){
  cout << "Lista de salones:\n";
  string sSalon, sMarca, sOS;
  int iRAM;
  for (int i = 0; i < iNum; i++){
    cout << "Numero de salon: ";
    sSalon = arrSal[i].getSalon();
    cout << sSalon << endl;
    cout << "Marca de computadora: ";
    sMarca = arrSal[i].getCompu().getMarca();
    cout << sMarca << endl;
    cout << "Sistema Operativo: ";
    sOS = arrSal[i].getCompu().getOS();
    cout << sOS << endl;
    cout << "Memoria RAM: ";
    iRAM = arrSal[i].getCompu().getRAM();
    cout << iRAM << endl;
  }
}

void showByOS(salon arrSal[], int iNum){
  string sOS, sSalon;
  bool bExist = true;
  cout << "Ingrese el sistema operativo que busca: ";
  cin.ignore();
  getline(cin, sOS);

  for(int i = 0; i < iNum; i++){
    if (arrSal[i].getCompu().getOS() == sOS){
      if (bExist){
        cout << "Lista de salones:\n";
        bExist = false;
      }
      cout << "Num de salon: ";
      sSalon = arrSal[i].getSalon();
      cout << sSalon << endl;
    }
  }
}

void showByBrand(salon arrSal[], int iNum){
  string sBrand, sSalon;
  bool bExist = true;
  cout << "Ingrese la marca que busca: ";
  cin.ignore();
  getline(cin, sBrand);
  
  for (int i = 0; i < iNum; i++){
    if (arrSal[i].getCompu().getMarca() == sBrand){
      if (bExist){
        cout << "Lista de salones:\n";
        bExist = false;
      }
      cout << "Num de salon: ";
      sSalon = arrSal[i].getSalon();
      cout << sSalon << endl;
    }
  }
}

int desplegarMenu() {
  int iOpcion;
  cout << "1. Buscar marca.\n2. Buscar Sistema Operativo.\n3. Mostrar todos los salones.\n4. Terminar.\nIngrese el numero de la opcion deseada: ";
  cin >> iOpcion;
  return iOpcion;
}

int main() {
  int iNumSalones, iRAM;
  string sNumSalon, sMarca, sOS;
  salon arrSal[10];
  computadora cCompu;
  int iOpcion = 0;

  cout << "Ingrese el numero de salones a registrar: ";
  cin >> iNumSalones;

  for (int i = 0; i < iNumSalones; i++){
    cout << "Numero de salon: ";
    cin.ignore();
    getline(cin, sNumSalon);
    cout << "Marca de computadora: ";
    getline(cin, sMarca);
    cout << "Sistema operativo: ";
    getline(cin, sOS);
    cout << "Memoria RAM (GBs): ";
    cin >> iRAM;
    arrSal[i].setSalon(sNumSalon);
    cCompu.setOS(sOS);
    cCompu.setRAM(iRAM);
    cCompu.setMarca(sMarca);
    arrSal[i].setCompu(cCompu);
  }

  while (iOpcion != 4){

    iOpcion = desplegarMenu();

    switch (iOpcion){
      case 1:
      showByBrand(arrSal, iNumSalones);
      break;
      case 2:
      showByOS(arrSal, iNumSalones);
      break;
      case 3:
      showList(arrSal, iNumSalones);
      break;
      case 4:
      cout << "Gracias, buen dia.";
      break;
      default:
      cout << "Opcion incorrecta, intente de nuevo.\n";
      break;
    }
  }

}