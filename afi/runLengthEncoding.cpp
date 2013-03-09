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

int main() {
	string input, output;
	cout << "Enter input string" << endl;
	cin >> input;
	if(runLengthEncoding(input, output) == SUCCESS)
		cout << output << endl;
}