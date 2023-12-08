//
// Created by Luca Mazza on 2023/11/24.
//
#ifndef PTREES_H
#define PTREES_H

#include <iostream>
#include <vector>
#include <iomanip>

// Class to represent a binary search tree
// T is the type of data stored in the tree
template <typename T>
class PTree {
public:
    // Structure to represent a node in the binary search tree
    // T is the type of the pointer to the node
    // left, right are pointers to the left and right children of the node
    struct Node {
        T* data;
        Node* left;
        Node* right;
    };

private:
    // Root node of the binary search tree
    Node* root;

    // Function to create a new node
    // data is the pointer to the data to be stored in the node
    // returns a pointer to the new node
    Node* createNode(T* data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a new node into the binary search tree
    // current is the pointer to the current node
    // data is the pointer to the data to be stored in the node
    // returns a pointer to the new node
    Node* insert(Node* current, T* data) {
        if (current == nullptr) {
            return this->createNode(data);
        }
        if (*data < *(current->data)) {
            current->left = this->insert(current->left, data);
        } else if (*data > *(current->data)) {
            current->right = this->insert(current->right, data);
        }
        return current;
    }

    // Function to search for a node with a specific pointer value
    // current is the pointer to the current node
    // data is the pointer to the data to be searched for
    // returns a pointer to the node if found, nullptr otherwise
    Node* search(Node* current, T* data) {
        if (current == nullptr || *(current->data) == *data) {
            return current;
        }
        if (*data < *(current->data)) {
            return search(current->left, data);
        } else {
            return search(current->right, data);
        }
    }

    // Function to remove a node from the binary search tree
    // node is the pointer to the node to be removed
    // value is the pointer to the data to be removed
    // returns a pointer to the new root
    Node* removeNode(Node* node, T* value) {
        if (node == nullptr) {
            return node;
        }
        if (*value < *(node->data)) {
            node->left = removeNode(node->left, value);
        } else if (*value > *(node->data)) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
        return node;
    }

    // Function to destroy the tree
    // node is the pointer to the root of the tree
    // deletes all the nodes in the tree
    void destroyTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    // Function to print the tree showing the values contained
    // in the nodes
    // prefix is the string to be printed before the value
    // node is the pointer to the current node
    // isLeft is true if the node is the left child of its parent
    // showAddress is true if the address of the node should be printed
    void print(const std::string& prefix, const Node* node, bool isLeft, bool showAddress) const {
        if( node == nullptr ) {
            return;
        }
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << *(node->data);
        if (showAddress) {
            std::cout <<  " (" << (node->data) << ")";
        }
        std::cout << std::endl;
        print( prefix + (isLeft ? "│   " : "    "), node->left, true, showAddress);
        print( prefix + (isLeft ? "│   " : "    "), node->right, false, showAddress);
    }

    // Function to count the number of nodes in the binary search tree
    // node is the pointer to the current node
    // returns the number of nodes in the tree
    int countNodes(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Function to get the height of the binary search tree
    // node is the pointer to the current node
    // returns the height of the tree
    int treeHeight(Node* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(treeHeight(node->left), treeHeight(node->right));
    }

    // Function to find the minimum value in the binary search tree
    // node is the pointer to the current node
    // returns the minimum value in the tree
    Node* findMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Function to find the maximum value in the binary search tree
    // node is the pointer to the current node
    // returns the maximum value in the tree
    Node* findMax(Node* node) const {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Function to print the binary search tree
    // node is the pointer to the current node
    // prints the values in the tree
    void inOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << *(node->data) << " ";
        inOrder(node->left);
        inOrder(node->right);
    }

    // Function to print the binary search tree
    // node is the pointer to the current node
    // prints the values in the tree in pre order
    void preOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        std::cout << *(node->data) << " ";
        preOrder(node->left);
        preOrder(node->right);

    }

    // Function to print the binary search tree
    // node is the pointer to the current node
    // prints the values in the tree in post order
    void postOrder(Node* node) const {
        if (node == nullptr) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        std::cout << *(node->data) << " ";
    }

public:
    // Constructor
    PTree() : root(nullptr) {}

    // Destructor
    ~PTree() {
        destroyTree(root);
    }

    // Public method to insert data into the tree
    void insert(T* data) {
        root = this->insert(root, data);
    }

    // Public method to search for data in the tree
    Node* search(T* data) {
        return search(root, data);
    }

    // Public method to remove data from the tree
    void remove(T* value) {
        root = removeNode(root, value);
    }

    // Public method to print the tree
    void treeView(bool showAddress = false) const {
        print("", root, false, showAddress);
    }

    // Public method to count the number of nodes in the tree
    int count() const {
        return countNodes(root);
    }

    // Public method to get the height of the tree
    int height() const {
        return treeHeight(root);
    }

    // Public methods to get the minimum and maximum values in the tree
    T* min() const {
        Node* minNode = findMin(root);
        return (minNode != nullptr) ? minNode->data : nullptr;
    }

    // Public methods to get the minimum and maximum values in the tree
    T* max() const {
        Node* maxNode = findMax(root);
        return (maxNode != nullptr) ? maxNode->data : nullptr;
    }

    // Public methods to get the minimum and maximum values in the tree
    void inOrderTrasversal() const {
        inOrder(root);
    }

    // Public methods to get the minimum and maximum values in the tree
    void preOrderTrasversal() const {
        preOrder(root);
    }

    // Public methods to get the minimum and maximum values in the tree
    void postOrderTrasversal() const {
        postOrder(root);
    }
};

#endif // PTREES_H