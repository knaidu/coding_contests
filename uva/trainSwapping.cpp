// UVa 299 - Train Swapping

#include <iostream>

using namespace std;
const int MAX_LEN = 50;

int bubbleSort(int a[], int n){
	int count = 0;
	for(int i=0; i < n; i++) {
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]) {
				//cout << "Swapping " << a[j] << " and " << a[j+1] << endl;
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				count += 1;
			}
		}
	}
	return count;
}

int main(){
	int numCases = 0;
	
	cin >> numCases;
	
	for(int j=0; j<numCases; j++) {
		int a[MAX_LEN];
		int len = 0;
		cin >> len;
		for(int i=0; i< len; i++){
			cin >> a[i];
		}
	
		int count = bubbleSort(a, len);
		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}
}

