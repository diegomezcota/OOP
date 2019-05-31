#ifndef function_h
#define function_h

#include <string>
#include <hour.h>

using namespace std;

class function {
  private:
    string sFunctionID;
    int iMovieNumber, iRoom;
    hour hHour;
  public:
    function();
    function(string, int, hour, int);
    string getFunctionID();
    int getMovieNumber();
    hour getHour();
    int getRoom();
    void setFunctionID(string);
    void setMovieNumber(int);
    void setHour(hour);
    void setRoom(int);
    void showFunctionInfo();
};

function::function(){
  sFunctionID = "";
  iMovieNumber = 0;
  iRoom = 0;
  hour h;
  hHour = h;
}

void function::showFunctionInfo(){
  cout << "\nFunction key: " << sFunctionID;
  cout << "\nMovie Number: " << iMovieNumber;
  cout << "\nRoom: " << iRoom;
  cout << "\nHour: ";
  hHour.showHourInfo();
}

function::function(string sFunctionID, int iMovieNumber, hour hHour, int iRoom){
  this->sFunctionID = sFunctionID;
  this->iMovieNumber = iMovieNumber;
  this->hHour = hHour;
  this->iRoom = iRoom;
}

string function::getFunctionID(){
  return sFunctionID;
}

int function::getMovieNumber(){
  return iMovieNumber;
}

hour function::getHour(){
  return hHour;
}

int function::getRoom(){
  return iRoom;
}

void function::setFunctionID(string sFunctionID){
  this->sFunctionID = sFunctionID;
}

void function::setMovieNumber(int iMovieNumber){
  this->iMovieNumber = iMovieNumber;
}

void function::setHour(hour hHour){
  this->hHour = hHour;
}

void function::setRoom(int iRoom){
  this->iRoom = iRoom;
}

#endif