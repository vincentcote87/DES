#include <iostream>
#include <fstream>
#include <string>
#include "block.h"

using namespace std;


int main(void) {
	Block blk("vincentc");
	// blk.convertString();
	return 0;
}
// void bitConverter(int x, int &converted);

// int main(void) {

// 	ifstream inFile;
// 	string str;
// 	string testStr = "VincentC";
// 	int tmpChar = 'a';
// 	int binChar;
// 	cout << tmpChar<<endl;
// 	binChar = bitConverter(tmpChar);

// 	inFile.open("testing.txt");

// 	getline(inFile, str);


// 	return 0;
// }

// int bitConverter(int x, int &converted) {
// 	int binaryNum[8];

// 	for(int i = 0; i < 8; i++) {
// 		binaryNum[i] = x % 2;
// 		x = x/2;
// 	}

// 	for(int i = 7; i >= 0; i--) {
// 		cout << binaryNum[i];
// 	}

// }