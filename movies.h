//movies.h
//Authors: Alejandro Diera
//Date: 21 May 2019

#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <string>
using namespace std;

class BST {

public:

    BST(); // constructor
    ~BST(); // destructor
    bool insert(string value); // insert value; return false if duplicate
    bool contains(string value) const; // true if value is in tree
    bool remove(string value); // deletes the Node containing the given value

private:

    struct Node {
      string info;
      Node *left, *right, *parent;
      // useful constructor:
      Node(string v="") : info(v), left(0), right(0), parent(0) {}
    };

    Node *root;
    Node* getNodeFor(string value, Node *n) const;
    void clear(Node *n); // for destructor
    bool insert(string value, Node *n); 

};

#endif
