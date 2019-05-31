#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream archEntr("calificaciones.txt");
  ofstream archSal("promedio.txt");
  string linea;
  double dEncargo;
  int cantidad, matricula, calif;
  cout << "¿Cuántos trabajos encargó?" << endl;
  cin >> dEncargo;
  
  if (archEntr.is_open()){
    while (!archEntr.eof()){  
      int suma = 0;    
      archEntr >> matricula;
      archSal << matricula << " ";
      archEntr >> cantidad;
      for (int i = 0; i < cantidad; i++){
        archEntr >> calif;
        suma += calif;
      }
      archSal << suma / dEncargo << endl;
    }
  } else {
    cout << "No abri el archivo.";
  }

  archSal.close();
  archEntr.close();
  return 0;
}