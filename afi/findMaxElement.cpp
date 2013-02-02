/*
 * findElement.cpp: Given an array that is first increasing then decreasing
 *                  find the max element
 *
 *  Created on: Feb 2, 2013
 *      Author: karthiknaidudj
 */

#include <iostream>
#include <vector>

using namespace std;

const int SUCCESS = 1;
const int INVALID_INPUT = -1;
const int FAILURE = 0;

/*
 * Returns 1 - success, else failure code
 * Max element is returned as last arg- &maxElement
 */
int findMaxElement(vector<int>& a, int n, int& maxElement) {
	if(n <3) return INVALID_INPUT;

	int low, mid, high;
	low = 0;
	high = n;
	mid = (low + high)/2;

	while(low < high) {
		cout << "mid:" << mid << endl;
		if(a[mid-1] < a[mid] && a[mid] < a[mid+1]) { // increasing order
			low = mid;
		}
		else if(a[mid-1] > a[mid] && a[mid] > a[mid+1]) { // decreasing order
			high = mid;
		}
		else if(a[mid -1] < a[mid] && a[mid > a[mid + 1]])
		{ // found max
			maxElement = a[mid];
			cout << "Max element is: " << maxElement << endl;
			return SUCCESS;
		}
		mid = (low + high)/2;
	}

	return FAILURE;
}

int main() {
	int n, temp, max;
	vector<int> a;
	cout << "Enter num elements:" << endl;
	cin >> n;
	cout << "Enter the elements: " << endl;
	for(int i=0; i<n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	if(findMaxElement(a, n, max) == SUCCESS) {
		cout << "Success" << endl;
	}
	else cout << "Failure" << endl;
}


