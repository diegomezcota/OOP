#ifndef empleado_h
#define empleado_h

class empleado {
  public:
  empleado();
  //empleado(int idEmpleado, double dSueldoFijo, double dSueldoPorHora,int iHorasTrabajadas);
  int getID();
  double getSueldoFijo();
  double getSueldoPorHora();
  int getHorasTrabajadas();
  void setID(int idEmpleado);
  void setSueldoFijo(double dSueldoFijo);
  void setSueldoPorHora(double dSueldoPorHora);
  void setHorasTrabajadas(int iHorasTrabajadas);
  void registrarHoras(int iHorasNuevas);
  double calcularPago();
  private:
  int id, horasTrabajadas;
  double sueldoFijo, sueldoPorHora;
};

empleado::empleado(){
  id = -1;
  horasTrabajadas = -1;
  sueldoFijo = -1;
  sueldoPorHora = -1;
}

/*
empleado::empleado(int idEmpleado, double dSueldoFijo, double dSueldoPorHora, int iHorasTrabajadas){
  id = idEmpleado;
  sueldoFijo = dSueldoFijo;
  sueldoPorHora = dSueldoPorHora;
  horasTrabajadas = iHorasTrabajadas;
}
*/

int empleado::getID(){
  return id;
}

 double empleado::getSueldoFijo(){
   return sueldoFijo;
 }

 double empleado::getSueldoPorHora(){
   return sueldoPorHora;
 }

 int empleado::getHorasTrabajadas(){
   return horasTrabajadas;
 }

 void empleado::setID(int idEmpleado){
   id = idEmpleado;
 }

void empleado::setSueldoFijo(double dSueldoFijo){
   sueldoFijo = dSueldoFijo;
}

void empleado::setSueldoPorHora(double dSueldoPorHora){
  sueldoPorHora = dSueldoPorHora;
}

void empleado::setHorasTrabajadas(int iHorasTrabajadas){
  horasTrabajadas = iHorasTrabajadas;
}

void empleado::registrarHoras(int iHorasNuevas){
  horasTrabajadas += iHorasNuevas;
}

double empleado::calcularPago(){
  return (sueldoFijo + horasTrabajadas*sueldoPorHora);
}

#endif