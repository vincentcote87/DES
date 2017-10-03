#include <iostream>
#include <string>
#include <vector>
#include "block.h"

using namespace std;

Block::Block(string str) {
	cout<<"In constructor"<<endl;
	plainText = str;
	convertString();
}

void Block::convertString() {
	int tmp;

	for(int i = 0; i < plainText.length(); i++) {
		tmp = plainText[i];
		int tmpBlock[8];
		for(int j = 7; j >= 0; j--) {
			tmpBlock[j] = tmp % 2;
			// binaryPlainText.push_back(tmp % 2);
			tmp = tmp / 2;
		}
		for(int j = 0; j < 8; j++) {
			binaryPlainText.push_back(tmpBlock[j]);
		}
	}
	for(int k = 0; k < binaryPlainText.size(); k++) {
		cout << binaryPlainText[k];
		if(k % 8 == 7) {
			cout<<endl;
		}
	}
	cout << plainText << endl;
}