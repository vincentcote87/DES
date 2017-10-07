#ifndef ROUND_H
#define ROUND_H

#include <iostream>
#include <string>
#include <vector>
#include "key.h"

using namespace std;

class Round {
public:
	Round(vector<int>, vector<int>, int[48]);
	void expansion();
	void fFunction();
	void sBox();
	int convertToInt(int[4]);
	void finalPermutation();
private:
	vector<int> L;
	vector<int> R;
	vector<int> expendedR;
	vector<int> F;
	vector<int> key;
	vector<int> KxorER;
	vector<int> sboxValues;
	vector<int> finalF;
	// Key roundKey('testing');

};

#endif