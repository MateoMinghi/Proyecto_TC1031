/*
 * Proyecto Generador Facturas
 * Mateo Minghi Vega
 * A01711231 
 */


/*ESTA ES LA PRIMERA VERSIÓN. VA A SER MÁS ROBUSTO*/


#ifndef _FACTURAS_H_
#define _FACTURAS_H_

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Factura {
public:
    
    int Day, Month, Year;
    double Amount;
    string Address, RFC;
    string Description;



public:
    Factura();
    Factura(int day, int month, int year, double amount, string address, string rfc, string description ): 
    Day(day), Month(month), Year(year), Amount(amount), Address(address), RFC(rfc), Description(description){};
    
    //void bubbleSort();
    //void generateDate();
    void printFactura();
};

Factura::Factura(){
    cout << "Ingrese el dia: ";
    cin >> Day;

    cout << "Ingrese el mes: ";
    cin >> Month;

    cout << "Ingrese el año: ";
    cin >> Year;

    cout << "Ingrese la cantidad a facturar: ";
    cin >> Amount;

    cout << "Ingrese el RFC: ";
    cin >> RFC;

    cin.ignore(); 

    cout << "Ingrese la direccion: ";
    getline(cin, Address); 

    cout << "Ingrese una descripcion: ";
    getline(cin, Description); 
}

void Factura::printFactura(){
    cout << "Fecha: " << Day << endl;
    cout << "Cantidad: " << Amount << endl;
    cout << "RFC: " << RFC << endl;
    cout << "Direccion: " << Address << endl;
    cout << "Descripcion: " << Description << endl;
}



void bubbleSort(vector<Factura>& facturas) {
    int n = facturas.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (facturas[j].Amount > facturas[j + 1].Amount) {
                facturas[j], facturas[j + 1] = facturas[j + 1], facturas[j] ;
            }
        }
    }
}





#endif