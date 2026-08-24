/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: ???
Fecha: 2026/08/06
Taller: 01 - Ejercicio 1
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_EQUIPOS = 50;

// Estructura que representa un equipo del inventario
struct Equipo {
    string codigo;
    char tipo;               // 'L' Laptop, 'D' Desktop, 'S' Servidor
    int costoInicial;
    float depreciacionMensual; // tasa mensual segun el tipo (en %)
    int mesesUso;
    float valorActual;         // se calcula luego de leer los datos
};

// Devuelve la tasa de depreciacion mensual (%) segun el tipo de equipo
float obtenerTasaDepreciacion(char tipo) {
    switch (tipo) {
        case 'L': return 2.5f;
        case 'D': return 1.5f;
        case 'S': return 0.5f;
        default:  return 0.0f; // tipo no valido -> no deprecia
    }
}

// Calcula el valor actual del equipo, sin permitir valores negativos
float calcularValorActual(const Equipo& e) {
    // Se usa casting explicito para asegurar division/operacion en float
    float porcentajeDepreciado = e.depreciacionMensual * static_cast<float>(e.mesesUso);
    float valor = static_cast<float>(e.costoInicial) * (1.0f - porcentajeDepreciado / 100.0f);

    if (valor < 0.0f) {
        valor = 0.0f;
    }
    return valor;
}

int main() {
    Equipo equipos[MAX_EQUIPOS];
    int n;

    cout << "===== REGISTRO DE INVENTARIO =====" << endl;
    cout << "Ingrese el numero de equipos a registrar (max " << MAX_EQUIPOS << "): ";
    cin >> n;

    // Validacion basica del limite de equipos
    while (n <= 0 || n > MAX_EQUIPOS) {
        cout << "Cantidad invalida. Ingrese un numero entre 1 y " << MAX_EQUIPOS << ": ";
        cin >> n;
    }

    // ----- Registro de datos -----
    for (int i = 0; i < n; i++) {
        cout << "\n--- Equipo " << (i + 1) << " ---" << endl;

        cout << "Codigo: ";
        cin >> equipos[i].codigo;

        cout << "Tipo (L=Laptop, D=Desktop, S=Servidor): ";
        cin >> equipos[i].tipo;

        cout << "Costo inicial: ";
        cin >> equipos[i].costoInicial;

        cout << "Meses de uso: ";
        cin >> equipos[i].mesesUso;

        // La depreciacion mensual depende del tipo, no se pide por teclado
        equipos[i].depreciacionMensual = obtenerTasaDepreciacion(equipos[i].tipo);

        // Se calcula el valor actual una sola vez y se guarda en la estructura
        equipos[i].valorActual = calcularValorActual(equipos[i]);
    }

    // ----- Mostrar informacion de cada equipo -----
    cout << "\n===== REPORTE DE EQUIPOS =====" << endl;
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << "Codigo: " << equipos[i].codigo
             << ", Tipo: " << equipos[i].tipo
             << ", Costo Inicial: " << equipos[i].costoInicial
             << ", Meses: " << equipos[i].mesesUso
             << ", Valor Actual: " << equipos[i].valorActual << endl;
    }

    // ----- Metricas globales -----
    float valorTotalInventario = 0.0f;
    int indiceMayorValor = 0;

    for (int i = 0; i < n; i++) {
        // Conversion explicita para asegurar la suma en punto flotante
        valorTotalInventario += static_cast<float>(equipos[i].valorActual);

        if (equipos[i].valorActual > equipos[indiceMayorValor].valorActual) {
            indiceMayorValor = i;
        }
    }

    cout << "\n===== METRICAS GLOBALES =====" << endl;
    cout << "Valor total del inventario: " << valorTotalInventario << endl;
    cout << "Equipo con mayor valor actual: " << equipos[indiceMayorValor].codigo
         << " (Valor: " << equipos[indiceMayorValor].valorActual << ")" << endl;

    return 0;
}