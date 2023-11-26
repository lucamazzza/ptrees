#ifndef PTREES_H
#define PTREES_H

#include <iostream>

// Define a generic Node class using templates
template <typename T>
struct Node {
    T* data;
    Node* left;
    Node* right;
};

// Function to create a new node
template <typename T>
    Node<T>* createNode(T* data) {
    Node<T>* newNode = new Node<T>();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a new node into the binary search tree
template <typename T>
Node<T>* insert(Node<T>* root, T* data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (*data < *(root->data)) {
        root->left = insert(root->left, data);
    } else if (*data > *(root->data)) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to search for a node with a specific pointer value
template <typename T>
    Node<T>* search(Node<T>* root, T* data) {
    if (root == nullptr || *(root->data) == *data) {
        return root;
    }

    if (*data < *(root->data)) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to destroy the binary tree and free memory
template <typename T>
void destroyTree(Node<T>* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

#endif // PTREES_H