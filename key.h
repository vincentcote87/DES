#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Key {
public:
	Key(string);
	void getKey(int, int[48]); // Pass int array to contain the key
private:
	string keyString;
	vector<int> k;
	vector<int> C;
	vector<int> D;
	int Kn[16][48]; // Kn 1 through 16

	void convertToBinary();
	void pushToK(int, int, int, int);
	void permutateKey();
	void shiftKey();
	void generateKeys();
};

#endif