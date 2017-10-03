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
	string plainText;

	void convertString();
	void initialPermutation();

};

#endif