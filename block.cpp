#include <iostream>
#include <string>
#include <vector>
#include "block.h"

using namespace std;

const int P[] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7
};

const int testing[] = {
	// 0,0,0,0,
	// 0,0,0,1,
	// 0,0,1,0,
	// 0,0,1,1,
	// 0,1,0,0,
	// 0,1,0,1,
	// 0,1,1,0,
	// 0,1,1,1,
	// 1,0,0,0,
	// 1,0,0,1,
	// 1,0,1,0,
	// 1,0,1,1,
	// 1,1,0,0,
	// 1,1,0,1,
	// 1,1,1,0,
	// 1,1,1,1
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
	0,0,1,1,
	1,0,0,0,
};

Block::Block(string str) {
	plainText = str;
	convertString();
	initialPermutation();
	splitLeftRight();
}

vector<int> Block::getLeft() {
	return L;
}

vector<int> Block::getRight() {
	return R;
}

void Block::convertString() {
	// int tmp;

	// for(int i = 0; i < plainText.length(); i++) {
	// 	tmp = plainText[i];
	// 	int tmpBlock[8];
	// 	for(int j = 7; j >= 0; j--) {
	// 		tmpBlock[j] = tmp % 2;
	// 		tmp = tmp / 2;
	// 	}
	// 	for(int j = 0; j < 8; j++) {
	// 		binaryPlainText.push_back(tmpBlock[j]);
	// 	}
	// }

	char ch;
	for(int i = 0; i < 16; i++) {
		ch = plainText.at(i);

		switch(ch) {
			case '0' : pushToBPT(0,0,0,0); break;
			case '1' : pushToBPT(0,0,0,1); break;
			case '2' : pushToBPT(0,0,1,0); break;
			case '3' : pushToBPT(0,0,1,1); break;
			case '4' : pushToBPT(0,1,0,0); break;
			case '5' : pushToBPT(0,1,0,1); break;
			case '6' : pushToBPT(0,1,1,0); break;
			case '7' : pushToBPT(0,1,1,1); break;
			case '8' : pushToBPT(1,0,0,0); break;
			case '9' : pushToBPT(1,0,0,1); break;
			case 'a' : case 'A' : pushToBPT(1,0,1,0); break;
			case 'b' : case 'B' : pushToBPT(1,0,1,1); break;
			case 'c' : case 'C' : pushToBPT(1,1,0,0); break;
			case 'd' : case 'D' : pushToBPT(1,1,0,1); break;
			case 'e' : case 'E' : pushToBPT(1,1,1,0); break;
			case 'f' : case 'F' : pushToBPT(1,1,1,1); break;
			default : cout << "Critical Error" << endl;
		}
	}
	// //debug msg
	// for(int k = 0; k < binaryPlainText.size(); k++) {
	// 	cout << binaryPlainText[k];
	// 	if(k % 8 == 7) {
	// 		cout<<endl;
	// 	}
	// }
	// cout << plainText << endl;
	// for(int j = 0; j < 64; j++) {
	// 		binaryPlainText.push_back(testing[j]);
	// 	}
	// for(int k = 0; k < binaryPlainText.size(); k++) {
	// 	cout << binaryPlainText[k];
	// 	if(k % 8 == 7) {
	// 		cout<<endl;
	// 	}
	// }
	// 	cout<<endl;
	//end dbug
}

void Block::pushToBPT(int w, int x, int y, int z) {
	binaryPlainText.push_back(w);
	binaryPlainText.push_back(x);
	binaryPlainText.push_back(y);
	binaryPlainText.push_back(z);
}

void Block::initialPermutation() {
	vector<int> tmp;
	for(int i = 0; i < 64; i++) {
		tmp.push_back(binaryPlainText[P[i] - 1]);
	}
	binaryPlainText = tmp;
	//debug msg
	// for(int k = 0; k < binaryPlainText.size(); k++) {
	// 	cout << binaryPlainText[k];
	// 	if(k % 8 == 7) {
	// 		cout<<endl;
	// 	}
	// }
	//end debug
}

void Block::splitLeftRight() {
	for(int i = 0; i < 32; i++) {
		L.push_back(binaryPlainText[i]);
	}
	for(int j = 32; j < 64; j++) {
		R.push_back(binaryPlainText[j]);
	}
}
























