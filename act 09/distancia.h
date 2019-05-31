#ifndef distancia_h
#define distancia_h

class distancia(){
  public:
  distancia();
  distancia(int ft, int inch);
  ~distancia();
  int getFeet();
  int getInches();
  void setFeet(int ft);
  void setInches(int inch);
  double convierteAMts();
  distancia sumaDistancia(distancia dist);
  distancia restaDistancia(distancia dist);
  private:
  int feet, inches;
  double metros;
  void conviertePulgadas(int inch);
};


void distancia::conviertePulgadas(int inch){
  int pulgEnPies = inch / 12;
  int restoPulg = inch % 12;

}


/* distancia distancia::conviertePulgadas(int ft, int inch){

}
*/

distancia::distancia(){
  feet = 0;
  inches = 0;
  metros = 0;
}

distancia::distancia(int ft, int inch){
  distancia d = conviertePulgadas(ft, inch);
  feet = d.getFeet();
  inches = d.getInches();
}

distancia::~distancia(){

}

distancia::getFeet(){
  return feet;
}

distancia::getInches(){
  return inches;
}

distancia::setFeet(int ft){
  feet = ft;
}

distancia::setInches(int inch){
  distancia d = conviertePulgadas(pies, inch);
  pies += d.getFeet();
  inches = d.getInches();
}

distancia::convierteAMts(){

}

distancia::sumaDistancia(distancia dist){
  int ft;
  int inch;
  ft = feet + dist.getFeet();
  inch = inches + dist.getInches();
  distancia distNew(ft, inch);
  return distNew;
}

distancia::restaDistancia(distancia dist){
  int ft;
  int inch;
  ft = feet - dist.getFeet();
  inch = inches - dist.getInches();
}

double distancia::convierteAMts() {
  double metros;
  metros = (feet * 12 + inches) * 2.54 / 100;
  return metros;
}

#endif