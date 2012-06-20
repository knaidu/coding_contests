// Uva 673 Parantheses balance
#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n = 0;
	stack<char> s;
	cin >> n;
	for(int j=0;j <n; j++){
		string line;
		int flag = 0;
		cin >> line;
		for(int i=0; i<line.length(); i++){
			switch(line[i]){
				case '(':
					//cout << "Found (, push into stack" << endl;
					s.push(line[i]);
					break;
				case '[':
					//cout << "Found [, push into stack" << endl;
					s.push(line[i]);
					break;
				case ')':
					//cout << "Found ), compare and pop" << endl;
					if(s.size() == 0) {
						flag = 1;
						break;
					}
					if(s.top() == '(')
						s.pop();
					else 
						flag = 1;
					break;
				case ']':
					//cout << "Found ], compare and pop" << endl;
					if(s.size() == 0) {
						flag = 1;
						break;
					}
					if(s.top() == '[')
						s.pop();
					else 
						flag = 1;
					break;
				default: 
					//cout << "Found something invalid, BREAKOUT" << endl;
					flag = 1;
					break;
			} // end switch
		}// end for
		//cout << "s.size():" << s.size() << endl;
		if(flag) cout << "No" << endl;
		else if(s.size() == 0) cout << "Yes" << endl;
	}
}