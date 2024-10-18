/*
 * Proyecto Generador Facturas
 * Mateo Minghi Vega
 * A01711231 
 */

#ifndef _FACTURAS_H_
#define _FACTURAS_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Factura {
public:
    
    //datos para generar la factura
    int Day, Month, Year;
    double Amount;
    string Address, RFC;
    string Description;



public:
    Factura(ifstream &csvFile); 
    /*un ifstream es un tipo de file stream en C++ que nos permite leer
    datos de archivos. Lo pasé como argumento en el constructor, porque
    de este modo evitamos abrir y cerrar el archivo muchas veces.
    Si abriéramos el archivo en cada instancia, se empezaría a leer desde
    el principio del csv, y todos los objetos tendrían los mismo datos.*/


    //constructor parametrizado. Por si se quiere crear una factura a mano
    Factura(int day, int month, int year, double amount, string address, 
    string rfc, string description ): 
    Day(day), Month(month), Year(year), Amount(amount), Address(address), 
    RFC(rfc), Description(description){};
    

    Factura();//constructor por omisión. Permite crear una factura a mano

    //void bubbleSort();
    //void generateDate();
    void readCSV(ifstream &csvFile); //funcion para leer el csv
    void create_new_Factura(); //crea una nueva factura manualmente
    void printFactura(); //imprime la factura
};

Factura::Factura(){
    create_new_Factura();
}

Factura::Factura(ifstream &csvFile) {
    readCSV(csvFile);  //lee SOLO una fila del csv
}

void Factura::create_new_Factura(){
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
    cout << "Fecha: " << Day << "," << Month << "," << Year << endl;
    cout << "Cantidad: " << Amount << endl;
    cout << "RFC: " << RFC << endl;
    cout << "Direccion: " << Address << endl;
    cout << "Descripcion: " << Description << endl;
}


void Factura::readCSV(ifstream &csvFile) {
    string line, temp; //variables temporales

    if (getline(csvFile, line)) { //lee una línea a la vez
        stringstream every_line(line); 
        /*utilizo un stringstream en vez de un string porque
        facilitan la manipulación de strings (como extraer o insertar)*/
        /*stringstream es, básicamente, un buffer en memória que simula
        comportarse como un archivo*/

        //tomamos el valor del stringstream y se lo asignamos a las variables
        getline(every_line, temp, ',');
        Day = stoi(temp);
        getline(every_line, temp, ',');
        Month = stoi(temp);
        getline(every_line, temp, ',');
        Year = stoi(temp);
        getline(every_line, temp, ',');
        Amount = stod(temp);
        getline(every_line, RFC, ',');
        getline(every_line, Address, ',');
        getline(every_line, Description, ',');
    } 
}





#endif