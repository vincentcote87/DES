#ifndef DECRYPT_H
#define DECRYPT_H

#include <iostream>
#include <string>
#include <vector>
#include "block.h"
#include "round.h"
#include "key.h"

using namespace std;

class Decrypt {
public:
	// Takes in a string (in Hex) to decrypt and a key as perameters
	Decrypt(string, string);
	// returns the string of decrypted text (in Hex), needs to be converted to plaintext outside of this function
	string getDecrypted();

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