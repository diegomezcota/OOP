#include <iostream>

using namespace std;

#include <Dog.h>
#include <Cat.h>
#include <Animal.h>

int main() {
  Animal *aAnimals[3];
  Cat c1("Silvestre", 1947);
  Cat c2("Tom", 1940);
  Dog d1("Bruno", 1800);

  aAnimals[0] = &c1;
  aAnimals[1] = &d1;
  aAnimals[2] = &c2;

  for (int i=0; i < 3; i++){
    aAnimals[i]->talk();
    aAnimals[i]->show();
  }

return 0;

}