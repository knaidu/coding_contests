#include <iostream>

using namespace std;

int main(){
	int numTestCases = 0;
	int numIntegers = 0;
	int array[100000];
	
	cin >> numTestCases;
	while(numTestCases > 0) {
		cin >> numIntegers;
		for(int i=0; i<numIntegers; i++){
			cin >> a[i];
		}
		insertionSort(a, numIntegers);
	}
}