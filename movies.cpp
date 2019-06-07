//movies.cpp
//Authors: Alejandro Diera
//Date: 21 May 2019

#include <iostream>
#include "movies.h"
#include "utility.h"
#include <string>
#include <vector>
#include <ctime>
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

}

// Recursive helper for printPreOrder
void BST::printPreOrder(Node *n) const {
    if(n) {
        cout<<n->movie_name<<", "<< n->movie_rating<<", "<<depth(n)<<endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// Search Function
void BST::search(string movie, int W) const {
    clock_t t;
    double time;
    Node *temp;
    t = clock();
    for(int i=0;i<=W;i++) {
        temp = getNodeFor(movie,root);
	temp = 0;
	time = (clock()-t);
	cout << "Time for search: " << time/1000 << endl;
	time = 0;
	t = clock();
    }
    //time = (clock() - t);
    //cout << "Time for search: " << time << endl;
    //cout << "Average time: " << ((time/W)/1000) << endl;
}

// Recursive function that finds Node with specific name
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

// Finds the depth of a node.
int BST::depth(Node *n) const {
    int i = 0;
    Node *temp = n;
    while(temp->parent) {
	i++;
	temp = temp->parent;
    }
    return i;
}

// Vector that contains all Nodes that start with a specific prefix
void BST::getNodesFor(string prefix, vector<Node*> &v) const {
    getNodesFor(prefix,v,root);
}

// Helper function
void BST::getNodesFor(string prefix, vector<Node*> &v, Node* n) const {
    int len = prefix.size();
    if(n) {
	if(prefix.compare(n->movie_name.substr(0,len)) == 0) { 
	    v.push_back(n);
	    getNodesFor(prefix, v, n->right);
	    return getNodesFor(prefix, v, n->left);
	}
	if(prefix.compare(n->movie_name.substr(0,len)) > 0)
	    return getNodesFor(prefix, v, n->right);
	else
	    return getNodesFor(prefix, v, n->left);
    }
    return;
}

void BST::bestMovie(string prefix) const {
    vector<Node*> b;
    getNodesFor(prefix,b);
    Node *temp, *best=0;
    if(b.empty())
	return;
    best = b[0];
    for(int i=0;i<b.size();i++) {
	temp = b[i];
	if(temp->movie_rating > best->movie_rating)
	    best = temp;
    }
    cout<<"Best movie is "<<best->movie_name<<" with rating "<<best->movie_rating;
    return;
}

