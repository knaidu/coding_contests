/*
 * maxSum1D.cpp
 *
 *  Created on: Jan 27, 2013
 *      Author: karthiknaidudj
 */

#include <iostream>

using namespace std;

const int MAX = 100;

/*
 * Returns 1 - success, or failure code
 */
int maxSum1D(int a[], int n, int& maxSum, int& begin, int& end) {
	if(n <= 0) return -1;

	if(n == 1) return a[0];

	int sum = a[0];
	maxSum = a[0];
	int begin_temp = 0;


	for(int i= 1; i<n; i++) {
		sum += a[i];
		if(sum < a[i]) {
			sum = a[i];
			begin_temp = i;
		}
		if(sum > maxSum){
			maxSum = sum;
			begin = begin_temp;
			end = i;
		}
		cout << "sum: " << sum << ", maxsum = " << maxSum << endl;
	}

	return 1;
}

int main(){
	int n = 0;
	int a[MAX];
	int maxSum, begin, end = 0;

	cout << "How many numbers? " << endl;
	cin >> n;
	cout << "Enter numbers in array to calculate max sum: " << endl;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}

	if(maxSum1D(a, n, maxSum, begin, end) == 1) {
		cout << "Maxsum = " << maxSum << endl;
		cout << "Begin = " << begin << ", End = " << end << endl;
	}
	else cout << "Invalid input" << endl;

	return 0;
}
