#ifndef evento_h
#define evento_h

using namespace std;

class evento {
  public:
    evento();
    evento(Reloj, int, string);
    Reloj getHoraInicial();
    int getDuracion();
    string getAsunto();
    void setHoraInicial(Reloj);
    void setDuracion(int);
    void setAsunto(string);
  private:
    Reloj horaInicial;
    int duracion;
    string sAsunto;
};

evento::evento() {
  Reloj hi(0, 0);
  horaInicial = hi;
  duracion = 0;
  sAsunto = "";
}

evento::evento(Reloj hi, int d, string a) {
  horaInicial = hi;
  duracion = d;
  sAsunto = a;
}

Reloj evento::getHoraInicial() {
  return horaInicial;
}

int evento::getDuracion(){
  return duracion;
}

string evento::getAsunto(){
  return sAsunto;
}

void evento::setHoraInicial(Reloj hi){
  horaInicial = hi;
}

void evento::setDuracion(int d){
  duracion = d;
}

void evento::setAsunto(string a){
  sAsunto = a;
}


#endif