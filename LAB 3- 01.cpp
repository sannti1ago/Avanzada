/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: 12
Fecha: 2026/08/06
Taller: 03 - Ejercicio 1
*/

#include <iostream>
#include <string>

using namespace std;

struct Venta {
    int idEmpleado;
    string producto;
    int cantidad;
    float valorUnitario;
};

int main() {
    const int NUM_VENTAS = 10;
    Venta ventas[NUM_VENTAS];
    Venta* ptr = ventas; 

    
    cout << "--- INGRESO DE VENTAS ---" << endl;
    for (int i = 0; i < NUM_VENTAS; ++i) {
        cout << "\nVenta #" << (i + 1) << ":" << endl;
        cout << "ID de Empleado: ";
        cin >> (ptr + i)->idEmpleado;
        
        cout << "Producto: ";
        cin.ignore();
        getline(cin, (ptr + i)->producto);
        
        cout << "Cantidad: ";
        cin >> (ptr + i)->cantidad;
        
        cout << "Valor Unitario: ";
        cin >> (ptr + i)->valorUnitario;
    }

    int opcion;
    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Mostrar todas las ventas" << endl;
        cout << "2. Total vendido por cada empleado" << endl;
        cout << "3. Empleado que mas vendio" << endl;
        cout << "4. Buscar ventas por ID de empleado" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cout << "========================\n" << endl;

        switch (opcion) {
            case 1: {
                cout << "--- TODAS LAS VENTAS ---" << endl;
                for (int i = 0; i < NUM_VENTAS; ++i) {
                    cout << "Venta " << (i + 1) 
                         << " | ID: " << (ptr + i)->idEmpleado
                         << " | Producto: " << (ptr + i)->producto
                         << " | Cantidad: " << (ptr + i)->cantidad
                         << " | V. Unitario: $" << (ptr + i)->valorUnitario << endl;
                }
                break;
            }
            case 2: {
                cout << "--- TOTAL VENDIDO POR EMPLEADO ---" << endl;
                int ids[NUM_VENTAS];
                float totales[NUM_VENTAS] = {0};
                int* ptrIds = ids;
                float* ptrTotales = totales;
                int empleadosUnicos = 0;

                for (int i = 0; i < NUM_VENTAS; ++i) {
                    int idActual = (ptr + i)->idEmpleado;
                    float montoVenta = ((ptr + i)->cantidad) * ((ptr + i)->valorUnitario);
                    bool registrado = false;

                    for (int j = 0; j < empleadosUnicos; ++j) {
                        if (*(ptrIds + j) == idActual) {
                            *(ptrTotales + j) += montoVenta;
                            registrado = true;
                            break;
                        }
                    }

                    if (!registrado) {
                        *(ptrIds + empleadosUnicos) = idActual;
                        *(ptrTotales + empleadosUnicos) = montoVenta;
                        empleadosUnicos++;
                    }
                }

                for (int j = 0; j < empleadosUnicos; ++j) {
                    cout << "Empleado ID: " << *(ptrIds + j) 
                         << " | Total Vendido: $" << *(ptrTotales + j) << endl;
                }
                break;
            }
            case 3: {
                
                int ids[NUM_VENTAS];
                float totales[NUM_VENTAS] = {0};
                int* ptrIds = ids;
                float* ptrTotales = totales;
                int empleadosUnicos = 0;

                for (int i = 0; i < NUM_VENTAS; ++i) {
                    int idActual = (ptr + i)->idEmpleado;
                    float montoVenta = ((ptr + i)->cantidad) * ((ptr + i)->valorUnitario);
                    bool registrado = false;

                    for (int j = 0; j < empleadosUnicos; ++j) {
                        if (*(ptrIds + j) == idActual) {
                            *(ptrTotales + j) += montoVenta;
                            registrado = true;
                            break;
                        }
                    }
                    if (!registrado) {
                        *(ptrIds + empleadosUnicos) = idActual;
                        *(ptrTotales + empleadosUnicos) = montoVenta;
                        empleadosUnicos++;
                    }
                }

                float maxVendido = -1.0;
                int idMax = -1;

                for (int j = 0; j < empleadosUnicos; ++j) {
                    if (*(ptrTotales + j) > maxVendido) {
                        maxVendido = *(ptrTotales + j);
                        idMax = *(ptrIds + j);
                    }
                }

                if (idMax != -1) {
                    cout << "--- MEJOR EMPLEADO ---" << endl;
                    cout << "El empleado que mas vendio es el ID: " << idMax 
                         << " con un total de $" << maxVendido << endl;
                }
                break;
            }
            case 4: {
                int idBuscado;
                cout << "Ingrese el ID del empleado a buscar: ";
                cin >> idBuscado;
                
                cout << "--- VENTAS DEL EMPLEADO " << idBuscado << " ---" << endl;
                bool tieneVentas = false;
                
                for (int i = 0; i < NUM_VENTAS; ++i) {
                    if ((ptr + i)->idEmpleado == idBuscado) {
                        cout << "Producto: " << (ptr + i)->producto
                             << " | Cantidad: " << (ptr + i)->cantidad
                             << " | V. Unitario: $" << (ptr + i)->valorUnitario
                             << " | Subtotal: $" << ((ptr + i)->cantidad * (ptr + i)->valorUnitario) << endl;
                        tieneVentas = true;
                    }
                }
                
                if (!tieneVentas) {
                    cout << "No se encontraron ventas registradas para este empleado." << endl;
                }
                break;
            }
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}