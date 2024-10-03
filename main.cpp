/*
 * Proyecto Generador Facturas
 * Mateo Minghi Vega
 * A01711231 
 */

#include <iostream>
#include <string>
#include "Facturas.h"
#include "Administrador_Facturas.h"

using namespace std;

int main() {
    vector<Factura> facturas;
    
    //se abre el csv solo una vez, evitamos que se repitan valores
    ifstream csvFile("info_facturas.csv");
    if (!csvFile.is_open()) {
        return 0;
    }

    string line;
    int numFacturas = 0;

    //contamos el número de filas en el csv
    while (getline(csvFile, line)) {
        numFacturas++;
    }
    
    // reseteamos el apuntador del filestream al principio del csv
    csvFile.clear();  
    csvFile.seekg(0); 

    cout << "Numero de facturas en el archivo: " << numFacturas << endl;

    //Creamos el mismo número de instancias como hay filas en el csv
    for (int i = 0; i < numFacturas; i++) {
        Factura nuevaFactura(csvFile);  
        facturas.push_back(nuevaFactura);  
    }

    csvFile.close();//se cierra el archivo

    string answer1;
    cout << "Quiere agregar otra factura (si/no) ";
    cin >> answer1;

    if (answer1 == "si"){
        Factura nuevaFactura;
        facturas.push_back(nuevaFactura);
    }

    string answer;
    cout << "Quiere ordenar las facturas por cantidad? (si/no) ";
    cin >> answer;
    
    if (answer == "si"){
        bubbleSort(facturas);
    }    
    
    for (int i = 0; i < facturas.size(); ++i) {
        facturas[i].printFactura();  
        if (i != facturas.size() - 1) {
            cout << ",\n";  
        }
    }

    return 0;
}