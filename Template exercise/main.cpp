#include <iostream>
using namespace std;
#include "funciones.h"

int main(int argc, const char * argv[]) {
    char iMat [10][10];
    int r, c, ren, col;
    char arr[10];
    int tamArr;
    
    cout << "De que tamaño quieres la matriz:" << endl;
    cout << "Cantidad de renglones:" << endl;
    cin >> r;
    cout << "Cantidad de columnas:" << endl;
    cin >> c;
    LlenaMatriz(iMat, r, c);
    cout << "Qué renglón quieres para crear el arreglo?" << endl;
    cin >> ren;
    cout << endl;
    MatrizArregloRenglon(iMat, r, c, ren, arr, tamArr);
    MuestraArreglo(arr, tamArr);
    
    cout << "Qué columna quieres para crear el arreglo?" << endl;
    cin >> col;
    cout << endl;
    MatrizArregloColumna(iMat, r, c, col, arr, tamArr);
    MuestraArreglo(arr, tamArr);
    
    return 0;
}