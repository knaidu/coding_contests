/*
 * majorityFind.cpp
 *
 *  Created on: Jul 23, 2012
 *      Author: karthiknaidudj
 *
 *  Problem: From a sequence of words, you know a priori that more than half
 *  the words are repetitions of a single word W, but he positions where W
 *  occurs are unknown. Design an algorithm that reads this stream only once
 *  and uses a constant amount of memory to identify W.
 */

#include <iostream>
using namespace std;

int majorityFind(int a[], int n) {
	int count = 1;
	int majorityCandidate = a[0];
	for(int i=1; i<n; i++) {
		if(majorityCandidate == a[i]) count ++;
		else if(count != 0) count --;
		else {
			majorityCandidate = a[i];
			count = 1;
		}
	}
	return majorityCandidate8;
}

int main() {
	int a[10];
	int n=0;
	cout << "Enter num of elements " << endl;
	cin >> n;
	cout << "Enter elements :" << endl;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << "Majority element is: " << majorityFind(a, n) << endl;
}
