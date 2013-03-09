// Run length encoding

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

const int SUCCESS = 1;
const int FAILURE = 0;

using namespace std;

// Returns 1 - success, else failure error code
int runLengthEncoding(string& input, string& output) {
	ostringstream ss;
	int n = input.size();

	if(n <= 0) return FAILURE;

	int i=0;
	int j=0;
	while(j<=n) {
		if(input[i] == input[j]) j++;
		else {
			int diff = j-i;
			ss << input[i] << diff;	
			i=j;
		}
	}
	output = ss.str();
	return SUCCESS;
}

int runLengthDecoding(string& input, string& output) {
	int n = input.size();
	if(n <= 0) return FAILURE;
	ostringstream ss;

	for(int i=0; i<n; i+=2) {
		char c = input[i];
		char x  = input[i+1];
		int num = atoi(&x);
		for(int j=0; j<num; j++) {
			ss << c;
		}
	}
	output = ss.str();
	return SUCCESS;
}

int main() {
	string input, encoded, decoded;
	cout << "Enter input string" << endl;
	cin >> input;
	if(runLengthEncoding(input, encoded) == SUCCESS)
		cout << "Encoded: " << encoded << endl;
	if(runLengthDecoding(encoded, decoded) == SUCCESS) 
		cout << "Decoded: " << decoded << endl;
}