#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Block {
public:
	Block(string = "hey");

	vector<int> getLeft();
	vector<int> getRight();

private:
	vector<int> binaryPlainText;
	vector<int> L;
	vector<int> R;
	string plainText;

	void convertString();
	void initialPermutation();
	void splitLeftRight();

};

#endif