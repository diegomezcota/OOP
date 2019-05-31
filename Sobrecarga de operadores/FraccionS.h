//
//  Fraccion.h
//  CascaronFraccion
//


#ifndef CascaronFraccion_Fraccion_h
#define CascaronFraccion_Fraccion_h

class Fraccion
{
	friend double operator !(Fraccion f);
public:
	// Constructores
	Fraccion();
	Fraccion(int n, int d);
	// metodos de acceso
	int getNum();
	int getDen();
	// metodos de modificacion
	void setNum(int n);
	void setDen(int d);
	// metodos
	Fraccion operator + (Fraccion f);
  Fraccion operator * (Fraccion);
  Fraccion operator ++ ();
  Fraccion operator -- ();
  Fraccion operator - (Fraccion);
  bool operator > (Fraccion f);
	void muestra();
	
private:
	int num, den;
};

Fraccion::Fraccion()
{
    num = 1;
    den = 2;
}

Fraccion::Fraccion(int n, int d)
{
    num = n;
    den = d;
}

int Fraccion::getNum()
{
    return num;
}

int Fraccion::getDen()
{
    return den;
}

void Fraccion::setNum(int n)
{
    num = n;
}

void Fraccion::setDen(int d)
{
    den = d;
}

void Fraccion::muestra()
{
	cout << num << "/" << den;
}

double operator !(Fraccion f)
{
    return  (double)f.num/f.den;
}

Fraccion Fraccion:: operator + (Fraccion f)
{   Fraccion res;
    res.num = this->num * f.den + this->den * f.num;
    res.den = this->den * f.den;
    return res;
}

Fraccion Fraccion::operator*(Fraccion f){
  Fraccion res;
  res.num = this->num * f.num;
  res.den = this->den * f.den;
  return res;
}

Fraccion Fraccion::operator++(){
  Fraccion res;
  res.num = this->num + this->den;
  res.den = this->den;
  return res;
}

Fraccion Fraccion::operator--(){
  Fraccion res;
  res.num = this->num * -1;
  res.den = this->den;
  return res;
}

 Fraccion Fraccion::operator-(Fraccion f){
  Fraccion res;
  f = --f;
  //Fraccion res1;
  //res1.num = this->num;
  //res1.den = this->den;
  res = *this + f;
  return res;
}

bool Fraccion::operator>(Fraccion f){
  return (!*this > !f);
}

#endif
