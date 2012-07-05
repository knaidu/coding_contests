// 1.1 Find square root of a number 

#include <iostream>

// @returns square root or -1 for invalid inputs
int squareRoot(int n){
	int low, mid, high = 0;
	if(n <= 0) return -1;
	
	low = 0;
	high = n/2;
	mid = (low + high)/2;
	while (low <= high) {
		int midSquared = mid*mid;
		if(midSquared == n) { // FOUND
			return mid;
		}
		else if(midSquared > n) {
			if(high == mid) return mid;
			high = mid;
			mid = (low + mid)/2;
		}
		else if(midSquared < n) {
			if(low == mid) return mid;
			low = mid;
			mid = (mid + high)/2;
		}
	}
	return mid;
}

int main(){
	int n;
	std::cin >> n;
	std::cout << "Square root of " << n << " is " << squareRoot(n) << std::endl;
}