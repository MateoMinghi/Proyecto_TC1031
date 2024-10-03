

#ifndef _ADMINISTRADOR_FACTURAS_H_
#define _ADMINISTRADOR_FACTURAS_H_

#include <iostream>
#include <string>
#include <fstream>
#include "Facturas.h"

using namespace std;

class AdminFacturas{ 
public:
    Factura fact;

    vector<Factura> facturas;

private:
    AdminFacturas(){};
};




#endif