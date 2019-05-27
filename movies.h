//movies.h
//Authors: Alejandro Diera
//Date: 21 May 2019

#ifdef MOVIES_H
#define MOVIES_H
#include <iostream>

using namespace std;

class BST {

public:

    BST();
    ~BST();
    bool insert(int value);
    bool contain(int value);
    bool remove(int value);

private:

    struct Node {
      int info;
      Node *left, *right, *parent;
      Node(int v=0) : info(v), left(0), right(0) parent(0) {}
    };
    Node *root;
    Node* getNodeFor(int value, Node* n)const;
    void clear(Node *n);
    bool insert(int value, Node *n);

};


#endif
