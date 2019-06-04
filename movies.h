//movies.h
//Authors: Alejandro Diera
//Date: 21 May 2019

#ifndef MOVIES_H
#define MOVIES_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

class BST {

public:

    BST(); //constructor
    ~BST(); //destructor
    bool insert(string name, double rating); //insert value return false if duplicate
    void printPreOrder() const; //prints pre-order traversal
    void bestMovie(string prefix) const; //prints out best movie w/ specific prefix 
private:

    struct Node {
      string movie_name;
      double movie_rating;
      Node *left,*right, *parent;
      // useful constructor:
      Node(string v="",double r=0.0):movie_rating(r),movie_name(v),left(0),right(0),parent(0) {}
    };

    Node *root; 
    Node* getNodeFor(string name, Node *n) const; //searches for movie
    vector<Node*> getNodesFor(string prefix) const; //vector that contains movies w/ prefix
    vector<Node*> getNodesFor(string prefix, vector<Node*> v, Node *n) const; //helper
    void clear(Node *n); //helper
    bool insert(string name, double rating, Node *n); //helper
    void printPreOrder(Node *n) const; //helper
    int depth(Node *n) const; 
   
};

#endif
