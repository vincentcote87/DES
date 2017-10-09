#include <iostream>
#include <fstream>
#include <string>
#include <streambuf>
#include <sstream>
#include <vector>
#include <iomanip>
#include "block.h"
#include "round.h"
#include "key.h"
#include "encrypt.h"
#include "decrypt.h"

using namespace std;

string getStringFromFile(string);
string convertToHex(string);
string convertToString(string);

int main(void) {

	string k1 = "0E329232EA6D0D73";
	string k2 = "0E339632EB6D0D73";
	string k3 = "0E329332AA6D0D73";

	string m = getStringFromFile("testing.txt");

	m = convertToHex(m);
	m = getStringFromFile("temp.txt");

	Encrypt a(m, k1);
	string aa = a.getEncrypted();
	Decrypt b(aa, k2);
	string bb = b.getDecrypted();
	Encrypt c(bb, k3);
	string cc = c.getEncrypted();

	Decrypt d(cc, k3);
	string dd = d.getDecrypted();
	Encrypt e(dd, k2);
	string ee = e.getEncrypted();
	Decrypt f(ee, k1);
	string ff = f.getDecrypted();

	cout<<convertToString(ff)<<endl;
	
	// cout<<convertToHex("testing.txt")<<endl;
  	
	// Encrypt plainText(m, k2);
	// cout<<plainText.getEncrypted()<<endl;
	// Decrypt cypherText(plainText.getEncrypted(), k2);
	// cout<<cypherText.getDecrypted()<<endl;
	// string cc = cypherText.getDecrypted();

	// cout<<cc<<endl;
	// cout<<convertToString(cypherText.getDecrypted())<<endl;

	return 0;
}


string getStringFromFile(string file) {
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

	return str;
}

string convertToHex(string str) {
	int tmp;
	ofstream outFile("temp.txt");
	for(int i = 0; i < str.length(); i++) {
		tmp = str.at(i);
		if(tmp >=0 && tmp <= 17)
			outFile << 0;
		outFile << hex << tmp;
	}
	return str;
}

string convertToString(string str) {
	int tmp;
	int x, y, z;
	char ch;
	string outStr;
	for(int i = 0; i < str.length(); i++){
		tmp = str.at(i);
		if(i % 2 == 0 && i != 0) {
			ch = (x * 16) + y;
			outStr += ch;
		}
		if(i % 2 == 0) {
			if(tmp >= '0' && tmp <= '9') {
				x = tmp - 48;
			}
			else {
				x = tmp - 55;
			}
		} else if(i % 2 == 1) {
			if(tmp >= '0' && tmp <= '9') {
				y = tmp - 48;
			}
			else {
				y = tmp - 55;
			}
		} 
		// if(str.length() - 1 == i) {
		// 	ch = (x * 16) + y;
		// 	outStr += ch;
		// }
	}
	return outStr;
}

