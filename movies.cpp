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
    if(name==n->movie_name || rating==n->movie_rating)
	return false;
    if(rating < n->movie_rating) {
	if(n->left)
	    return insert(name, rating, n->left);
	else {
	    n->left = new Node(name, rating);
	    n->left->parent = n;
	    return true;
	}
    }
    else {
	if(n->right)
	    return insert(name, rating, n->right);
	else {
	    n->right = new Node(name, rating);
	    n->right->parent = n;
	    return true;
	}
    }
}

BST::Node* BST::getNodeFor(string name, double rating, Node *n) const {
    if(n) {
	if(name == n->movie_name)
	    return n;
	else if(rating > n->movie_rating)
	    return getNodeFor(name, rating, n->right);
	else
	    return getNodeFor(name, rating, n->left);
    }
    else
	return NULL;
}

void BST::movieSearch(string name, double rating) const {
    Node *n = getNodeFor(name, rating, root);
    if(n)
	return true;
    else 
	return false;
}

void BST::ratingSearch(string prefix, double rating) const {
    Node *n = getNodeFor(name, rating, root);
    if(n)
	return true;
    else 
	return false;
}
//std::string compare
