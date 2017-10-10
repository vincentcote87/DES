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

bool keyIsInvalid(string);

string getStringFromFile(string);
string convertToHex(string);
string convertToString(string);

int main(void) {
	char choice;
	bool choiceValid = false;
	bool fileIsGood = false;
	string k1, k2, k3, fileName;
	string c, m, out, outputFileName;

	cout<<endl;
	cout<<"Welcome to the Tripple DES tool."<<endl<<endl;
	cout<<"What would you like to do?"<<endl<<endl;
	cout<<"E)ncrypt"<<endl<<"D)ecrypt"<<endl<<endl;
	do{
		cout<<"Enter your option:";
		cin>>choice;
		if(choice == 'e' || choice == 'E' || choice == 'd' || choice == 'D') {
			choiceValid = true;
		} else
			cout<<"Invalid input, please enter E for encryption or D for decryption"<<endl;
	} while(!choiceValid);

	cout<<"You will now be asked to enter 3 keys, each key must be in Hexodecimal format (0 - F) and 16 characters long."<<endl;

	do{
		cout<<endl;
		cout<<"Please enter your first key: ";
		cin>>k1;
		if(keyIsInvalid(k1)) {
			cout<<"Invalid key, please try again."<<endl;
		}
	} while(keyIsInvalid(k1));

	do{
		cout<<endl;
		cout<<"Please enter your second key: ";
		cin>>k2;
		if(keyIsInvalid(k2)) {
			cout<<"Invalid key, please try again."<<endl;
		}
	} while(keyIsInvalid(k2));

	do{
		cout<<endl;
		cout<<"Please enter your third key: ";
		cin>>k3;
		if(keyIsInvalid(k3)) {
			cout<<"Invalid key, please try again."<<endl;
		}
	} while(keyIsInvalid(k3));
	
	do{
		cout<<endl;
		cout<<"Please enter the name of the file to Encrypt/Decrypt including its extension (eg. example.txt): ";
		cin>>fileName;
		ifstream inFile(fileName.c_str());
		if(inFile.good()){
			fileIsGood = true;
		}
		else{
			cout<<"File not found, try again"<<endl;
		}
	} while(!fileIsGood);

	if(choice == 'e' || choice == 'E') {
		m = getStringFromFile(fileName.c_str());
		m = convertToHex(m);
		m = getStringFromFile("temp.txt");
		remove("temp.txt");

		Encrypt aa(m, k1);
		Decrypt bb(aa.getEncrypted(), k2);
		Encrypt cc(bb.getDecrypted(), k3);

		out = cc.getEncrypted();
		cout<<"your file has been encrypted, please enter a name for your output file: ";
	} else {
		c = getStringFromFile(fileName.c_str());

		Decrypt dd(c, k3);
		Encrypt ee(dd.getDecrypted(), k2);
		Decrypt ff(ee.getEncrypted(), k1);
		
		out = convertToString(ff.getDecrypted());
		cout<<"your file has been decrypted, please enter a name for your output file: ";
	}
	cin>>outputFileName;
	outputFileName += ".txt";
	ofstream outFile(outputFileName.c_str());
	outFile<<out;

	return 0;
}

bool keyIsInvalid(string key) {
	if(key.length() != 16) {
		return true;
	}
	else {
		bool pass = true;
		for(int j = 0; j < 16; j++) {
			char ch = key[j];
			switch(ch) {
				case '0' : break;
				case '1' : break;
				case '2' : break;
				case '3' : break;
				case '4' : break;
				case '5' : break;
				case '6' : break;
				case '7' : break;
				case '8' : break;
				case '9' : break;
				case 'a' : case 'A' : break;
				case 'b' : case 'B' : break;
				case 'c' : case 'C' : break;
				case 'd' : case 'D' : break;
				case 'e' : case 'E' : break;
				case 'f' : case 'F' : break;
				default : pass = false;
			}
		}
		if(!pass) {
			return true;
		}
	}
	
	return false;
}

string getStringFromFile(string file) {
	ifstream t(file.c_str());
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
	}
	return outStr;
}

