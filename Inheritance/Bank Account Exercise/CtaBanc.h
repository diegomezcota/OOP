#ifndef CtaBanc_h
#define CtaBanc_h

class CtaBanc 
{
public:
	CtaBanc();
	CtaBanc(int n, double s);
	int getNumCuenta() {return numCuenta;};
	void setNumCuenta(int n) {numCuenta = n;};
	void setSaldo(double s) { dBalance = s; };
	double getSaldo(){return dBalance;};
	void deposita(double cant);
	bool retire(double cant);  // se debe redefinir en la clase Cheques
	void show();		   // se debe redefinir en la clase Cheques
protected:
	int numCuenta;
	double dBalance;
};

CtaBanc::CtaBanc()
{	numCuenta = 0;
	dBalance = 0;
}

CtaBanc::CtaBanc(int n, double s)
{	numCuenta = n;
	dBalance = s;
}

void CtaBanc::deposita(double cant)
{	dBalance += cant;
}

// si hay suficiente saldo resta cant del saldo de la cuenta y manda true, si no hay suficiente saldo, solo manda false
bool CtaBanc::retire(double cant)
{	if (dBalance >= cant)
{	dBalance -= cant;
	return true;
}
else
	return false;
}

void CtaBanc::show()
{	cout<<endl;
	cout<<"Your account "<<numCuenta<< " balance is: "<<dBalance<<endl;
}

#endif