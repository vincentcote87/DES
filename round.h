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
	void fFuncton();
private:
	vector<int> L;
	vector<int> R;
	vector<int> expendedR;
	vector<int> F;
	// Key roundKey('testing');

};

#endif