#ifndef book_h
#define book_h

#include <lecture.h>
#include <string>

class book : public lecture {
  protected:
    string sEditorial;
    int iPageAmount;
  public:
    book();
    book(string, string, string, int);
    void setEditorial(string);
    void setPageAmount(int);
    string getEditorial() {return sEditorial;}
    int getPageAmount() {return iPageAmount;}
    void show();
};

book::book():lecture() {
  sEditorial = "N/A";
  iPageAmount = 0;
}

book::book(string sTitle, string sAut, string sEd, int iPages) : lecture(sTitle, sAut){
  sEditorial = sEd;
  iPageAmount = iPages;
}

void book::setEditorial(string sEditorial){
  this->sEditorial = sEditorial;
}

void book::setPageAmount(int iPageAmount){
  this->iPageAmount = iPageAmount;
}

void book::show(){
  lecture::show();
  cout << "Editorial: " << sEditorial << "\nPage Amount: " << iPageAmount << endl;
}

#endif