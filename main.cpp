#include <iostream>
#include <fstream>
#include <string>
#include "block.h"
#include "round.h"
#include "key.h"
#include "encrypt.h"

using namespace std;


int main(void) {

	Encrypt plainText("hello \n there");
	// Block blk("vincentc");
	// cout<<endl;
	
	// Key k("Hello");

	// Round rnd(blk.getLeft(), blk.getRight(), k);
	// rnd.expansion();
	return 0;
}
