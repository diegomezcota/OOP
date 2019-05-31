#ifndef Animal_h
#define Animal_h

#include <string>

class	Animal
{
public:
				Animal(string,	int);
				int	calculaEdad();
				virtual	void	talk()	=	0;			//Nota	que	son	funciones	virtual	pura.
				virtual	void	show()	=	0;			//	ENTONCES	la	clase	es	abstracta.
protected:
				string	sName;
				int	iAnioNacim;
};
Animal::Animal(string	sNom,	int	iANac)
{
				sName	=	sNom;
				iAnioNacim	=	iANac;
}
int	Animal::calculaEdad()
{
				return	2019 - iAnioNacim;
}

#endif