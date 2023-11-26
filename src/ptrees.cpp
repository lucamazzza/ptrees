#include "ptrees.h"

#include <iostream>

int main() {
    // Sample data
    int a = 5;
    int b = 3;
    int c = 7;

    // Creating and inserting nodes with int* data
    Node<int>* rootInt = nullptr;
    rootInt = insert(rootInt, &a);
    rootInt = insert(rootInt, &b);
    rootInt = insert(rootInt, &c);

    // Searching for a node
    int* searchDataInt = &b;
    Node<int>* resultInt = search(rootInt, searchDataInt);

    if (resultInt != nullptr) {
        std::cout << "Node with data " << *(resultInt->data) << " found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    // Destroying the tree
    destroyTree(rootInt);

    // Another sample with double* data
    double x = 3.14;
    double y = 1.23;
    double z = 5.67;

    Node<double>* rootDouble = nullptr;
    rootDouble = insert(rootDouble, &x);
    rootDouble = insert(rootDouble, &y);
    rootDouble = insert(rootDouble, &z);

    double* searchDataDouble = &y;
    Node<double>* resultDouble = search(rootDouble, searchDataDouble);

    if (resultDouble != nullptr) {
        std::cout << "Node with data " << *(resultDouble->data) << " found." << std::endl;
    } else {
        std::cout << "Node not found." << std::endl;
    }

    destroyTree(rootDouble);

    return 0;
}