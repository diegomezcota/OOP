#ifndef Cat_h
#define Cat_h

#include <Animal.h>

class Cat : public Animal {
  public:
    Cat(string, int);
    void talk();
    void show();
};

Cat::Cat(string sName, int iYear):Animal(sName, iYear){}

void Cat::talk(){
  cout << "\nMIAU! ";
}

void Cat::show(){
  cout << "Soy el gato " << sName << " y tengo " << Animal::calculaEdad() << " años";
}

#endif