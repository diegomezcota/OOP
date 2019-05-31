#ifndef triangleName_h
#define triangleName_h

#include "triangle.h"
#include <string>

class triangleName : public triangle {
  private:
    string sName;
  public:
    triangleName();
    triangleName(int, char, string);
    string getName();
    void setName(string);
    void show();
};

triangleName::triangleName() : triangle(){
  sName = " ";
}

triangleName::triangleName(int iS, char cChar, string sN):triangle(iS, cChar){
  sName = sN;
}

string triangleName::getName(){
  return sName;
}

void triangleName::setName(string sName){
  this->sName = sName;
}


void triangleName::show(){

  if (sName.length() < iSide*2-1){
    for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK; iE>0; iE--){
      cout << " ";
    }
    for (int iD=1; iD<=iA; iD++){
      if (iD%2==0){
        cout << " ";
      } else {
        cout << cChar;
      }
    }
    cout << endl;
  }
    for (int i = 0; i < ((iSide*2-1) - sName.length())/2; i++){
      cout << " ";
    }
    cout  << sName;
 } 
 
 else {
    for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK+((sName.length() - (iSide*2-1))/2); iE>0; iE--){
      cout << " ";
    }
    for (int iD=1; iD<=iA; iD++){
      if (iD%2==0){
        cout << " ";
      } else {
        cout << cChar;
      }
    }
    cout << endl;
  }
    cout  << sName;
 }


}


#endif