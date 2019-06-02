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
    bool insert(string name, double rating);//insert value return false if duplicate
    bool contains(string name, double rating) const;//true if value is in tree
    bool remove(string name);//deletes the Node containing the given value

private:

    struct Node {
      string movie_name;
      double movie_rating;
      Node *left, *right, *parent;
      // useful constructor:
      Node(string v="",double r=0.0) : movie_rating(r), movie_name(v), left(0), right(0), parent(0) {}
    };

    Node *root;
    Node* getNodeFor(string name, double rating, Node *n) const;
    void clear(Node *n); // for destructor
    bool insert(string name, double rating, Node *n); 

};

#endif
