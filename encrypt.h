#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <iostream>
#include <string>
#include <vector>
#include "block.h"
#include "round.h"
#include "key.h"

using namespace std;

class Encrypt {
public:
	// Takes in a string (in Hex) to encrypt and a key as perameters
	Encrypt(string, string);
	// returns the string of encrypted text (in Hex)
	string getEncrypted();

private:
	string M;
	string C;
	vector<int> Ln;
	vector<int> Rn;
	vector<int> RL;
	vector<int> inverseIP;

	// Converts binary string of 4 bits ro hex char
	char convertToHex(int[4]);

};

#endif