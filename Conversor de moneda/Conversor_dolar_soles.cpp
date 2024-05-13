#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("precios_dolares.txt");  // Archivo de entrada con precios en dólares
    ofstream outputFile("precios_soles.txt");   // Archivo de salida con precios convertidos a soles

    double tasaConversion = 3.85;  // Tasa de conversión de dólares a soles

    if (!inputFile) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        double precioDolar;
        if (iss >> precioDolar) {
            double precioSoles = precioDolar * tasaConversion;
            outputFile << fixed << setprecision(2) << precioSoles << endl;
        } else {
            cerr << "Error: linea no valida en el archivo de entrada." << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Se ha completado la conversion de precios de dolares a soles." << endl;

    return 0;
}
