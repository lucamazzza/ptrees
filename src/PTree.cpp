#include "PTree.h"
#include <iostream>

int main() {

    // PTREE
    PTree<int> intTree;

    // INSERT VALUES
    intTree.insert(new int(1));
    intTree.insert(new int(10));
    intTree.insert(new int(5));
    intTree.insert(new int(6));
    intTree.insert(new int(43));
    intTree.insert(new int(32));
    intTree.insert(new int(11));
    intTree.insert(new int(34));
    intTree.insert(new int(44));
    intTree.insert(new int(81));
    intTree.insert(new int(91));
    intTree.insert(new int(33));
    intTree.insert(new int(31));
    intTree.insert(new int(2));
    intTree.insert(new int(8));
    intTree.insert(new int(0));
    intTree.insert(new int(99));
    intTree.insert(new int(9));

    // SEARCH VALUE
    int fif = 50;
    PTree<int>::Node* result = intTree.search(&fif);
    if(result) {
        std::cout << *(result->data) << " |-> @" << result->data << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    // REMOVE VALUE
    intTree.treeView(false);
    intTree.remove(&fif);
    intTree.treeView(false);

    // COUNT AND HEIGHT
    std::cout << "Count: " << intTree.count() << std::endl;
    std::cout << "Height: " << intTree.height() << std::endl;

    // MIN AND MAX
    int* min = intTree.min();
    int* max = intTree.max();
    std::cout << "Min val: " << *min << std::endl;
    std::cout << "Max val: " << *max << std::endl;

    // TRAVERSAL
    std::cout << "Preorder: ";
    intTree.preOrderTrasversal();
    std::cout << std::endl;
    std::cout << "Inorder: ";
    intTree.inOrderTrasversal();
    std::cout << std::endl;
    std::cout << "Postorder: ";
    intTree.postOrderTrasversal();
    std::cout << std::endl;

    return 0;
}