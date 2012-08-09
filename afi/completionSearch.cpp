/*
 * completionSearch.cpp
 *
 *  Created on: Aug 9, 2012
 *      Author: karthiknaidudj
 *
 *  Problem: Given a set {s1, s2, ... sN}, and Sum'=X. Find a cap q, such that
 *  elements in S now sum up to S'. If a value is less than q, it stays the same,
 *  if its greater than q then it gets capped at q.
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int completionSearch(int a[], int n, int sNew){
	vector<int> sortedValues(a, a+n);
	sort(sortedValues.begin(), sortedValues.end());
	int q = sortedValues[n/2]; // set q to be the middle element
	cout << "Chosen q = " << q << endl;
	int sum = 0;
	int tempSum = 0;
	for(int i=0; i<n; i++){
		sum = sum + sortedValues[i];
		if(i < n/2) continue;
		tempSum = tempSum + sortedValues[i] -q;
		cout << "temp sum = " << tempSum << endl;
	}
	int diff = sum - sNew;
	cout << "diff = " << diff << ", tempSum = " << tempSum << endl;
	if(tempSum == diff) {
		cout << "tempSum is same as diff" << endl;
		return q;
	}
	if(diff - tempSum >= q)
		q = q + ((tempSum-diff)/((n/2)+1));
	else
		q = q + ((tempSum-diff)/(n/2));
	cout << "calculating q" << endl;
	return q;
}

int main(){
	const int SIZE= 5;
	int a[SIZE] = {30, 90, 100, 20, 80};
	int sNew = 210;
	int q = 0;
	cout << "q = " << completionSearch(a, SIZE, sNew) << endl;
}




