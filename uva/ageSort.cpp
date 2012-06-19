#include <iostream>

using namespace std;
const int MAX_SIZE = 100;

int main(){
	int n = 0;
	int num = 0;
	
	cin >> n;
	while(n != 0) {
		int a[MAX_SIZE];
		for(int i=0;i<MAX_SIZE;i++){
			a[i]=0;
		}
		
		// Read input and count
		for(int i=0; i<n; i++){
			cin >> num;
			a[num] += 1;
		}
		
		// Print sorted output
		for(int i=0; i<MAX_SIZE; i++){
			for(int j=0; j<a[i]; j++)
				cout << i << " ";
		}
		cout << endl;
		cin >> n;
	}
}