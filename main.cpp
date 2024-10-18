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
    
    

    while (true){
        string answer;
        cout << "Quiere agregar otra factura (si/no) ";
        cin >> answer;
        cout << " " << endl;

        if (answer == "si") {
            manager.addNewFactura();
        }
        else if (answer != "si"){
            break;
        }
    }

    manager.printFacturas();

    return 0;
}