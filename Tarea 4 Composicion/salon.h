#ifndef salon_h
#define salon_h

#include "computadora.h"

class salon {
  public:
  salon();
  string getSalon();
  computadora getCompu();
  void setSalon(string);
  void setCompu(computadora);
  private:
  string sNumSalon;
  computadora cCompu;
};

salon::salon(){
  computadora c;
  cCompu = c;
  sNumSalon = "0000";
}

string salon::getSalon(){
  return sNumSalon;
}

computadora salon::getCompu(){
  return cCompu;
}

void salon::setSalon(string salon){
  sNumSalon = salon;
}

void salon::setCompu(computadora compu){
  cCompu = compu;
}

#endif