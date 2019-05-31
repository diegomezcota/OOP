#ifndef fraccion_h
#define fraccion_h

class fraccion {
  public:
    fraccion();
    fraccion(int num, int den);
    ~fraccion();
    int getNumerador();
    int getDenominador();
    void setNumerador(int num);
    void setDenominador(int den);
    double calcValorReal();
  private:
    int denominador, numerador;  
};

fraccion::fraccion() {
  numerador = 1;
  denominador = 2;
}

fraccion::fraccion(int num, int den) {
  numerador = num;
  denominador = den;
}

int fraccion::getNumerador() {
  return numerador;
}

int fraccion::getDenominador() {
  return denominador;
}

fraccion::~fraccion(){

}

void fraccion::setNumerador(int num){
  numerador = num;
}

void fraccion::setDenominador(int den){
  denominador = den;
}

double fraccion::calcValorReal() {
  return (double) numerador / denominador;
}

#endif