#ifndef hour_h
#define hour_h

using namespace std;

class hour {
  public:
    hour();
    hour(int, int);
    void setHour(int);
    void setMinute(int);
    void showHourInfo();
    int getHour();
    int getMinute();
  private:
    int iHour, iMinute;
};

hour::hour(){
  iHour = 0;
  iMinute = 0;
}

void hour::showHourInfo(){
  cout << "\nHora: " << iHour;
  cout << "\nMinute: " << iMinute << endl;
}

hour::hour(int iHour, int iMinute){
  this->iHour = iHour;
  this->iMinute = iMinute;
}

void hour::setHour(int iHour){
  this->iHour = iHour;
}

void hour::setMinute(int iMinute){
  this->iMinute = iMinute;
}

int hour::getHour(){
  return iHour;
}

int hour::getMinute(){
  return iMinute;
}

#endif