// 1.4 Search a sorted array for A[i] = i

#include <iostream>

// @returns i if A[i] == i, else returns -1
// @assumes array is sorted, else returns 0
int searchElementEqualsIndex(int a[], int n) {
	int low, mid, high;
	low = 0;
	high = n-1;
	while(low <= high) {
		mid = (low+high)/2;
		if(a[mid] == mid) return mid;
		else if(a[mid] > mid) high = mid -1;
		else low = mid +1;
	}
	return -1;
}

int main(){
	int n, a[10];
	std::cin >> n;
	for(int i=0; i<n; i++) {
		std::cin >> a[i];
	}
	std::cout << "A[i] == i for i=" << searchElementEqualsIndex(a, n) 
		<< std::endl;
	// Test cases
	// 0 1 2, i = 1
	// 1 2 3, i = -1
	// -1 1 5, i = 1
	// 0 2 4 6 8, i=0
	// -2 -1 0 3 6, i=3
}