#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "block.h"
#include "round.h"
#include "key.h"
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

int main(void) {

	Encrypt plainText("abcdefgh");
	cout<<plainText.getEncrypted()<<endl;
	Decrypt cypherText("abcdefgh");
	cout<<cypherText.getDecrypted()<<endl;

	return 0;
}
