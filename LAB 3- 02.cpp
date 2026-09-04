/*
Integrantes Maria Fernanda Castañeda, Santiago Gaitan
Grupo: 12
Fecha: 2026/08/06
Taller: 03 - Ejercicio 2
*/
#include <iostream>
#include <limits>

using namespace std;

struct Materia {
    char nombreMateria[50]; 
    float nota;
};

struct Estudiante {
    int id;
    char nombre[50]; 
    Materia materias[3]; 
};

int main() {
    const int NUM_ESTUDIANTES = 5;
    const int NUM_MATERIAS = 3;
    
    
    Estudiante estudiantes[NUM_ESTUDIANTES];
    
 
    Estudiante* ptrEst = estudiantes; 

    cout << "========== REGISTRO ACADEMICO ==========\n" << endl;

    
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        cout << "--- Ingresando datos del Estudiante #" << (i + 1) << " ---" << endl;
        cout << "ID: ";
        cin >> (ptrEst + i)->id;
        
        cout << "Nombre: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cin.getline((ptrEst + i)->nombre, 50);

       
        Materia* ptrMat = (ptrEst + i)->materias; 
        
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            cout << "  Nombre de la Materia " << (j + 1) << ": ";
            cin.getline((ptrMat + j)->nombreMateria, 50);
            
            cout << "  Nota de " << (ptrMat + j)->nombreMateria << ": ";
            cin >> (ptrMat + j)->nota;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        cout << endl;
    }


    float sumaGeneralCurso = 0.0;
    float maxPromedio = -1.0;
    Estudiante* ptrMejorEst = nullptr; 

    cout << "========== RESULTADOS ==========\n" << endl;

   
    cout << "1. PROMEDIOS INDIVIDUALES:" << endl;
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        float sumaNotas = 0.0;
        
        
        Materia* ptrMat = (ptrEst + i)->materias;
        
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            sumaNotas += (ptrMat + j)->nota; 
        }
        
        float promedioEstudiante = sumaNotas / NUM_MATERIAS;
        sumaGeneralCurso += promedioEstudiante; 
        
        cout << "   - " << (ptrEst + i)->nombre << " (ID: " << (ptrEst + i)->id 
             << ") | Promedio: " << promedioEstudiante << endl;

      
        if (promedioEstudiante > maxPromedio) {
            maxPromedio = promedioEstudiante;
            ptrMejorEst = (ptrEst + i); 
        }
    }

  
    float promedioGeneral = sumaGeneralCurso / NUM_ESTUDIANTES;
    cout << "\n2. PROMEDIO GENERAL DEL CURSO:" << endl;
    cout << "   - El promedio de todos los " << NUM_ESTUDIANTES << " estudiantes es: " << promedioGeneral << endl;
    cout << "\n3. ESTUDIANTE CON EL MAYOR PROMEDIO:" << endl;
    if (ptrMejorEst != nullptr) {
        cout << "   - Nombre: " << ptrMejorEst->nombre << endl;
        cout << "   - Promedio: " << maxPromedio << endl;
        cout << "   - Notas desglosadas:" << endl;
        
        // Apuntador para recorrer las materias del MEJOR estudiante (Restricción de mostrar las notas usando solo aritmética de apuntadores)
        Materia* ptrMatMejor = ptrMejorEst->materias;
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            cout << "       * " << (ptrMatMejor + j)->nombreMateria 
                 << ": " << (ptrMatMejor + j)->nota << endl;
        }
    }

    return 0;
}
 