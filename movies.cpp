//movies.cpp
//Authors: Alejandro Diera
//Date: 21 May 2019

#include <iostream>
#include "movies.h"
#include "utility.h"

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
void BST::insert(int value) {
    if(!root) {
	root = new Node(value);
	return true;
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool BST::insert(int value, Node *n) {
    if(value==n->info)
	return false;
    if(value < n->info) {
	if(n->left)
	    return insert(value,n->left);
	else {
	    n->left = new Node(value);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if(n->right)
	    return insert(value, n->right);
	else {
	    n->right = new Node(value);
	    n->right->parent = n;
	    return true;
	}
    }
}

BST::Node* BST::getNodeFor(int avlue, Node *n) const {
    if(n) {
	if(value == n->info)
	    return n;
	else if(value > n->info)
	    return getNodeFor(value,n->right);
	else
	    return getNodeFor(value,n->left);
    }
    else
	return NULL;
}

bool BST::constrains(int value)const {
    Node *n = getNodeFor(value,root);
    if(n)
	return true;
    else 
	return false;
}














    return 0;
}
