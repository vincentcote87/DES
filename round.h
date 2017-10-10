#ifndef ROUND_H
#define ROUND_H

#include <iostream>
#include <string>
#include <vector>
#include "key.h"

using namespace std;

class Round {
public:
	// Takes in left and right side as well as sub key to do a round
	Round(vector<int>, vector<int>, int[48]);
	// Expands the string using the expansion table
	void expansion();
	// Generates the f function
	void fFunction();
	// Runs through the 8 s boxes
	void sBox();
	// Converts 4 bits to an int
	int convertToInt(int[4]);
	// Runs through the final permutation
	void finalPermutation();
	// Returns the right side for the next round
	vector<int> getRight();
private:
	vector<int> L;
	vector<int> R;
	vector<int> expendedR;
	vector<int> F;
	vector<int> key;
	vector<int> KxorER;
	vector<int> sboxValues;
	vector<int> finalF;
	vector<int> Rn;

};

#endif