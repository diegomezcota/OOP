#ifndef court_h
#define court_h

#include <string>

class court : public service {
  private:
    double dCostPerHour;
    int iMaxAmountPeople;
    string sSport;
  public:
    court();
    court(string, int, char, double, int, string);
    double getCostPerHour() {return dCostPerHour;}
    int getMaxAmountPeople() {return iMaxAmountPeople;}
    string getSport() {return sSport;}
    void setCostPerHour(double);
    void setMaxAmountPeople(int);
    void setSport(string);
    void show();
    double calculateCost(int);
};

court::court(){
  dCostPerHour = 0;
  iMaxAmountPeople = 0;
  sSport = "N/A";
}

court::court(string s, int i, char c, double dCost, int iMax, string sSport) : service (s, i, c){
  dCostPerHour = dCost;
  iMaxAmountPeople = iMax;
  this->sSport = sSport;
}

void court::setCostPerHour(double dCostPerHour){
  this->dCostPerHour = dCostPerHour;
}

void court::setMaxAmountPeople(int iMaxAmountPeople){
  this->iMaxAmountPeople = iMaxAmountPeople;
}

void court::setSport(string sSport){
  this->sSport = sSport;
}

void court::show(){
  switch (this->getType()){
    case 'T':
    cout << endl << "Court";
    break;
    case 'F':
    cout << endl << "Court";
    break;
    case 'V':
    cout << endl << "Court";
    break;
    default:
    cout << "\nUnknown sport court.";
    break; 
  }
  service::show();
  cout << "\nCost x Hour: $" << this->dCostPerHour;
  cout << "\nMax amount of people: " << this->iMaxAmountPeople;
  cout << "\nSport: " << this->sSport;
}

double court::calculateCost(int iMinutes){
  if (iMinutes % 60 != 0){
    return (iMinutes / 60 * dCostPerHour + dCostPerHour);
  }
  return iMinutes/60*dCostPerHour;
}

#endif