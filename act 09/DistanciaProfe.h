#ifndef Distancia_h
#define Distancia_h

class Distancia {
public:
    Distancia();
    Distancia(int pi, int pu);
    void setPies(int pi);
    void setPulgadas(int pu);
    int getPies();
    int getPulgadas();
    double convierteAMts();
    Distancia sumaDistancia(Distancia d);
    Distancia restaDistancia(Distancia d);
private:
    int pies;
    int pulgadas;
    void conviertePulgadas();
};

Distancia::Distancia() {
    pies = 0;
    pulgadas = 0;
}

Distancia::Distancia(int pi, int pu) {
    pies = pi;
    pulgadas = pu;
    // ya que recibimos los parámetros de pies y pulgados del constructor, mandamos llamar el método privado de conviertePulgadas, para ajustar los atributos para que las pulgadas se convierta en pies y pulgadas
    conviertePulgadas();
}

// Método privado para convertir las pulgadas a pies y pulgadas, por si recibimos de parámetro o si la suma o resta me da valores de pulgadas que puedan convertirse a pies
// En clase quisimos hacer este método de tipo Distancia, gracias al apoyo de Pato nos dimos cuenta que no era necesario, dado que es un método privado que tiene acceso a los atributos del objeto, por eso vemos como el código hace uso de esos atributos.

void Distancia::conviertePulgadas() {
    if (pulgadas >= 12) {
        int pulgadasEnPies = pulgadas / 12;
        pies = pies + pulgadasEnPies;
        pulgadas = pulgadas%12;
    } else {
        // hacemos un ciclo para ir descontanto los pies de 12 en 12 pulgadas, hasta que llegas a que las pulgadas sean mayores o iguales a 0
        while (pulgadas < 0) {
            pies = pies - 1;
            pulgadas = pulgadas + 12;
        }
    }
    
}

int Distancia::getPies() {
    return pies;
}

int Distancia::getPulgadas() {
    return pulgadas;
}

void Distancia::setPies(int pi) {
    pies = pi;
}

void Distancia::setPulgadas(int pu) {
    pulgadas = pu;
    conviertePulgadas();
}

Distancia Distancia::sumaDistancia(Distancia d) {
    Distancia nd(d.getPies()+pies,d.getPulgadas()+pulgadas);
    return nd;
}

Distancia Distancia::restaDistancia(Distancia d) {
    Distancia nd(pies - d.getPies(),pulgadas - d.getPulgadas());
    return nd;
}

double Distancia::convierteAMts() {
    double metros;
    metros = (pies * 12 + pulgadas) * 2.54 / 100;
    return metros;
}

#endif /* Distancia_h */