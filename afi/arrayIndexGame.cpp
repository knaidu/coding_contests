/*
 * Given an array containing only positive values and 0, given starting index, play this game where if 
 * you hit a zero you win, else you can jump left or right value positions. If you never hit a zero but 
 * have explored all possibilities then you lose too.
*/

bool playGame(vector<int> a, vector<int>& visited, int &index) {
	
	visited[index] = 1;

	// Validate 

	if(visited[index]) return false;
	if(a[index] == 0) return TRUE;
	bool leftRetVal = playGame(a, visited, index + a[index]);
	bool rightRetVal = playGame(a, visited, index - a[index]);
	return (leftRetVal || rightRetVal);
}

int main() {
	vector<int> a;
	vector<int> visited;
	visited.clear();
}