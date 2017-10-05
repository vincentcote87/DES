#include <iostream>
#include <string>
#include <vector>
#include "key.h"

using namespace std;

const int PC1[] = {
	57, 49, 41, 33, 25, 17,  9,
	 1, 58, 50, 42, 34, 26, 18,
	10,  2, 59, 51, 43, 35, 27,
	19, 11,  3, 60, 52 ,44 ,36,
	63, 55, 47, 39, 31 ,23 ,15,
	 7, 62, 54, 46, 38 ,30 ,22,
	14,  6, 61, 53, 45 ,37 ,29,
	21, 13,  5, 28, 20 ,12 , 4
};

const int PC2[] = {
	14, 17, 11, 24,  1,  5,
     3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8,
    16,  7, 27, 20, 13,  2,
    41, 52, 31, 37, 47, 55,
    30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53,
    46, 42, 50, 36, 29, 32
};

Key::Key(string str) {
	keyString = str;
	convertToBinary();
	permutateKey();
	generateKeys();
}

void Key::convertToBinary() {
	char ch;
	for(int i = 0; i < 16; i++) {
		ch = keyString.at(i);

		switch(ch) {
			case '0' : pushToK(0,0,0,0); break;
			case '1' : pushToK(0,0,0,1); break;
			case '2' : pushToK(0,0,1,0); break;
			case '3' : pushToK(0,0,1,1); break;
			case '4' : pushToK(0,1,0,0); break;
			case '5' : pushToK(0,1,0,1); break;
			case '6' : pushToK(0,1,1,0); break;
			case '7' : pushToK(0,1,1,1); break;
			case '8' : pushToK(1,0,0,0); break;
			case '9' : pushToK(1,0,0,1); break;
			case 'a' : case 'A' : pushToK(1,0,1,0); break;
			case 'b' : case 'B' : pushToK(1,0,1,1); break;
			case 'c' : case 'C' : pushToK(1,1,0,0); break;
			case 'd' : case 'D' : pushToK(1,1,0,1); break;
			case 'e' : case 'E' : pushToK(1,1,1,0); break;
			case 'f' : case 'F' : pushToK(1,1,1,1); break;
			default : cout << "Critical Error" << endl;
		}
	}
}

void Key::pushToK(int w, int x, int y, int z) {
	k.push_back(w);
	k.push_back(x);
	k.push_back(y);
	k.push_back(z);
}

void Key::permutateKey() {
	vector<int> tmp;

	for(int i = 0; i < 56; i++) {
		tmp.push_back(k[PC1[i] - 1]);
	}
	for(int i = 0; i < 28; i++) {
		C.push_back(tmp[i]);
		D.push_back(tmp[i + 28]);
	}
}

void Key::shiftKey() {
	int tmpC[28];
	int tmpD[28];
	// if(singleShift) {
		tmpC[27] = C[0];
		tmpD[27] = D[0];
		for(int i = 0; i < 27; i++) {
			tmpC[i] = C[i + 1];
			tmpD[i] = D[i + 1];
		}
		for(int i = 0; i < 28; i++) {
			C[i] = tmpC[i];
			D[i] = tmpD[i];
		}
	// }
}

void Key::generateKeys() {
	// vector<int> CD;
	int CD[56];

	for(int k = 0; k < 28; k++) {
		cout<<C[k];
	}
cout<<endl;
	for(int i = 0; i < 16; i++) {
		if(i == 0 || i == 1 || i == 8 || i == 15) {
			shiftKey();
		} else {
			shiftKey();
			shiftKey();
		}
		for(int j = 0; j < 28; j++) {
			CD[j] = C[j];
			CD[j + 28] = D[j];
			// CD.push_back(C[i]);
			// cout<<C[j];
		}
		// for(int j = 0; j < 28; j++) {
		// 	CD.push_back(D[i]);
		// }
		for(int j = 0; j < 48; j++) {
			// cout<<CD[j];
			Kn[i][j] = C[PC2[j] - 1];
		}
		// cout<<endl;
	}

	for(int i = 0; i < 16; i++) {
		cout<<"Key" << i << " = ";
		for(int j = 0; j < 48; j++) {
			cout<<Kn[i][j];
		}
		cout<<endl;
	}



	// shiftKey();
	// shiftKey();
	// cout<<"C = ";
	// for(int i = 0; i < 27; i++) {
	// 		cout<<C[i];
	// 	}
	// 	cout<<endl;
	// 	cout<<"D = ";
	// 	for(int i = 0; i < 28; i++) {
	// 		cout<<D[i];
	// 	}
}











000110110000001011101111110100001110011100111000
000110110000001011101111111111000111000001110010











