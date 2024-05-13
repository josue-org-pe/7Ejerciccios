#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct RegistroTemperatura {
    string fecha;
    double temperatura;
};

int main() {
    ifstream inputFile("registro_temperaturas.txt");   // Archivo de entrada con registro de temperaturas
    ofstream outputFile("temperaturas_extremas.txt");  // Archivo de salida con temperaturas extremas

    if (!inputFile) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    vector<RegistroTemperatura> registros;
    double temperaturaMinima = numeric_limits<double>::max();
    double temperaturaMaxima = numeric_limits<double>::lowest();

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        RegistroTemperatura registro;
        if (iss >> registro.fecha >> registro.temperatura) {
            registros.push_back(registro);
            if (registro.temperatura < temperaturaMinima) {
                temperaturaMinima = registro.temperatura;
            }
            if (registro.temperatura > temperaturaMaxima) {
                temperaturaMaxima = registro.temperatura;
            }
        } else {
            cerr << "Error: línea no válida en el archivo de entrada." << endl;
        }
    }

    inputFile.close();

    outputFile << "Temperatura mínima: " << temperaturaMinima << endl;
    outputFile << "Temperatura máxima: " << temperaturaMaxima << endl;
    outputFile << "Días con temperaturas extremas:" << endl;
    for (const RegistroTemperatura& registro : registros) {
        if (registro.temperatura == temperaturaMinima || registro.temperatura == temperaturaMaxima) {
            outputFile << registro.fecha << ", " << registro.temperatura << endl;
        }
    }

    outputFile.close();

    cout << "Se ha completado el procesamiento de temperaturas extremas." << endl;

    return 0;
}
