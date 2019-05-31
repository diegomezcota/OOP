#ifndef lecture_h
#define lecture_h

#include <string>
using namespace std;

class lecture {
  protected:
    string sTitle, sAuthor;
  public:
    lecture();
    lecture(string, string);
    void setTitle(string);
    void setAuthor(string);
    string getTitle();
    string getAuthor();
    virtual void show() = 0;
};

lecture::lecture(){
  sTitle = "N/A";
  sAuthor = "N/A";
}

lecture::lecture(string sTitle, string sAuthor){
  this->sTitle = sTitle;
  this->sAuthor = sAuthor;
}

void lecture::setTitle(string sTitle){
  this->sTitle = sTitle;
}

void lecture::setAuthor(string sAuthor){
  this->sAuthor = sAuthor;
}

string lecture::getTitle(){
  return sTitle;
}

string lecture::getAuthor(){
  return sAuthor;
}

void lecture::show(){
  cout << "**********\nTitle: " << sTitle << "\nAuthor: " << sAuthor << endl;
}

#endif