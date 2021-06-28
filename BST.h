#pragma once
#include <iostream>

using ValueType = int;

class BST {
    class Node {
    public:
        Node(ValueType value)
            : left(nullptr), right(nullptr), value(value) { }
        Node* left;
        Node* right;
        ValueType value;
    };
    Node* getNode(ValueType value);
    Node* getPrevNode(ValueType value);
    void replaceCur(Node* prev, Node* cur, Node* newCur);

public:
    BST();

    BST(const BST& other);
    BST(BST&& other);
    BST& operator=(const BST& other);
    BST& operator=(BST&& other);
    ~BST();

    void add(ValueType value);
    void remove(ValueType value);
    ValueType& find(ValueType value);

private:
    Node* _root;
    size_t _size;
};