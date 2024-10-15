#ifndef _ADMINISTRADOR_FACTURAS_H_
#define _ADMINISTRADOR_FACTURAS_H_

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Facturas.h"

using namespace std;

class BinarySearchTree {
private:
    struct BSTNode {
        Factura data;
        BSTNode* left;
        BSTNode* right;

        BSTNode(const Factura& factura) : data(factura), left(nullptr), right(nullptr) {}
    };

    BSTNode* root;

    BSTNode* insert(BSTNode* node, const Factura& factura) {
        if (node == nullptr) {
            return new BSTNode(factura);
        }

        if (factura.Amount < node->data.Amount) {
            node->left = insert(node->left, factura);
        } else {
            node->right = insert(node->right, factura);
        }

        return node;
    }

    void inorderTraversal(BSTNode* node, vector<Factura>& result) const {
        if (node != nullptr) {
            inorderTraversal(node->left, result);
            result.push_back(node->data);
            inorderTraversal(node->right, result);
        }
    }

    void deleteTree(BSTNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(const Factura& factura) {
        root = insert(root, factura);
    }

    vector<Factura> getSortedFacturas() const {
        vector<Factura> result;
        inorderTraversal(root, result);
        return result;
    }

    size_t size() const {
        return getSortedFacturas().size();
    }
};

class FacturaManager {
private:
    BinarySearchTree bst;
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

    void addNewFactura() {
        string answer;
        cout << "Quiere agregar otra factura (si/no) ";
        cin >> answer;

        if (answer == "si") {
            Factura nuevaFactura;
            bst.insert(nuevaFactura);
        }
    }

    void displayAllFacturas() {
        vector<Factura> sortedFacturas = bst.getSortedFacturas();
        for (size_t i = 0; i < sortedFacturas.size(); ++i) {
            sortedFacturas[i].printFactura();
            if (i != sortedFacturas.size() - 1) {
                cout << ",\n";
            }
        }
    }

    size_t size() const {
        return bst.size();
    }

    vector<Factura> getFacturas() const {
        return bst.getSortedFacturas();
    }
};

#endif