#include <iostream>
#include <string>
#include <vector>
#include "round.h"
#include "block.h"
#include "key.h"
#include "decrypt.h"

using namespace std;

const int INVERSE_IP[] = {
	40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41,  9, 49, 17, 57, 25
};

Decrypt::Decrypt(string plainText, string providedKey) {
	int index = 0;
	int key[48]; // use get key(key#, key), key# starts at 1 through 16
	Key k(providedKey);

	while(index != plainText.length()) {
		Rn.clear();
		Ln.clear();
		RL.clear();
		char tmp[16];
		for(int i = 0; i < 16; i++) {
			tmp[i] = plainText.at(i + index);
		}

		Block blk(tmp);
		Ln = blk.getLeft();
		Rn = blk.getRight();
		int i = 16;
		for(int j = 1; j <= 16; j++) {
			k.getKey(i, key);
			Round r(Ln, Rn, key);
			Ln = Rn;
			Rn = r.getRight();
			i--;
		}

		for(int j = 0; j < 32; j++) {
			RL.push_back(Rn[j]);
		}
		for(int j = 0; j < 32; j++) {
			RL.push_back(Ln[j]);
		}

		for(int j = 0; j < 64; j++) {
			inverseIP.push_back(RL[INVERSE_IP[j] - 1]);
		}
		index += 16;
	}
}

string Decrypt::getDecrypted() {
	int tmpChar[4];
	C = "";
	for(int i = 0; i < inverseIP.size(); i++) {
		tmpChar[i % 4] = inverseIP[i];
		if(i % 4 == 3) {
			C = C + convertToHex(tmpChar);
		}
	}
	return C;
}

char Decrypt::convertToHex(int x[4]) {
	int y = (x[0] * 8) + (x[1] * 4) + (x[2] * 2) + (x[3] * 1);
	char ch;
	switch(y) {
		case 0 : ch = '0'; break;
		case 1 : ch = '1'; break;
		case 2 : ch = '2'; break;
		case 3 : ch = '3'; break;
		case 4 : ch = '4'; break;
		case 5 : ch = '5'; break;
		case 6 : ch = '6'; break;
		case 7 : ch = '7'; break;
		case 8 : ch = '8'; break;
		case 9 : ch = '9'; break;
		case 10 : ch = 'A'; break;
		case 11 : ch = 'B'; break;
		case 12 : ch = 'C'; break;
		case 13 : ch = 'D'; break;
		case 14 : ch = 'E'; break;
		case 15 : ch = 'F'; break;
	}
	return ch;
}