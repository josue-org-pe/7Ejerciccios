#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main() 
{
    
    ifstream inputFile("datos_personales.txt");  // Archivo de entrada
    ofstream outputFile("emails_filtrados.txt"); // Archivo de salida

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string nombre, email;
        int edad;
        char delim; 
        getline(iss, nombre, ',');
        iss >> edad >> delim;
        getline(iss, email);
        if (edad > 18) {
            outputFile << email << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Ok revisar: 'emails_filtrados.txt'." << endl;

    return 0;
}