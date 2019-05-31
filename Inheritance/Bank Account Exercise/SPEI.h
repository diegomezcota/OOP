#ifndef SPEI_h
#define SPEI_h

#include "CtaBanc.h"

class SPEI : public CtaBanc {
  public:
    SPEI();
    SPEI(int, double, double);
    void show();
    bool retire(double);
    void setFee(double dFee) {this->dFee = dFee;}
    double getFee() {return dFee;}
  private:
    double dFee;  
};

SPEI::SPEI() : CtaBanc(){
  dFee = 0;
}

SPEI::SPEI(int iAcc, double dBal, double dFee) : CtaBanc(iAcc, dBal){
  this->dFee = dFee;
}

void SPEI::show(){
  CtaBanc::show();
  cout << "The fee charge is " << dFee << "%\n"; 
}

bool SPEI::retire(double dAmount){
  if (dAmount * (1 + dFee/100) <= dBalance){
    CtaBanc::retire(dAmount);
    dBalance -= dAmount * dFee/100;
    return true;
  }
  return false;
}

#endif