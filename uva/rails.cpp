// Uva 514 Rails
#include <iostream>
#include <stack>

using namespace std;

const int MAX_SIZE = 1000;

int main(){
	int n = 0;
	int output[MAX_SIZE];
	int input[MAX_SIZE]; // 1, 2 ,3 ,4 ,5..
	stack<int> s;
	
	// Initialize arrays
	for(int i=0; i<MAX_SIZE; i++){
		output[i] = 0;
		input[i] = i+1;
	}

	cin >> n;
		int k=0;
		int flag = 0;
		int value = 0;
		for(int i=0; i<n; i++){
			cin >> value;
			s.push(input[k]);
			while(s.top() != value) {
				if(k >= n) {
					flag = 1;
					break;
				}
				s.push(input[k]);
				k++;
			}
			if(flag) break;
			s.pop();
		}
		cout << "s.top()" << s.top() << endl;
		if(s.empty()) cout << "Yes" << endl;
		else cout << "No" << endl;
}