#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Block {
public:
	Block(string = "hey");

private:
	vector<int> binaryPlainText;
	// int binaryPlainText[64];
	string plainText;

	void convertString();

};

#endif