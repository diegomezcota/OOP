#include <iostream>
#include <string>
#include <Reloj.h>
#include <evento.h>

using namespace std;

int main() {

  char cOpcion = 's';
  int hr, min, dur, cont = 0;
  Reloj hora(0,0);
  string asunto;
  evento ev;

  evento arrEvento[20];

  while (cOpcion == 's' && cont < 20) {
  cout << "Quieres agregar un evento? (s/n): ";
  cin >> cOpcion;

  if (cOpcion == 's'){
    cout << "A que hora inicia el evento (hh mm): ";
    cin >> hr >> min;
    hora.setHora(hr);
    hora.setMinu(min);
    cout << "Cuanto dura el evento (hrs)? ";
    cin >> dur;
    cout << "De que se trata el evento? \n";
    cin.ignore();
    getline(cin, asunto);
    ev.setHoraInicial(hora);
    ev.setDuracion(dur);
    ev.setAsunto(asunto);
    arrEvento[cont] = ev;
    cont++;
  } else {
    cout << "Gracias\n\n";
  }
  } 

  for (int i = 0; i < cont; i++) {
    cout << "Evento: " << arrEvento[i].getAsunto();
    arrEvento[i].getHoraInicial().muestraHora();
    cout << "\nDuracion: " << arrEvento[i].getDuracion() << " horas.";
    if (i != cont-1){
      cout << "\n\n";
    }
  }

  return 0;
}