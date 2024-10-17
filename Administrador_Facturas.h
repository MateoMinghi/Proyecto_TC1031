#ifndef _ADMINISTRADOR_FACTURAS_H_
#define _ADMINISTRADOR_FACTURAS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Facturas.h"

using namespace std;

class Node {
public:
    Factura data;
    Node* left;
    Node* right;

    Node(Factura& factura) : data(factura), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

public: 
    BinarySearchTree() : root(nullptr) {}

    void traversal(Node* node, vector<Factura>& result) const;

    void insert(Factura& factura);

    vector<Factura> getSortedFacturas() const;

    long long size() const;
};


void BinarySearchTree::traversal(Node* node, vector<Factura>& result) const {
    if (node != nullptr) {
        traversal(node->left, result);
        result.push_back(node->data);
        traversal(node->right, result);
    }
}


void BinarySearchTree::insert(Factura& factura) {
    if (root == nullptr) {
        root = new Node(factura);
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (factura.Amount < current->data.Amount) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (factura.Amount < parent->data.Amount) {
        parent->left = new Node(factura);
    } else {
        parent->right = new Node(factura);
    }
}

vector<Factura> BinarySearchTree::getSortedFacturas() const {
    vector<Factura> result;
    traversal(root, result);
    return result;
    }


long long BinarySearchTree::size() const {
    return getSortedFacturas().size();
}




class FacturaManager {
private:
    BinarySearchTree bst;
    string csvFilename;

public:
    FacturaManager(const string& filename) : csvFilename(filename) {}

    bool loadFromCSV();

    void addNewFactura();
    

    void printFacturas();

    long long size() const {
        return bst.size();
    }

    vector<Factura> getFacturas() const {
        return bst.getSortedFacturas();
    }
};


bool FacturaManager::loadFromCSV() {
        ifstream csvFile(csvFilename);
        if (!csvFile.is_open()) {
            cout << "Error: No se pudo abrir el archivo " << csvFilename << endl;
            return false;
        }

        string line;
        int numFacturas = 0;

        
        while (getline(csvFile, line)) {
            numFacturas++;
        }

        
        csvFile.clear();
        csvFile.seekg(0);

        cout << "Numero de facturas en el archivo: " << numFacturas << endl;

        
        for (int i = 0; i < numFacturas; i++) {
            Factura nuevaFactura(csvFile);
            bst.insert(nuevaFactura);
        }

        csvFile.close();
        return true;
    }


void FacturaManager::addNewFactura() {
    Factura nuevaFactura;
    bst.insert(nuevaFactura);
}

void FacturaManager::printFacturas() {
    vector<Factura> sortedFacturas = bst.getSortedFacturas();
    for (long long i = 0; i < sortedFacturas.size(); ++i) {
        sortedFacturas[i].printFactura();
        if (i != sortedFacturas.size() - 1) {
            cout << " " << endl;
        }
    }
}

#endif