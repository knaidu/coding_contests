#include <iostream>

int mergeSort(int a[], int left, right){
	int mid = 0;
	int invIndex = 0;
	mid = (left + right) / 2;
	if(right > left) {
		invIndex += mergeSort(a, left, mid);
		invIndex += mergeSort(a, mid+1, right);
		invIndex += merge(a, left, mid, right);
	}
	return invIndex;
}

int merge(int a[], int left, int mid, int right){
	int temp[]
	int i=left;
	int j=mid+1;;
	int k=0;
	int invIndex = 0;
	while(i<mid && j<right) {
		if(a[i] <= a[j]){
			temp[k++] = a[i]
		}
		else {
			temp[k++] = a[j];
			invIndex += mid -i;
		}
	}
	// Copy remaining elements from left array
	while(i<mid) temp[k++] = a[i++];
	
	// Copy remaining elements from right array
	while(j<right) temp[k++] = a[j++];
	
	// Copy back to original array
	for(int x=left; x<right; x++)
		a[x] = tmep[x];
	
	return invIndex;
}

int main(){
	int n;
	cin >> n;
	while(n > 0){
		n--;
		int numValues = 0;
		int i = 0;
		while(numValues > 0) {
			cin >> a[i++];
			numValues --;
		}
		std::cout << "Inversion index:" << mergeSort(a, 0, n) << std::endl;
	}
}