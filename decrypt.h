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
	Decrypt(string, string);
	string getDecrypted();

private:
	string M;
	string C;
	vector<int> Ln;
	vector<int> Rn;
	vector<int> RL;
	vector<int> inverseIP;

	char convertToHex(int[4]);

};

#endif