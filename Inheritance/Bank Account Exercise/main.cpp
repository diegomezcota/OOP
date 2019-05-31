#include <iostream>
using namespace std;

#include "SPEI.h"

int main ()
{
	SPEI ch;
	CtaBanc cb;
	int numCta;
	double saldo, com;
	
	cout << "Teclea el numero de cuenta de la cuenta bancaria ";
	cin >> numCta;
	
	cb.setNumCuenta(numCta);
	
	cout << "Teclea el saldo inicial para el cliente de la cuenta bancaria ";
	cin >> saldo;
	
	cb.setSaldo(saldo);
	
	cout << "Teclea el numero de cuenta de la chequera ";
	cin >> numCta;
	
	ch.setNumCuenta(numCta);
	
	cout << "Teclea el saldo inicial para el cliente de la chequera ";
	cin >> saldo;
	
	ch.setSaldo(saldo);
	
	cout << "Teclea  la comision por retiro de la chequera ";
	cin >> com;
	
	ch.setFee(com);
	
	cout << "Los datos de la cuenta bancaria son " << endl;
	cb.show();
	
	cout << "Los datos de la cuenta de cheques son " << endl;
	ch.show();
	
	cb.retire(1000);
	ch.retire(1000);
	
	cout << "despues de retirar datos de cuenta bancaria " << endl;
	cb.show();
	
	cout << "despues de retirar datos de chequera " << endl;
	ch.show();
	
  return 0;
}
