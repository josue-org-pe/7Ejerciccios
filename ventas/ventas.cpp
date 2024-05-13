#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct VentaDiaria {
    string fecha;
    double monto;
};

int main() {
    ifstream inputFile("ventas_diarias.txt");       // Archivo de entrada con las ventas diarias
    ofstream outputFile("resumen_ventas.txt");      // Archivo de salida con el resumen de ventas

    if (!inputFile) {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error al abrir el archivo de salida." << endl;
        return 1;
    }

    vector<VentaDiaria> ventas;
    double ventaTotal = 0;
    double montoMayorVenta = numeric_limits<double>::lowest();
    double montoMenorVenta = numeric_limits<double>::max();
    string fechaMayorVenta;
    string fechaMenorVenta;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        VentaDiaria venta;
        if (iss >> venta.fecha >> venta.monto) {
            ventas.push_back(venta);
            ventaTotal += venta.monto;
            if (venta.monto > montoMayorVenta) {
                montoMayorVenta = venta.monto;
                fechaMayorVenta = venta.fecha;
            }
            if (venta.monto < montoMenorVenta) {
                montoMenorVenta = venta.monto;
                fechaMenorVenta = venta.fecha;
            }
        } else {
            cerr << "Error: línea no válida en el archivo de entrada." << endl;
        }
    }

    inputFile.close();

    double promedioVentas = ventaTotal / ventas.size();

    outputFile << "Venta total: $" << ventaTotal << endl;
    outputFile << "Promedio de ventas: $" << promedioVentas << endl;
    outputFile << "Día de mayor venta: " << fechaMayorVenta << ", $" << montoMayorVenta << endl;
    outputFile << "Día de menor venta: " << fechaMenorVenta << ", $" << montoMenorVenta << endl;

    outputFile.close();

    cout << "Se ha completado el procesamiento del resumen de ventas." << endl;

    return 0;
}
