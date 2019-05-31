#ifndef hour_h
#define hour_h

#include <iostream>

using namespace std;

class hour {
  protected:
    int iHour;
    int iMinute;
  public:
    hour();
    hour(int, int);
    int getHour() {return iHour;}
    int getMinute() {return iMinute;}
    void setHour(int);
    void setMinute(int);
    hour operator + (int);
    bool operator >= (hour);
    friend bool operator <= (hour, hour);
    friend bool operator == (hour, hour);
    friend istream& operator>>(istream &is, hour &h);
    friend ostream& operator<<(ostream &os, hour h);
    friend void adjustHourValues(hour &h);
};

void adjustHourValues(hour &h){
  if (h.iMinute >= 60){
    h.iHour += h.iMinute / 60;
    h.iMinute = h.iMinute % 60;
  }
  if (h.iHour >= 24){
    h.iHour = h.iHour % 24;
  }
  if (h.iMinute < 0 && h.iHour < 0){
    h.iMinute = 0;
    h.iHour = 0;
   } else {
    if (h.iMinute < 0){
       h.iMinute += 60;
       h.iHour -= 1;
       adjustHourValues(h);
     }
     if (h.iHour < 0){
       h.iHour += h.iMinute/60;
       h.iMinute -= 60;
       adjustHourValues(h);
     }
  }
}

hour::hour(){
  iHour = 0;
  iMinute = 0;
}

hour::hour(int iHour, int iMinute){
  this->iMinute = iMinute;
  this->iHour = iHour;
  adjustHourValues(*this);
}

void hour::setHour(int iHour){
  this->iHour = iHour;
}

void hour::setMinute(int iMinute){
  this->iMinute = iMinute;
}

hour hour::operator+(int iMinutes){
  int iMin, iHr;
  iHr = iHour + iMinutes/60;
  iMin = iMinute + iMinutes%60;
  hour h(iHr, iMin);
  adjustHourValues(h);
  return h;
}

bool hour::operator>=(hour h2){
  if (this->iHour > h2.iHour){
    return true;
  } else if (this->iHour == h2.iHour){
    if (this->iMinute >= h2.iMinute){
      return true;
    }
  }
  return false;
}

bool operator <= (hour h1, hour h2){
  if (h1.iHour < h2.iHour){
    return true;
  } else if (h1.iHour == h2.iHour){
     if (h1.iMinute <= h2.iMinute){
       return true;
     }
  }
 return false; 
}

bool operator == (hour h1, hour h2){
  if (h1.iHour == h2.iHour && h1.iMinute == h2.iMinute){
    return true;
  }
  return false;
}

istream& operator>>(istream &is, hour &h){
  is >> h.iHour;
  is >> h.iMinute;
  return is;
}

ostream& operator<<(ostream &os, hour h){
  os << h.iHour;
  os << ":";
  if (h.iMinute < 10){
    os << "0";
  }
  os << h.iMinute;
  return os;
}

#endif