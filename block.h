#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Block {
public:
	// Block is used for the initial round to generate left and right sides of the 64 bit string.
	Block(string = "");

	// Returns the left side of the bit string
	vector<int> getLeft();
	// returns the righ side of the bit string
	vector<int> getRight();

private:
	vector<int> binaryPlainText;
	vector<int> L;
	vector<int> R;
	string plainText;

	// Converts the string of Hex chars to a 64 bit binary string
	void convertString();
	// Helper function to push the 4 bits of each hex char
	void pushToBPT(int,int,int,int);
	// Sends the string through the IP
	void initialPermutation();
	// Splits the 64 bit string into a right and left 32 bit strings.
	void splitLeftRight();

};

#endif