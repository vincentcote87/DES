#include <iostream>
#include <fstream>
#include <string>
#include "block.h"

using namespace std;


int main(void) {

	Block blk("vincentc");
	cout<<endl;
	cout<<blk.getRight()[4];
	// blk.convertString();
	return 0;
}
