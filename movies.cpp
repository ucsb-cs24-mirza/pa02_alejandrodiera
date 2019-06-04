//movies.cpp
//Authors: Alejandro Diera
//Date: 21 May 2019

#include <iostream>
#include "movies.h"
#include "utility.h"
#include <string>
using namespace std;

// Constructor that sets up empty tree
BST::BST() : root(0) {}

// Destructor, deletes all nodes in BST
BST::~BST() {
    clear(root);
}

// Recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
        clear(n->left);
	clear(n->right);
	delete n;
    }
}

// Insert value in tree, returns false if duplicate
bool BST::insert(string name, double rating) {
    if(!root) {
	root = new Node(name, rating);
	return true;
    }
    return insert(name, rating, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(string name, double rating, Node *n) {
    string mn = n->movie_name;
    if(mn.compare(name) > 0) {
	if(n->left)
	    return insert(name, rating, n->left);
	else {
	    n->left = new Node(name, rating);
	    n->left->parent = n;
	    return true;
	}
    }
    else if(mn.compare(name) < 0) {
	if(n->right)
	    return insert(name, rating, n->right);
	else {
	    n->right = new Node(name, rating);
	    n->right->parent = n;
	    return true;
	}
    }
    else
    	return false;
}

// Prints pre-order traversal
void BST::printPreOrder() const {
    printPreOrder(root);
    cout << endl;
}

// Recursive helper for printPreOrder
void BST::printPreOrder(Node *n) const {
    if(n) {
        cout<<n->movie_name<<", "<< n->movie_rating<<", "<<depth(n)<<endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

BST::Node* BST::getNodeFor(string name, Node *n) const {
    if(n) {
	if(name == n->movie_name)
	    return n;
	else if(name.compare(n->movie_name) > 0)
	    return getNodeFor(name, n->right);
	else
	    return getNodeFor(name, n->left);
    }
    else
	return NULL;
}

BST::Node* BST::getNodePrefix(string prefix, Node *n) const {
    if(n) {
	if(prefix.compare(n->movie_name.substr(0,prefix.size())) == 0)
	    return n;
	else if(prefix.compare(n->movie_name.substr(0,prefix.size())) > 0)
	    return getNodePrefix(prefix, n->right);
	else
	    return getNodePrefix(prefix, n->left);
    }
    else
	return NULL;
}

int BST::depth(Node *n) const {
    int i = 0;
    Node *temp = n;
    while(temp->parent) {
	i++;
	temp = temp->parent;
    }
    return i;
}

