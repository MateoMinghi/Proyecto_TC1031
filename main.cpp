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
    FacturaManager manager("info_facturas.csv");
    
    manager.loadFromCSV();

    manager.addNewFactura();
    // The sortByAmount function call has been removed as it's no longer needed
    manager.displayAllFacturas();

    return 0;
}