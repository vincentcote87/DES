#include <iostream>
#include <string>
#include <vector>
#include "round.h"
#include "block.h"
#include "key.h"
#include "encrypt.h"

using namespace std;

Encrypt::Encrypt(string plainText) {
	char tmp[8];
	int key[48];
	string str;
	cout<<plainText.at(0)<<endl;
	for(int i = 0; i < 8; i++) {
		tmp[i] = plainText.at(i);
	}
	Key k("133457799BBCDFF1");
	Block blk(tmp);
	Round rd(blk.getLeft(), blk.getRight(), k);

	k.getKey(2, key);
	cout<<endl;
	for(int i = 0; i < 48; i++) {
		cout<<key[i];
	}
	cout<<endl;
}