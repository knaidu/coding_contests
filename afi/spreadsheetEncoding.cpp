/*
 * spreadsheetEncoding.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: karthiknaidudj
 */

#include <iostream>
#include <string>

using namespace std;

// RETURN CODES
const int INVALID_INPUT = -1;
const int SUCCESS       = 1;

/*
 * Converts column number to column string
 * Example 27 -> AA
 * Returns 1 for success else failure code
 */
int colNumToName(int num, string& result){
	if(num <= 0) return INVALID_INPUT;
	const int MAX_ALPHABETS = 26;

	result = "";
	while(num > 0) {
		cout << "num: " << num << endl;
		// Special case for Z
		if(num % MAX_ALPHABETS == 0) {
			result += 'Z';
			if(num/MAX_ALPHABETS == 1) break;
		}
		else
			result += num % MAX_ALPHABETS + 'A' - 1;

		num = num / MAX_ALPHABETS;

	}
	cout << "Result: " << result << endl;
	return SUCCESS;
}

/*
 * Converts column string to number
 * Example: AA -> 27
 * Returns 1 for success else failure code
 */
int colNameToNum(string& colName, int& num){
	if(colName == "") return INVALID_INPUT;

	num = 0;

	for(int i=0; i<colName.length(); i++) {
		if(colName[i] < 'A') return INVALID_INPUT;
		num = num * 26 + colName[i] - 'A' + 1;
	}
	cout << "Num: " << num << endl;
	return SUCCESS;
}

int main(){
	int num;
	string name;
	cout << "Enter Number: " << endl;
	cin >> num;
	if(colNumToName(num, name)){
		cout << "colNumToName() success" << endl;
	}

	cout << "Enter Name: " << endl;
	cin >> name;
	if(colNameToNum(name, num)) {
		cout << "colNameToNum() success" << endl;
	}
	return 0;
}


