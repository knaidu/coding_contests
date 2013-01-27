/*
 * binomial_coeff.cpp
 *
 *  Created on: Oct 27, 2012
 *      Author: karthiknaidudj
 */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

unsigned long long binomial_coeff(int n, int k) {
	const int MAXN = 1000000000;

	if(k <= 0) return 1;

	unsigned long long table[1000][1000];

	for(int i=0; i<=n; i++) table[i][0] = 1;

	for(int j=0; j<=n; j++) table[j][j] = 1;

	for (int i=1; i<=n; i++){
		for(int j=1; j<=min(i,k); j++){
			table[i][j] = table[i-1][j-1] + table[i-1][j];
		}
	}
	return table[n][k];
}

int main() {

	int numLines = 0;
	cin >> numLines;
	if(numLines <= 0 || numLines >= 100000) return 0;
	for(int i=0; i<numLines; i++) {
		int n = 0;
		int k = 0;
		cin >> n >> k;
		unsigned long long result = binomial_coeff(n,k);
		cout << result << " -- ";
		result = result % 142857;
		cout << result << std::endl;
	}
}



