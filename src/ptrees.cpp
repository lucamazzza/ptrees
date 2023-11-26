#include "ptrees.h"

#include <iostream>
using namespace std;

int main() {
    // Sample data
    int a = 5;
    int b = 3;
    int c = 7;

    PTree<int> intPtrs;
    intPtrs.insert(&a);
    intPtrs.insert(&b);
    intPtrs.insert(&c);

    int* interestingPtr = &b;

    PTree<int>::Node* result = intPtrs.search(interestingPtr);

    std::cout << "Pointer containing " << *(result->data) << " found at " << (result->data) << std::endl;
    return 0;
}