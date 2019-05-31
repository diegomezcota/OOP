//
//  claseTiempo.cpp
//
//  Created by Yolanda Martinez on 3/9/17.
//  Copyright Â© 2017 com.itesm. All rights reserved.
//
//  Alumno Diego Gomez Cota
//  A00824758

#include <iostream>
using namespace std;

/*
 Implementa los funciones faltantes de la Clase Tiempo
 El valor de hora puede ser cualquier valor positivo
 El valor de minutos debe ser un valor entre 0 y 59
 Al realizar cualquier operaciÃ³n, el tiempo (hora y minutos) debe quedar con valores vÃ¡lidos
 */
class Tiempo {
    
public:
    Tiempo();
    Tiempo(int h, int m);
    void setHora(int h);
    void setMinu(int m);
    int getHora();
    int getMinu();
    void muestra();
    
    // Miembro de la clase. operador ++ incrementa el Tiempo en 1 minuto y regresa el tiempo
    Tiempo operator++();
    //Friend. operador -- decrementa el Tiempo en 1 minuto y regresa el tiempo
    // si la hora es 0:0 y se pide decrementar, regresa 0:0
    friend Tiempo operator--(Tiempo);
    // Miembro de la clase. operador > Compara si el primer Tiempo es mayor que el segundo
    bool operator>(Tiempo);
    // Miembro de la clase. operador + Para sumar tiempo + minutos, regresa un tiempo como resultado
    Tiempo operator+(int);
    // Friend. operador + Para sumar minutos + tiempo, regresa un tiempo como resultado
    friend Tiempo operator+(int, Tiempo);
    // Miembro de la clase. operador + Suma t1 con t2 y regresa un tiempo con el resultado
    Tiempo operator+(Tiempo);
    // Friend. operador += Suma t1 con t2 y deja el resultado en t1, no regresa nada
    friend void operator+=(Tiempo &t, Tiempo);
    // Friend. funcion que arregla la hora, si algun valor es negativo le asignamos 0, si los minutos son mayor a 59 ajustamos valores
    friend void ajustarTiempo(Tiempo &t1);
    
private:
    int hora;
    int minu;
};

Tiempo::Tiempo() {
    hora = 0;
    minu = 0;
}

Tiempo::Tiempo(int h, int m) {
    hora = h;
    minu = m;
}

void Tiempo::setHora(int h) {
    hora = h;
}

void Tiempo::setMinu(int m) {
    minu = m;
}

int Tiempo::getHora() {
    return hora;
}

int Tiempo::getMinu() {
    return minu;
}

void Tiempo::muestra() {
    cout <<hora<<":";
    if (minu<10)
        cout << "0" <<minu;
    else
        cout << minu;
}

Tiempo Tiempo::operator++(){
  this->minu++;
  ajustarTiempo(*this);
  return *this;
}

bool Tiempo::operator>(Tiempo t2){
  if (this->hora > t2.hora){
    return true;
  } else if (this->hora == t2.hora){
    if (this->minu > t2.minu){
      return true;
    }
  }
  return false;
}

Tiempo Tiempo::operator+(int iMin){
  Tiempo tRes = *this;
  tRes.minu += iMin;
  ajustarTiempo(tRes);
  return tRes;
}

Tiempo operator--(Tiempo t1){
  if (t1.minu == 0 && t1.hora == 0){
    return t1;
  } else {
    t1.minu--;
  }
  ajustarTiempo(t1);
  return t1;
}

Tiempo operator+(int iMin, Tiempo t1){
  Tiempo tRes;
  tRes = t1;
  tRes.minu = t1.minu + iMin;
  ajustarTiempo(tRes);
  return tRes;
}

Tiempo Tiempo::operator+(Tiempo t2){
  Tiempo tRes = *this;
  tRes.hora += t2.hora;
  tRes.minu += t2.minu;
  ajustarTiempo(tRes);
  return tRes;
}

void operator+=(Tiempo &t1, Tiempo t2){
  t1.hora += t2.hora;
  t1.minu += t2.minu;
  ajustarTiempo(t1);
}


void ajustarTiempo(Tiempo &t1){
  if (t1.hora < 0){
    t1.hora = 0;
  }
  if (t1.minu < 0){
    t1.minu = 0;
  }
  if (t1.minu > 59){
    t1.hora += t1.minu/60;
    t1.minu = t1.minu%60;
  }
}


int main() {
    int t1h, t1m, t2h, t2m, t4h, t4m, t5h, t5m;
    char opcion;
    Tiempo t3, t6, t7(15, 59), t8(0,0), t9;
    
    // teclear los valores para tiempo 1, tiempo2, tiempo4 y tiempo5
    cin >> t1h >> t1m >> t2h >> t2m >> t4h >> t4m >> t5h >> t5m;
    Tiempo t1(t1h, t1m), t2(t2h, t2m);
    Tiempo t4(t4h, t4m), t5(t5h, t5m);
    
    cin >> opcion;
    
    switch (opcion) {
        case 'a':
            // + SUMA tiempo con tiempo miembro
            t3 = t1 + t2;
            t1.muestra();
            cout << endl;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            cout << "*****\n";
            t6 = t4 + t5;
            t4.muestra();
            cout << endl;
            t5.muestra();
            cout << endl;
            t6.muestra();
            cout << endl;
            
            
            break;
            
        case 'b':
            // + SUMA tiempo con minutos miembro
            t3 = t2 + 10;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            cout << "*****\n";
            t3 = t2 + 190;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            
            break;
            
        case 'c':
            // + SUMA minutos con tiempo friend
            t3 = 45 + t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            cout << "****\n";
            t3 = 90 + t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            break;
            
        case 'd':
            // ++ Incrementa 1 minuto   miembro
            t3 = ++t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            cout << "****\n";
            t3 = ++t7;
            t7.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            break;
            
        case 'e':
            // -- Decrementa 1 minuto   friend
            t3 = --t2;
            t2.muestra();
            cout << endl;
            t3.muestra();
            cout << endl;
            cout << "****\n";
            t3 = --t8;
            t3.muestra();
            cout << endl;
            t8.muestra();
            cout << endl;
            break;
            
        case 'f':
            // += SUMA tiempo con tiempo  friend
            t2 += t4;
            t2.muestra();
            cout << endl;
            t4.muestra();
            cout << endl;
            cout << "****\n";
            t7 += t5;
            t5.muestra();
            cout << endl;
            t7.muestra();
            cout << endl;
            break;
            
        case 'g':
            // > Regresa true si el primer tiempo es mayor que el segundo  miembro
            if (t1 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;
            
            if (t4 > t2)
                cout << "mayor" << endl;
            else
                cout << "no mayor" << endl;
            break;
    }
    return 0;
}
