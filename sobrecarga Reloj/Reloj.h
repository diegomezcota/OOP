//
//  Sobrecarga-Reloj
//
//  Created by David A Cantú Delgado on 3/25/19.
//  Copyright © 2019 Tec de Monterrey. All rights reserved.
//

#ifndef Reloj_h
#define Reloj_h

class Reloj {
private:
    int hora;
    int minu;
public:
    Reloj();
    Reloj(int hora);
    Reloj(int hora, int minu);
    void setHora(int h);
    void setMin(int m);
    int getHora();
    int getMin();
    void muestra();
    void operator++();  // incrementa un minuto al reloj
    void operator--();  // decrementa un minuto al reloj
    void operator+=(int); //se suman los minutos
    void operator-=(int); //se restan los minutos
    Reloj operator+(int);  // suma un Reloj con una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator+(Reloj, Reloj);  // suma un Reloj con otro Reloj y regresa un nuevo Reloj
    Reloj operator-(int m);  // a un Reloj le resta una cantidad de minutos y regresa el nuevo Reloj
    friend Reloj operator-(Reloj, Reloj); // a un Reloj le resta otro Reloj y regresa el nuevo Reloj
    bool operator>(Reloj r);  // regresa true/false si el primer Reloj es > el segundo
    bool operator<(Reloj r); // regresa true/false si el primer Reloj es < el segundo
    bool operator==(Reloj r); // regresa true/false si ambos relojes son iguales
};

Reloj::Reloj(){
    hora = 0;
    minu = 0;
}
Reloj::Reloj(int hora){
    this->hora = hora;
    minu = 0;
}
Reloj::Reloj(int hora, int minu){
    this->hora = hora;
    this->minu = minu;
}

void Reloj::setHora(int h){
    hora = h;
}

void Reloj::setMin(int m){
    minu = m;
}

int Reloj::getHora(){
    return hora;
}

int Reloj::getMin(){
    return minu;
}


void Reloj::muestra(){
    if (hora<10)
        cout << "0";
    cout <<hora<<":";
    if (minu<10)
        cout << "0";
    cout <<minu<<endl;
}

//////////////////////////////////
//  Aqui va tu codigo
//////////////////////////////////
void Reloj::operator++(){
  minu++;
  if (minu == 60){
    minu = 0;
    hora++;
    if (hora == 24){
      hora = 0;
    }
  }
}

void Reloj::operator--(){
  minu--;
  if (minu == -1){
    minu = 59;
    hora--;
    if (hora == -1){
      hora = 23;
    }
  }
}

void Reloj::operator+=(int minu){
  this->minu += minu;
  hora += this->minu/60;
  this->minu = this->minu%60;
  if (hora >= 24){
    hora = hora % 24;
  }
}

void Reloj::operator-=(int minu){
  this->minu -= minu;
  while (this->minu < 0){
    this->minu+=60;
    this->hora-=1;
    if (this->hora < 0){
      this->hora = 23;
    }
  }
}

Reloj Reloj::operator+(int minu){
  Reloj r = *this;
  r.minu += minu;
  r.hora += r.minu/60;
  r.minu = r.minu%60;
  if (r.hora > 23){
    r.hora = r.hora%24;
  }
  return r;
}

Reloj Reloj::operator-(int minu){
  Reloj r = *this;
  r.minu -= minu;
  while (r.minu < 0){
    r.minu = r.minu + 60;
    r.hora -= 1;
    if (r.hora < 0){
      r.hora = 23;
    }
  }
  return r;
}

Reloj operator+(Reloj r1, Reloj r2){
  Reloj r = r1;
  r += (r2.minu + r2.hora * 60);
  return r;
}

Reloj operator-(Reloj r1, Reloj r2){
  Reloj r = r1;
  r -= r2.minu + r2.hora * 60;
  return r;
}

bool Reloj::operator>(Reloj r){
  int minuto1, minuto2;
  minuto1 = hora * 60 + minu;
  minuto2 = r.hora * 60 + r.minu;
  return (minuto1 > minuto2);
}

bool Reloj::operator<(Reloj r){
  int minuto1, minuto2;
  minuto1 = hora * 60 + minu;
  minuto2 = r.hora * 60 + r.minu;
  return (minuto1 < minuto2);
}

bool Reloj::operator==(Reloj r){
  int minuto1, minuto2;
  minuto1 = hora * 60 + minu;
  minuto2 = r.hora * 60 + r.minu;
  return (minuto1 == minuto2);
}

#endif /* Reloj_h */
