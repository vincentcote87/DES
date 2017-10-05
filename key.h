#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Key {
public:
	Key(string);
private:
	string keyString;
	vector<int> k;
	vector<int> C;
	vector<int> D;
	// vector<int> Kn; // 16 Keys
	int Kn[16][48];
	
	void convertToBinary();
	void pushToK(int, int, int, int);
	void permutateKey();
	void shiftKey();
	void generateKeys();
};

#endif