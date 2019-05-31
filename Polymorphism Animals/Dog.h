#ifndef Dog_h
#define Dog_h

#include <Animal.h>

class Dog : public Animal {
  public:
    Dog(string, int);
    void talk();
    void show();
};

Dog::Dog(string sName, int iYear):Animal(sName, iYear){}

void Dog::talk(){
  cout << "\nGUAU!";
}

void Dog::show(){
  cout << " Soy el perro " << sName << " y tengo " << Animal::calculaEdad() << " años";
}

#endif