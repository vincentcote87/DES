#ifndef ROUND_H
#define ROUND_H

#include <iostream>
#include <string>
#include <vector>
#include "key.h"

using namespace std;

class Round {
public:
	Round(vector<int>, vector<int>, Key);
	void expansion();
private:
	vector<int> L;
	vector<int> R;
	vector<int> expendedR;
	// Key roundKey('testing');

};

#endif