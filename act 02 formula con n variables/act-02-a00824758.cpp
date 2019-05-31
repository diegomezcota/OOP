#include <iostream>
#include <math.h>
using namespace std;

int main(){
int x, n;
double suma = 0, producto;

while (x>0) {
    double suma = 0, producto = 0;
    cout << "Ingrese el valor de la variable (teclee un numero menor a 1 para salir): ";
    cin >> x;
    if (x>0){

cout << "Ingrese la cantidad de coeficientes: ";
cin >> n;

int arr[n];

//Llenar las n posiciones del arreglo

for (int i = 0; i < n; i++){
    cout << i+1 << ".- Ingrese el coeficiente: ";
    cin >> arr[i];
}

// Si el tama�o del arreglo es mayor a 1 ser� diferente a que si s�lo es 1

if (x>1){
    suma += arr[0];
    cout << arr[0];
    for (int i = 1; i < n; i++){
        cout <<  " + " << arr[i] << "(" << x << ")" << i;
        suma += arr[i]*pow(x, i);
    }
    cout << " = " << suma << endl;
} else {
    cout << arr[0] << " = " << arr[0] << endl;
}

    }
}

return 0;
}