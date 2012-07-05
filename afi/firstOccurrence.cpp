// 1.2 Find first occurrence of k in a sorted array

#include <iostream>

int firstOccurrence(int a[], int n, int k){
	int low, mid, high = 0;
	high = n-1;
	while(low <= high){
		mid = (low + high)/2;
		if(a[mid] == k && (mid == 0 || a[mid-1] != k)) {
			return mid;
		}
		else if(a[mid] < k) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return mid;
}

int main(){
	int n, k = 0;
	int a[10];
	std::cin >> n;
	for(int i=0; i<n; i++){
		std::cin >> a[i];
	}
	std::cin >> k;
	std::cout << "First occurrence of " << k << " is at " 
		<< firstOccurrence(a, n, k);
}