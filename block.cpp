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

Block::Block(string str) {
	plainText = str;
	convertString();
	initialPermutation();
}

void Block::convertString() {
	int tmp;

	for(int i = 0; i < plainText.length(); i++) {
		tmp = plainText[i];
		int tmpBlock[8];
		for(int j = 7; j >= 0; j--) {
			tmpBlock[j] = tmp % 2;
			tmp = tmp / 2;
		}
		for(int j = 0; j < 8; j++) {
			binaryPlainText.push_back(tmpBlock[j]);
		}
	}
	//debug msg
	for(int k = 0; k < binaryPlainText.size(); k++) {
		cout << binaryPlainText[k];
		if(k % 8 == 7) {
			cout<<endl;
		}
	}
	cout << plainText << endl;
	//end dbug
}

void Block::initialPermutation() {
	vector<int> tmp;
	for(int i = 0; i < 64; i++) {
		tmp.push_back(binaryPlainText[P[i] + 1]);
	}
	binaryPlainText = tmp;
	//debug msg
	for(int k = 0; k < binaryPlainText.size(); k++) {
		cout << binaryPlainText[k];
		if(k % 8 == 7) {
			cout<<endl;
		}
	}
	//end debug
}