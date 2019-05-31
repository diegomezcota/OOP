#include <iostream>
#include "empleado.h"
#include <fstream>

using namespace std;

int realID(empleado arrEmp[20]){
  int i = 0, id;
  bool bExiste = false;

  do {
  
  cout << "Ingrese el ID del empleado: ";
  cin >> id;

  for(; i < 20; i++){
    if (arrEmp[i].getID() == id){
      return i;
    }
  }

  if (!bExiste){
    cout << "El ID no existe.\n";
  }

  } while (bExiste == false);

  return 0;
}

char mostrarMenu(){

  char cOpcion;

  cout << "\nA. Modificar sueldo fijo\nB. Modificar sueldo por horas\nC. Registrar horas trabajadas\nD. Calcular pago del empleado\nE. Ver lista empleados.\nF. Terminar\nTeclee la opcion: ";

  cin >> cOpcion;

  return cOpcion;
}

void verLista(empleado arrEmp[20]){
  for (int i = 0; i < 20 && arrEmp[i].getID() != -1; i++){
    cout << endl << i + 1 << endl << "ID: " << arrEmp[i].getID() << endl << "Sueldo Fijo: " << arrEmp[i].getSueldoFijo() << endl << "Sueldo por Hora: " << arrEmp[i].getSueldoPorHora() << endl << "Horas Trabajadas: " << arrEmp[i].getHorasTrabajadas() << endl << "Pago: " << arrEmp[i].calcularPago() << endl;
  }
}

void calcularPago(empleado arrEmp[20]){
  int i = realID(arrEmp);
  cout << "El saldo es de $" << arrEmp[i].calcularPago();
}

void registrarHorasTrabajadas(empleado arrEmp[20]){
    
  int i = realID(arrEmp);
  int iHoras;
      
  cout << "Ingrese las horas trabajadas: ";      
  cin >> iHoras;
      
  if (iHoras >= 0){
  arrEmp[i].registrarHoras(iHoras);
  } else {
    cout << "El valor es negativo e incorrecto.";
  }
}  

void modificarSueldoPorHora(empleado arrEmp[20]){
  
  int i = realID(arrEmp);
  double sueldoXHora;
  
  cout << "Ingrese el valor del nuevo sueldo por hora: ";      
  cin >> sueldoXHora;
  
  if (sueldoXHora >= 0){
  arrEmp[i].setSueldoPorHora(sueldoXHora);
  } else {
  cout << "El valor es negativo e incorrecto.";
  }
       
}

void modificarSueldoFijo(empleado arrEmp[20]){
 
  int i = realID(arrEmp);
  double sueldoFijo;

  cout << "Ingrese el valor del nuevo sueldo fijo: ";      
  cin >> sueldoFijo;

  if (sueldoFijo >= 0){
  arrEmp[i].setSueldoFijo(sueldoFijo);
  } else {
    cout << "El valor es negativo e incorrecto.";
  } 
}

void setValues(empleado arrEmp[20]){
  
  int id, horas, i;
  double sueldoFijo, sueldoPorHora;
  
  ifstream inFile("data.txt");

  if (inFile.is_open()){
    while(!inFile.eof()){
      inFile >> id >> sueldoFijo >> sueldoPorHora >> horas;
      arrEmp[i].setID(id);
      arrEmp[i].setSueldoFijo(sueldoFijo);
      arrEmp[i].setSueldoPorHora(sueldoPorHora);
      arrEmp[i].setHorasTrabajadas(horas);
      i++;
    }
  } else {
    cout << "No abri el archivo\n"; 
  }
  inFile.close();
}

int main() {

empleado arrEmp[20];
char cOpcion = ' ';

setValues(arrEmp);

cOpcion = mostrarMenu();

  do {

  if (cOpcion == 'A'){
    modificarSueldoFijo(arrEmp);
  } else if (cOpcion == 'B'){
    modificarSueldoPorHora(arrEmp);
  } else if (cOpcion == 'C'){
    registrarHorasTrabajadas(arrEmp);
  } else if (cOpcion == 'D'){
    calcularPago(arrEmp);
  } else if (cOpcion == 'E'){
    verLista(arrEmp);
  } else if (cOpcion == 'F'){
    cout << "Gracias, adios.";
  } else {
    cout << "Opcion incorrecta, ingresela de nuevo";
  }

  cOpcion = mostrarMenu();

} while (cOpcion != 'F');

return 0;
}