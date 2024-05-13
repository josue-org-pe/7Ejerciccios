#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Estudiante {
    string nombre;
    vector<double> notas;
    double promedio;
};

int main() {
    ifstream inputFile("notas_estudiantes.txt");    // Archivo de entrada
    ofstream outputFile("promedios_estudiantes.txt");  // Archivo de salida

    string line;
    vector<Estudiante> estudiantes;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        Estudiante estudiante;
        getline(iss, estudiante.nombre, ',');
        double nota;
        while (iss >> nota) {
            estudiante.notas.push_back(nota);
            char delim;
            if (iss >> delim && delim == ',') continue;
            else break;
        }

        // Calcular promedio
        double suma = 0;
        for (double nota : estudiante.notas) {
            suma += nota;
        }
        estudiante.promedio = suma / estudiante.notas.size();

        estudiantes.push_back(estudiante);
    }

    // Escribir los resultados en el archivo de salida
    for (const Estudiante& estudiante : estudiantes) {
        outputFile << estudiante.nombre << ", " << estudiante.promedio << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Ok, revisa 'promedios_estudiantes.txt' para ver los resultados." << endl;

    return 0;
}
