#ifndef computadora_h
#define computadora_h

class computadora {
  public:
    computadora();
    string getMarca();
    string getOS();
    int getRAM();
    void setMarca(string);
    void setOS(string);
    void setRAM(int);
  private:
    string sMarca, sOS;
    int iRAM;
};

computadora::computadora(){
  sMarca = "Sin marca.";
  sOS = "No tiene sistema.";
  iRAM = 0;
}

string computadora::getMarca(){
  return sMarca;
}

string computadora::getOS(){
  return sOS;
}

int computadora::getRAM(){
  return iRAM;
}

void computadora::setMarca(string marca){
  sMarca = marca;
}

void computadora::setOS(string OS){
  sOS = OS;
}

void computadora::setRAM(int RAM){
  iRAM = RAM;
}

#endif 