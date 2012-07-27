/*
 * majorityFindK.cpp
 *
 *  Created on: Jul 26, 2012
 *      Author: karthiknaidudj
 *
 *  Given a sequence of integers find all elements that occur more than n/k
 *  times.
 */

#include <iostream>
#include <tr1/unordered_map>

using namespace std;
using namespace std::tr1;

int majorityFindK(int a[], int n, int k){
	unordered_map<int, int> hash;
	unordered_map<int, int>::iterator it;

	hash.clear();

	// Parse through input stream
	for(int i=0; i<n; i++){
		it = hash.find(a[i]);
		if(it != hash.end()) { // found, increment
			it->second += 1;
		}
		else { // not found, insert element
			hash.insert(make_pair<int, int>(a[i], 1));
			if(hash.size == k) { // eliminate k distinct elements
				for(unordered_map<int, int>::iterator iter = hash.begin();
						iter!=hash.end(); iter++){
					if(iter->second > 1) iter->second -=1;
					else hash.erase(iter);
				}
			}
		}
	}

	// Now parse through the array second time and verify the elements that remain
	for(int i=0; i<n; i++){
		it = hash.find(a[i]);
		if(it != hash.end()) {
			it->second += 1;
		}
	}

	// Print the elements greater than n/k
	for(it = hash.begin(); it != hash.end(); it++){
		if(it->second-1 > n/k) std::cout << it->first;
	}

	return 1;
}




