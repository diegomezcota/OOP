#ifndef triangle_h
#define triangle_h

#include <iostream>
using namespace std;

class triangle {
  protected:
  int iSide;
  char cChar;
  public:
  triangle();
  triangle(int, char);
  void setSide(int);
  void setChar(char);
  int getSide();
  char getChar();
  void show();
};

triangle::triangle(){
  iSide = 0;
  cChar = '*';
}

triangle::triangle(int iSide, char cChar){
  this->iSide = iSide;
  this->cChar = cChar;
}

void triangle::setSide(int iSide){
  this->iSide = iSide;
}

void triangle::setChar(char cChar){
  this->cChar = cChar;
}

int triangle::getSide(){
  return iSide;
}

char triangle::getChar(){
  return cChar;
}

void triangle::show(){
   for (int iK=1, iA=1; iK<=iSide; iK++, iA=iA+2){
    for (int iE=iSide-iK; iE>=0; iE--){
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
}

#endif