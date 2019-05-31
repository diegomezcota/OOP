#ifndef persona_h
#define persona_h
#include <string>
using namespace std;

class persona {
    private:
    string sNombre;
    string sNumCel;
  public:
    persona();
    persona(string, string);
    string getNombre();
    string getNumero();
    void setNombre(string);
    void setNumero(string);
};

persona::persona(){
  sNombre = "";
  sNumCel = "";
}

persona::persona(string nombre, string num){
  sNombre = nombre;
  sNumCel = num;
}

string persona::getNombre(){
   return sNombre;
}

string persona::getNumero(){
  return sNumCel;
}

void persona::setNombre(string nombre){
  sNombre = nombre;
}

void persona::setNumero(string numero){
  sNumCel = numero;
}
#endif