// Rotate a 2d matrix by 90 degrees

const int INVALID_INPUT = -1;
const int SUCCESS = 1;
const int FALURE = 0;

// Returns 1 - success; else failure code
int rotate(vector<vector<int>> a, int n) {
	// Assume n is perfect square
	if(n <= 0) return INVALID_INPUT;

	for(int i=0; i<n/2; i++) {
		for(int j=i; j<n/2; j++) {
			cyclicRotate(a[i][j], a[i][n-j-1],
				a[n-i-1][n-j-1], a[n-i-1][j]);
		}
	}
	return SUCCESS;
}

void cyclicRotate(int &a, int &b, int &c, int &d) {
	int temp = 0;
	temp = a; a = b; b = c; c = d; d = temp;
}