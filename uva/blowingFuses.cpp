#include <iostream>

using namespace std;

int main(){
	int n,m,c = -1;
	int devices[21];
	int seq = 1;
	
	while(n != 0 && m != 0 && c != 0) {
	cin >> n >> m >> c;
	if(n == 0 && m == 0 && c == 0) break;
	
	std::cout << "Sequence " << seq << std::endl;
	seq++;
	
	// intialize devices 
	for(int i=0;i<21;i++){
		devices[i]=0;
	}
	
	// Read device load
	for(int i=1;i<=n;i++){
		cin >> devices[i];
	}
	
	int operation = 0;
	int load = 0;
	int fuse = 0;
	int max = 0;
	
	// perform operations
	for(int i=1;i<=m; i++) {
		cin >> operation;
		load+= devices[operation];
		devices[operation] = -devices[operation];
		//cout << "Load: " << load << std::endl;
		if(max < load) max = load;
		if(load > c) fuse = 1;
	}
	
	if(fuse) cout << "Fuse was blown." << std::endl;
	else {
		cout << "Fuse was not blown" << endl;
		cout << "Maximal power consumption was " << max << " amperes." << endl;
    }
	cout << "\n";
   } // end while 
}