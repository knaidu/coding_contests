// Given a string, find if a substring exists

bool substringExists(string& str, string& substr) {
	int m = str.size();
	int n = substr.size();

	if(m == 0 || n == 0 || m < n) 
		return FALSE;

	int j = 0;
	for(int i=0; i<m; i++) {
		int k = i;
		while(str[k].compare(substr[j]) == 0 && j < n) {
			k++; j++;
		}
		if(j == n+1) return TRUE;
		else j = 0;
	}

	return FALSE;
}