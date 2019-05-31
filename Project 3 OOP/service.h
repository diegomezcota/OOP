#ifndef service_h
#define service_h

#include <string>
using namespace std;

class service {
  protected:
    string sKey;
    int iMaximumTime;
    char cType;
  public:
    static int iServices;
    service();
    service(string, int, char);
    string getKey() {return sKey;}
    int getMaximumTime() {return iMaximumTime;}
    char getType() {return cType;}
    void setKey(string);
    void setMaximumTime(int);
    void setType(char);
    virtual void show();
    virtual double calculateCost(int) = 0;
};

int service::iServices = 0;

service::service(){
  sKey = "N/A";
  iMaximumTime = 0;
  cType = '?';
  iServices++;
}

service::service(string sKey, int iMaximumTime, char cType){
  this->sKey = sKey;
  this->iMaximumTime = iMaximumTime;
  this->cType = cType;
  iServices++;
}

void service::show(){
  cout << "\nKey: " << sKey << "\nMax time: " << iMaximumTime << " minutes" << "\nType: " << cType;
}

void service::setKey(string sKey){
  this->sKey = sKey;
}

void service::setMaximumTime(int iMaximumTime){
  this->iMaximumTime = iMaximumTime;
}

void service::setType(char cType){
  this->cType = cType;
}

#endif