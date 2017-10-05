#include <iostream>
#include <string>
#include <vector>
#include "round.h"
#include "key.h"

using namespace std;

const int E[] = {
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1
};

Round::Round(vector<int> left, vector<int> right, int k[48]) {
	L = left;
	R = right;
	expansion();
}

void Round::expansion() {
	for(int i = 0; i < 48; i++) {
		expendedR.push_back(R[E[i] - 1]);
		cout<<expendedR[i];
	} 
	cout<<endl;
}

void fFuncton() {
	for(int i = 0; i < 48; i++) {
		//implement XOR between expendedR and k
	}
}