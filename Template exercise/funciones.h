#ifndef funciones_h
#define funciones_h

template <class T>
void MatrizArregloRenglon(T mat[10][10], int r, int c, int ren, T arr[10], int &tamArr) {
    if (ren >= 0 && ren <= r) {
        tamArr = c;
        for (int i = 0; i < c; i++) {
            arr[i] = mat[ren][i];
        }
    }
}

template <class T>
void MatrizArregloColumna(T mat[10][10], int r, int c, int col, T arr[10], int &tamArr) {
    if (col >= 0 && col <= c) {
        tamArr = r;
        for (int i = 0; i < r; i++) {
            arr[i] = mat[i][col];
        }
    }
}

template <class T>
void LlenaMatriz(T mat[10][10], int r, int c) {
    cout << "Llena los datos de la matriz" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Renglón: " << i << " Columna: " << j << endl;
            cin >> mat[i][j];
            cout << endl;
        }
    }
}

template <class T>
void MuestraArreglo(T arr[10], int n) {
    for (int i = 0; i < n; i++) {
        cout << "posición del arreglo: " << i << " Valor: " << arr[i] << endl;
    }
}
#endif /* funciones_h */