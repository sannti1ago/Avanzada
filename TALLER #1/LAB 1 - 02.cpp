/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: ???
Fecha: 2026/08/06
Taller: 01 - Ejercicio 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int FILAS = 4;
const int COLUMNAS = 4;

int main() {
    int matrizOriginal[FILAS][COLUMNAS];
    float matrizNormalizada[FILAS][COLUMNAS];

    // ----- Lectura de la matriz 4x4 -----
    cout << "===== INGRESO DE DATOS =====" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "Valor [" << i << "][" << j << "]: ";
            cin >> matrizOriginal[i][j];
        }
    }

    // ----- Busqueda de minimo y maximo -----
    int minimo = matrizOriginal[0][0];
    int maximo = matrizOriginal[0][0];

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matrizOriginal[i][j] < minimo) {
                minimo = matrizOriginal[i][j];
            }
            if (matrizOriginal[i][j] > maximo) {
                maximo = matrizOriginal[i][j];
            }
        }
    }

    // ----- Normalizacion Min-Max -----
    // matrizNormalizada[i][j] = (original - min) / (max - min)
    int rango = maximo - minimo;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (rango == 0) {
                // Caso limite: todos los valores son iguales -> evitar division entre 0
                matrizNormalizada[i][j] = 0.0f;
            } else {
                // Conversion explicita (casting) para forzar division flotante
                // y no perder los decimales por division entera
                matrizNormalizada[i][j] = static_cast<float>(matrizOriginal[i][j] - minimo) /
                                           static_cast<float>(rango);
            }
        }
    }

    // ----- Salida de resultados -----
    cout << fixed << setprecision(2);

    cout << "\n===== RESULTADOS =====" << endl;
    cout << "Valor minimo encontrado: " << minimo << endl;
    cout << "Valor maximo encontrado: " << maximo << endl;

    cout << "\nMatriz Original (enteros):" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << setw(6) << matrizOriginal[i][j];
        }
        cout << endl;
    }

    cout << "\nMatriz Normalizada (flotante):" << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << setw(8) << matrizNormalizada[i][j];
        }
        cout << endl;
    }

    return 0;
}