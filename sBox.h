#ifndef SBOX_H
#define SBOX_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class SBox {
public:
	SBox();
private:
	int s1[8][4][16];

	void initSBox();

};

#endif