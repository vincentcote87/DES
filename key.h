#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Key {
public:
	// Used to generate 16 subkeys from a string if 16 Hex chars
	Key(string);
	// Returns the subkeys, first perameter is the key number (starting at 1 not 0)
	// and the second is an empty int array of 48 to fill with the key.
	void getKey(int, int[48]);
private:
	string keyString;
	vector<int> k;
	vector<int> C;
	vector<int> D;
	int Kn[16][48]; // Kn 1 through 16

	// Converts a hex string into binary
	void convertToBinary();
	// Helper function for converting to Hex
	void pushToK(int, int, int, int);
	// Runs throught he permutation table for the keys
	void permutateKey();
	// Shifts keys once to the left
	void shiftKey();
	// Runs through to generate all 16 keys
	void generateKeys();
};

#endif