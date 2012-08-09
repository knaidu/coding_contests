/*
 * matrixSearch.cpp
 *
 *  Created on: Jul 30, 2012
 *      Author: karthiknaidudj
 *
 *  Problem: Given a matrix in row and column increasing order, find an element in it
 */

#include <iostream>

// Returns 1-found or 0-not found
int matrixSearch(int a[3][3], int m, int n, int key) {
	// Start from top right of matrix
	int i=0;
	int j=m;
	while(i<n && j<0) {
		if(a[i][j] == key) return 1;
		else if(a[i][j] > key) j--; // go left
		else i++; // go down
	}
	return 0; // not found
}

int main(){
	int a[3][3] = {1, 2, 3, 4, 5, 6, 7 ,8 ,9};
	if(matrixSearch(a, 3, 3, 4))
		std::cout << "Element found !" << std::endl;
	else
		std::cout << "ELement not found" << std::endl;
}




