// Element count
/* Design an algorithm that, given a list of n elements in an array, 
 * finds all the elements that appear more than n/3 times in the list
 */

#include <iostream>
#include <unordered_map>

	using namespace std;

int main() {
	int a[100];
	int n;
	unordered_map<int, int> hashMap;
	cin >> n;
	if(n >= 100) cout << "N too large"; return 1;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(hashMap[a[i]]) hashMap[a[i]] += 1;
		else hashMap[a[i]] = 1; 
	}
	for(unordered_map<int,int>::iterator i = hashMap.begin();
	i != hashMap.end(); i++){
		if(i->second > n/3) cout << i->first << endl;
	}
}