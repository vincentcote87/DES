#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <vector>
#include <iomanip>
#include "block.h"
#include "round.h"
#include "key.h"
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

string convertToHex(string);

int main(void) {

	string k1 = "0E329232EA6D0D73";
	string k2 = "0E3292323A6D0A73";
	string k3 = "0E310232EA6D0D3B";

	int n = 61;
  std::cout << std::dec << n << '\n';
  std::cout << std::hex << n << '\n';
  std::cout << std::oct << n << '\n';
	// Encrypt a("596F7572206C6970", k1);
	// string aa = a.getEncrypted();
	// Decrypt b(aa, k2);
	// string bb = b.getDecrypted();
	// Encrypt c(bb, k3);
	// string cc = c.getEncrypted();

	// cout<<cc<<endl;

	// Decrypt d(cc, k3);
	// string dd = d.getDecrypted();
	// Encrypt e(dd, k2);
	// string ee = e.getEncrypted();
	// Decrypt f(ee, k1);
	// string ff = f.getDecrypted();

	// cout<<ff<<endl;
	
	// cout<<convertToHex("testing.txt")<<endl;

	Encrypt plainText("8787878787878787", k1);
	cout<<plainText.getEncrypted()<<endl;
	Decrypt cypherText(plainText.getEncrypted(), k1);
	cout<<cypherText.getDecrypted()<<endl;

	return 0;
}


string convertToHex(string file) {
	ifstream t(file);
	string str;
	string hexStr = "";
	vector<int> binary;
	int tmp;
	int hex;

	t.seekg(0, ios::end);   
	str.reserve(t.tellg());
	t.seekg(0, ios::beg);

	str.assign((istreambuf_iterator<char>(t)), istreambuf_iterator<char>());

	for(int i = 0; i < str.length(); i++) {
		tmp = str[i];
		int tmpBlock[8];
		for(int j = 7; j >= 0; j--) {
			tmpBlock[j] = tmp % 2;
			tmp = tmp / 2;
		}
		for(int j = 0; j < 8; j++) {
			binary.push_back(tmpBlock[j]);
		}
	}
	cout<<binary.size()<<endl;
	while(binary.size() % 64 != 0){
		binary.push_back(0);
	}
	for(int i = 0; i < binary.size(); i++) {
		hex += binary[0] * 8;
		if( i % 4 == 1) {
			hex += binary[i] * 4;
		} else if( i % 4 == 2) {
			hex += binary[i] * 2;
		} else if( i % 4 == 3) {
			hex += binary[i] * 1;
		} if(i % 4 == 0 && i != 0) {
			switch(hex) {
				case 0: hexStr = hexStr + '0'; hex = 0; break;
				case 1: hexStr = hexStr + '1'; hex = 0; break;
				case 2: hexStr = hexStr + '2'; hex = 0; break;
				case 3: hexStr = hexStr + '3'; hex = 0; break;
				case 4: hexStr = hexStr + '4'; hex = 0; break;
				case 5: hexStr = hexStr + '5'; hex = 0; break;
				case 6: hexStr = hexStr + '6'; hex = 0; break;
				case 7: hexStr = hexStr + '7'; hex = 0; break;
				case 8: hexStr = hexStr + '8'; hex = 0; break;
				case 9: hexStr = hexStr + '9'; hex = 0; break;
				case 10: hexStr = hexStr + 'A'; hex = 0; break;
				case 11: hexStr = hexStr + 'B'; hex = 0; break;
				case 12: hexStr = hexStr + 'C'; hex = 0; break;
				case 13: hexStr = hexStr + 'D'; hex = 0; break;
				case 14: hexStr = hexStr + 'E'; hex = 0; break;
				case 15: hexStr = hexStr + 'F'; hex = 0; break;
				default : cout<<"Should never see this"<<endl;
			}
			hex += binary[i] * 8;
		}
	}
	return hexStr;
}




