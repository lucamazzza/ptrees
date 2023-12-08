#include "ptrees.h"

#include <iostream>

int main() {
    PTree<int> intTree;

    intTree.insert(new int(50));
    intTree.insert(new int(30));
    intTree.insert(new int(70));
    intTree.insert(new int(20));
    intTree.insert(new int(40));
    intTree.insert(new int(60));
    intTree.insert(new int(80));

    int fif = 50;

    PTree<int>::Node* result = intTree.search(&fif);

    std::cout << *(result->data) << " |-> @" << result->data << std::endl << std::endl;

    intTree.values(false);

    intTree.remove(&fif);

    intTree.values(false);

    return 0;
}