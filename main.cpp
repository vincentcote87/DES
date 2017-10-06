#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include "block.h"
#include "round.h"
#include "key.h"
#include "encrypt.h"

using namespace std;

int main(void) {

	// Key k("133457799BBCDFF1");
	Encrypt plainText("abcdefgh");
	// Block blk("vincentc");
	// cout<<endl;
	
	// Key k("Hello");

	// Round rnd(blk.getLeft(), blk.getRight(), k);
	// rnd.expansion();
	return 0;
}
