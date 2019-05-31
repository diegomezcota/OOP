#ifndef taxi_h
#define taxi_h

using namespace std;

#include <string>
#include <persona.h>

static int iCant = 0;

class taxi {
  public:
    taxi();
    taxi(persona, int);
    void setPersona(persona);
    void setIdent(int);
    persona getPersona();
    int getIdent();
    int getCant();
  private:
    persona pPersona;
    int iIdent;
};

taxi::taxi(){
  persona per;
  pPersona = per;
  iIdent = 0;
  iIdent = iCant + 1;
}

taxi::taxi(persona per, int ident){
  pPersona = per;
  iIdent = ident;
}

void taxi::setPersona(persona per){
  pPersona = per;
}

void taxi::setIdent(int ident){
  iIdent = ident;
}

persona taxi::getPersona(){
  return pPersona;
}

int taxi::getIdent(){
  return iIdent;
}

int taxi::getCant(){
  return iCant;
}

#endif