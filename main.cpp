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
    manager.sortByAmount();
    manager.displayAllFacturas();

    return 0;
}