#ifndef actor_h
#define actor_h

#include <string>

using namespace std;

class actor {
  public:
    actor();
    actor(int, string);
    void setID(int);
    void setName(string);
    void printActorInfo();
    int getID();
    string getName();
  private:
    int iID;
    string sName;
};

actor::actor(){
  iID = 0;
  sName = "";
}

actor::actor(int iID, string sName){
  this->iID = iID;
  this->sName = sName;
}

void actor::setID(int iID){
  this->iID = iID;
}

void actor::setName(string sName){
  this->sName = sName;
}

int actor::getID(){
  return iID;
}

string actor::getName(){
  return sName;
}

void actor::printActorInfo(){
  cout << "\nActor ID: " << iID;
  cout << "\nName: " << sName << endl;
}

#endif