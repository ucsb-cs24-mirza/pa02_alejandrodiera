//tests.cpp
//Authors: Alejandro Diera
//Date: 21 May 2019

#include <iostream>
#include "tests.h"
#include "movies.h"

using namespace std;

int getTest();

int main() {

    BST b1,b2;

    // insert data to b1
    b1.insert("movie1",1.0);
    b1.insert("movie2",2.0);
    b1.insert("movie3",3.0);
    b1.insert("movie4",4.0);
    b1.insert("movie5",5.0);
    b1.insert("movie6",6.0);
    b1.insert("movie7",7.0);
    b1.insert("movie8",8.0);
    b1.insert("movie9",9.0);

    bool all = true;
    int testnum = getTest();
    if(testnum)
	all = false;
    if(all || testnum == 1) {
        cout << endl << "BST: " << endl << "pre-order:\n";
        b1.printPreOrder();
	cout << endl;
    }
    if(all || testnum == 2) {
	cout << endl << "BST: " << endl << "before insert:\n";
	b2.printPreOrder();
	b2.insert("Avengers Endgame",10.0);
	b2.insert("Iron Man 3",3000.0);
	cout << endl << "after insert:\n";
	b2.printPreOrder();
	cout << endl;
    }
    if(all || testnum == 3) {
	cout << endl << "BST: " << endl << "constructor:\n";
	BST b3;
	b3.printPreOrder();
	cout << "if empty: PASS\n";
	cout << endl;
    }
    if(all || testnum == 4) {
	cout << endl << "BST: " << endl << "bestMovie:\n";
	cout << "EXPECTED: Best movie is movie9 with a rating of 9";
	cout << endl << "ACTUAL: ";
	b1.bestMovie("m");
	cout << endl << endl;
    }

    return 0;
}

int getTest() {
    cout << "Choice of tests:\n"
	 << " 0. all tests\n"
	 << " 1. pre-order\n"
	 << " 2. insert\n"
	 << " 3. construct\n"
	 << " 4. bestMovie\n";

    do {
	int choice;
	cout << "Enter choice:\n";
	cin >> choice;
	if(choice >=0 && choice <=4)
	    return choice;
	cout << "0, 1, 2, 3, 4 only!\n";
    } while(true);
}

