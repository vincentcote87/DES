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
	Encrypt(string, string);
	string getEncrypted();

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