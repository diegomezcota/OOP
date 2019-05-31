#ifndef eTutorial_h
#define eTutorial_h

#include <string>

using namespace std;

class eTutorial : public lecture {
  protected:
    string sURL, sLastUpdate;
  public:
    eTutorial();
    eTutorial(string, string, string, string);
    string getURL() {return sURL;}
    string getLastUpdate() {return sLastUpdate;}
    void setURL(string);
    void setLastUpdate(string);
    void show();
};

eTutorial::eTutorial():lecture(){
  sURL = "N/A";
  sLastUpdate = "N/A";
}

eTutorial::eTutorial(string sTitle, string sAut, string sURL, string sLastUpdate):lecture(sTitle, sAut){
  this->sURL = sURL;
  this->sLastUpdate = sLastUpdate;
}

void eTutorial::setURL(string sURL){
  this->sURL = sURL;
}

void eTutorial::setLastUpdate(string sLastUpdate){
  this->sLastUpdate = sLastUpdate;
}

void eTutorial::show(){
  lecture::show();
  cout << "URL: " << sURL << "\nLast Update: " << sLastUpdate << endl;
}

#endif