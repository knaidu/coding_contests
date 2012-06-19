#include <iostream>

int bubbleSort(std::string str, int n){
	int count = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j)
	}
}


int main(){
	int numCases = 0;
	std::string line;
	cin >> numCases;
	cin >> line;
	
	for(int i=0; i< numcases; i++){
		int len = 0;
		int n = 0;
		vector<string> dnaList;
		for(int j=0; j<n; j++){
			cin >> dnaList[j];
			int count = bubbleSort(dnaList[j], len);
			map<int, string> dnaResult;
			dnaResult.insert(count, dnaList[j]);
		}
		for(map<int,string>::iterator i=dnaResult.begin(); 
		i!= dnaResult.end(); i++){
			cout << (*i).second << endl;
		}
	}
}