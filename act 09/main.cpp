#include <iostream>

using namespace std;

#include <distancia.h>

int main() {
  distancia a;
  distancia b(5, 11);
  distancia c(0, 4);

  distancia d = b.sumaDistancia(c);

  cout << d.getFeet();
}