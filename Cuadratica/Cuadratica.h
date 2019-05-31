#ifndef Cuadratica_h
#define Cuadratica_h

class Cuadratica
{
  
public:
 Cuadratica();
 Cuadratica(int, int, int);
 void muestra();
 Cuadratica operator+(Cuadratica);
 Cuadratica operator*(int);
 bool operator==(Cuadratica);
 friend Cuadratica operator-(Cuadratica, Cuadratica);
 friend Cuadratica operator+=(Cuadratica &c1, Cuadratica c2);
 friend Cuadratica operator++(Cuadratica &c1);
private:
 int iCoefA, iCoefB, iCoefC;

};

Cuadratica::Cuadratica()
{
 iCoefA = 1;
 iCoefB = 1;
 iCoefC = 1;
}

Cuadratica::Cuadratica(int iA, int iB, int iC)
{
 iCoefA = iA;
 iCoefB = iB;
 iCoefC = iC;
}

void Cuadratica::muestra()
{
 if (iCoefA != 0)
 {
 cout << iCoefA;
 cout << "x^2 ";
 }

 if (iCoefB != 0)
 {
 if (iCoefB > 0)
 cout << " + ";
 cout << iCoefB;
 cout << "x ";
 }

 if (iCoefC != 0)
 {
 if (iCoefC > 0)
 cout << " + ";
 cout << iCoefC << endl;
 }
}

Cuadratica Cuadratica::operator+(Cuadratica cuad){
  Cuadratica cReturned;
  cReturned.iCoefA = this->iCoefA + cuad.iCoefA;
  cReturned.iCoefB = this->iCoefB + cuad.iCoefB;
  cReturned.iCoefC = this->iCoefC + cuad.iCoefC;
  return cReturned;
}

Cuadratica Cuadratica::operator*(int num){
  Cuadratica cReturned;
  cReturned.iCoefA = this->iCoefA * num;
  cReturned.iCoefB = this->iCoefB * num;
  cReturned.iCoefC = this->iCoefC * num;
  return cReturned;
}

bool Cuadratica::operator==(Cuadratica c){
  return
  (this->iCoefA == c.iCoefA && 
   this->iCoefB == c.iCoefB && 
   this->iCoefC == c.iCoefC
  );
}

#endif