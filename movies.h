//movies.h
//Authors: Alejandro Diera
//Date: 21 May 2019

#ifdef MOVIES_H
#define MOVIES_H

#include <iostream>
using namespace std;

class movieBST {

public:

    BST(); // constructor
    ~BST(); // destructor
    bool insert(int value); // insert value; return false if duplicate
    bool contain(int value); // true if value is in tree
    bool remove(int value); // deletes the Node containing the given value

private:

    struct Node {
      int info;
      Node *left, *right, *parent;
      // useful constructor:
      Node(int v=0) : info(v), left(0), right(0) parent(0) {}
    };

    Node *root;
    Node* getNodeFor(int value, Node *n) const;
    void clear(Node *n); // for destructor
    bool insert(int value, Node *n); 

};

#endif
