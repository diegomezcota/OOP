#ifndef Reloj_h
#define Reloj_h

using namespace std;

class Reloj {
  public:
   Reloj();
   Reloj(int h, int m);
   int getHora();
   int getMinu();
   void setHora(int h);
   void setMinu(int m);
   void muestraHora();
  private:
    int hora;
    int minu; 
};

Reloj::Reloj() {
  hora = 0;
  minu = 0;
}

Reloj::Reloj(int h, int m) {
  hora = h;
  minu = m;
}

int Reloj :: getHora() {
  return hora;
}

int Reloj :: getMinu() {
  return minu;
}

void Reloj :: setHora(int h) {
  hora = h;
}

void Reloj::setMinu(int m){
  minu = m;
}

void Reloj::muestraHora(){
  cout << endl;
  cout << "Hora: ";
  if (hora <= 9){
    cout << "0" << hora;
  } else {
    cout << hora;
  }
  cout << ":";
    if (minu <= 9){
    cout << "0" << minu;
  } else {
    cout << minu;
  }
}

#endif