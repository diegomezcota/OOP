#include <string>
using namespace std;

#ifndef CuentaBanc_h
#define CuentaBanc_h

class CuentaBanc {
    
public:
    CuentaBanc();
    CuentaBanc(string nom, double sal);
    void setNombre(string nom);
    void setSaldo(double sal);
    string getNombre();
    double getSaldo();
    bool retira(double cant);
    void deposita(double cant);
    
private:
    string nombre;
    double saldo;
    
};

CuentaBanc::CuentaBanc() {
    nombre="";
    saldo=0;
}

CuentaBanc::CuentaBanc(string nom, double sal) {
    nombre = nom;
    saldo = sal;
}

void CuentaBanc::setNombre(string nom) {
    nombre = nom;
}

void CuentaBanc::setSaldo(double sal) {
    saldo = sal;
}

string CuentaBanc::getNombre() {
    return nombre;
}

double CuentaBanc::getSaldo() {
    return saldo;
}

bool CuentaBanc::retira(double cant) {
    if (saldo >= cant) {
        saldo -= cant;
        return true;
    } else {
        return false;
    }
}

void CuentaBanc::deposita(double cant) {
    saldo += cant;
}


#endif /* CuentaBanc_h */
