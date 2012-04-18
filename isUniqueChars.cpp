/* Problem
*  Given a string, determine if it contains unique chars
*  Assume chars are in ASCII
*
*  Algorithm:
*  1. Use a hash table to keep track if a char has been seen before
*  2. Iterate through entire string, if a char has been seen then return 0. else return 1
*
*  Time complexity O(n)
*/

int isUniqueChars(std::string str, int len) {
	const int NUM_CHARS = 256;
	short hash[NUM_CHARS]; // initialized to 0
	
	if(len > NUM_CHARS) return 0; // cannot be unique
	
	// Iterate through the string and update Hash table
	for(int i=0; i<len; i++) {
		if(1 == hash[str[i]]) return 0; // already marked as seen
		else hash[str[i]] = 1; // first occurrence, mark as seen
	}
	return 1; // completed loop, no duplicates seen
}

int isUniqueCharsWithoutDs(std::string str, int len) {
	const int NUM_CHARS = 256;
	
	if(len > NUM_CHARS) return 0; // cannot be unique
	
	// Iterate through the string and update Hash table
	for(int i=0; i<len; i++){
		for(j=0; j<len; j++){
			if(i!=j){
				if(str[i] == str[j]) return 0; // duplicate found
			}
		}
	}
}

void main(){
	std::string unique = "abcd";
	std::string notUnique = "hello";
	
	if(isUniqueChars(unique, unique.length()))
		std::cout << unique " is unique" << std::endl;
	if(!isUniqueChars(unique, notUnique.length()))
		std::cout << notUnique " is not unique" << std::endl;	
}