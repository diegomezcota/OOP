#ifndef device_h
#define device_h

#include <service.h>
#include <string>

class device : public service {
  private:
    double dCostPer15Min;
    bool bWithInstructor;
    string sDescription;
  public:
    device();
    device(string, int, char, double, bool, string);
    void show();
    double calculateCost(int);
    double getCostPer15Min() {return dCostPer15Min;}
    bool includingInstructor() {return bWithInstructor;}
    string getDescription() {return sDescription;}
    void setCostPer15Min(double);
    void setInstructorInclusion(bool);
    void setDescription(string);
};

device::device() : service(){
  dCostPer15Min = 0;
  bWithInstructor = false;
  sDescription = "N/A";
}

device::device(string s, int i, char c, double dCost, bool bInstr, string sDesc) : service(s, i, c){
  dCostPer15Min = dCost;
  bWithInstructor = bInstr;
  sDescription = sDesc;
}

void device::setCostPer15Min(double dCostPer15Min){
  this->dCostPer15Min = dCostPer15Min;
}

void device::setInstructorInclusion(bool bWithInstructor){
  this->bWithInstructor = bWithInstructor;
}

void device::setDescription(string sDescription){
  this->sDescription = sDescription;
}

void device::show(){

  switch (this->getType()){
    case 'C':
    cout << "\nDevice: Walking machine";
    break;
    case 'B':
    cout << "\nDevice: Escalator";
    break;
    case 'E':
    cout << "\nDevice: Stationary bike";
    break;
    default:
    cout << "\nUnknown device.";
    break; 
  }
  service::show();
  cout << "\nCost x 15 Minutes: $" << this->dCostPer15Min;
  if (bWithInstructor){
    cout << "\nIncludes instructor";
  } else {
    cout << "\nNo instructor";
  }
  cout << "\nDescription: " << this->sDescription;
}  

double device::calculateCost(int iMinutes){
  if (iMinutes % 15 != 0){
    return (iMinutes / 15 * dCostPer15Min + dCostPer15Min);
  }
  return iMinutes/15*dCostPer15Min;
}

#endif