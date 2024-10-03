

#ifndef _ADMINISTRADOR_FACTURAS_H_
#define _ADMINISTRADOR_FACTURAS_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Facturas.h"

using namespace std;

class FacturaManager {
private:
    vector<Factura> facturas;
    string csvFilename;

public:
    FacturaManager(const string& filename) : csvFilename(filename) {}

    bool loadFromCSV() {
        ifstream csvFile(csvFilename);
        if (!csvFile.is_open()) {
            cout << "Error: No se pudo abrir el archivo " << csvFilename << endl;
            return false;
        }

        string line;
        int numFacturas = 0;

        // Contar número de facturas
        while (getline(csvFile, line)) {
            numFacturas++;
        }

        // Resetear el archivo
        csvFile.clear();
        csvFile.seekg(0);

        cout << "Numero de facturas en el archivo: " << numFacturas << endl;

        // Crear las facturas
        for (int i = 0; i < numFacturas; i++) {
            Factura nuevaFactura(csvFile);
            facturas.push_back(nuevaFactura);
        }

        csvFile.close();
        return true;
    }

    void addNewFactura() {
        string answer;
        cout << "Quiere agregar otra factura (si/no) ";
        cin >> answer;

        if (answer == "si") {
            Factura nuevaFactura;
            facturas.push_back(nuevaFactura);
        }
    }

    void sortByAmount() {
        string answer;
        cout << "Quiere ordenar las facturas por cantidad? (si/no) ";
        cin >> answer;

        if (answer == "si") {
            bubbleSort(facturas);
        }
    }

    void displayAllFacturas() {
        for (int i = 0; i < facturas.size(); ++i) {
            facturas[i].printFactura();
            if (i != facturas.size() - 1) {
                cout << ",\n";
            }
        }
    }

    size_t size() const {
        return facturas.size();
    }

    const vector<Factura>& getFacturas() const {
        return facturas;
    }
};

#endif