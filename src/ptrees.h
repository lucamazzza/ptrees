#ifndef PTREES_H
#define PTREES_H

#include <iostream>
#include <vector>
#include <iomanip>


template <typename T>
class PTree {
public:
    // Define a generic Node class using templates
    struct Node {
        T* data;
        Node* left;
        Node* right;
    };

private:
    Node* root;

    // Function to create a new node
    Node* createNode(T* data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Function to insert a new node into the binary search tree
    Node* insert(Node* current, T* data) {
        if (current == nullptr) {
            return createNode(data);
        }

        if (*data < *(current->data)) {
            current->left = insert(current->left, data);
        } else if (*data > *(current->data)) {
            current->right = insert(current->right, data);
        }

        return current;
    }

    // Function to search for a node with a specific pointer value
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

    // Function to destroy the binary tree and free memory
    void destroyTree(Node* current) {
        if (current != nullptr) {
            destroyTree(current->left);
            destroyTree(current->right);
            delete current;
        }
    }

    // Function to print the tree showing the values contained
    void print(const std::string& prefix, const Node* node, bool isLeft, bool showAddress)
    {
        if( node != nullptr )
        {
            std::cout << prefix;

            std::cout << (isLeft ? "├──" : "└──" );

            // print the value of the node
            std::cout << *(node->data);
            if (showAddress) {
                std::cout <<  " (" << (node->data) << ")";
            }
            std::cout << std::endl;

            // enter the next tree level - left and right branch
            print( prefix + (isLeft ? "│   " : "    "), node->left, true, showAddress);
            print( prefix + (isLeft ? "│   " : "    "), node->right, false, showAddress);
        }
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
        root = insert(root, data);
    }

    // Public method to search for data in the tree
    Node* search(T* data) {
        return search(root, data);
    }

    void values(bool showAddress){
        print("", root, false, showAddress);
    }
};

#endif // PTREES_H