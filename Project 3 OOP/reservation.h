#ifndef reservation_h
#define reservation_h

#include <string>
#include <hour.h>

class reservation {
  private:
    string sServiceID;
    int iClientID;
    hour hStartingHour;
    int iLength;
  public:
    static int iReservations;
    reservation();
    reservation(string, int iClientID, hour, int iLength);
    hour calculateReservationEnd();
    string getServiceID() {return sServiceID;}
    int getClientID() {return iClientID;}
    hour getStartingHour() {return hStartingHour;}
    int getLength() {return iLength;}
    void setServiceID(string);
    void setClientID(int);
    void setStartingHour(hour);
    void setLength(int);
};

reservation::reservation(){
  sServiceID = "N/A";
  iClientID = 0;
  iLength = 0;
  hour h;
  hStartingHour = h;
}

reservation::reservation(string sServiceID, int iClientID, hour hStartingHour, int iLength){
  this->sServiceID = sServiceID;
  this->iClientID = iClientID;
  this->hStartingHour = hStartingHour;
  this->iLength = iLength;
}

void reservation::setServiceID(string sServiceID){
  this->sServiceID = sServiceID;
}

void reservation::setClientID(int iClientID){
  this->iClientID = iClientID;
}

void reservation::setStartingHour(hour hStartingHour){
  this->hStartingHour = hStartingHour;
}

void reservation::setLength(int iLength){
  this->iLength = iLength;
}

hour reservation::calculateReservationEnd(){
  hour h;
  h = this->hStartingHour + iLength;
  return h;
}

#endif