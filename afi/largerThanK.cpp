// 1.3 Find first element larger than k in a sorted array

#include <iostream>

// @returns first element larger than k, else -1
// assumes the array is sorted in increasing order
int firstLargestElement(int a[], int n, int k) {
	int low, mid, high = 0;
	high = n-1;
	while(low <= high) {
		mid = (low+high)/2;
		if(a[mid] == k && (mid == n-1 || a[mid+1] != k)) {
			if(mid == n-1) return -1;
			if(a[mid+1] > k) return a[mid+1];
		}
		else if(a[mid] <= k) low = mid + 1;
		else high = mid - 1;
	}
}

int main(){
	int n, k, a[10];
	std::cin >> n;
	for(int i=0; i<n; i++){
		std::cin >> a[i];
	}
	std::cin >> k;
	std::cout << "First element larger than " << k << " is " 
		<< firstLargestElement(a, n, k) << std::endl;
}