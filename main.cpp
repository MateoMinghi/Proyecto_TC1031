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
    int numFacturas;

    cout << "Ingrese el numero de facturas a añadir: ";
    cin >> numFacturas;

    for (int i = 0; i < numFacturas; i++) {
        cout << "Factura #" << (i + 1) << ": ";
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