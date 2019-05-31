#ifndef complejo_h
#define complejo_h

class complejo{
  public:
    complejo();
    complejo(int re, int im);
    ~complejo();
    int getReal();
    int getImaginario();
    void setReal(int re);
    void setImaginario(int im);
    complejo sumaComplejo(int re, int im);
    complejo restaComplejo(int re, int im); 
  private:
    int real, imaginario;
};

complejo::complejo() {
  real = 0;
  imaginario = 0;
}

complejo::complejo(int re, int im){
  real = re;
  imaginario = im;
}

complejo::~complejo(){

}

int complejo::getReal(){
  return real;
}

int complejo::getImaginario(){
  return imaginario;
}

void complejo::setReal(int re){
  real = re;
}

void complejo::setImaginario(int im){
  imaginario = im;
}

complejo complejo::sumaComplejo(int re, int im){
  int iReal, iImaginario;
  iReal = real + re;
  iImaginario = imaginario + im;
  complejo temp(iReal, iImaginario);
  return temp;
}

complejo complejo::restaComplejo(int re, int im){
  int iReal, iImaginario;
  iReal = real - re;
  iImaginario = imaginario - im;
  complejo temp2(iReal, iImaginario);
  return temp2;
}

#endif