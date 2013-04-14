// Given a word find all anagrams

int preprocess(vector<string>& dictionary, map<string, vector<string>>& anagrams) {

	if(dictionary.size() == 0) reutrn FALSE;
	anagrams.clear();

	map<string, vector<string>>::iterator aIter;

	for(int i=0; i<dictionary.size(); i++) {
		string sortedWord = sortString(dictionary[i]);
		aIter = anagrams.find(sortedWord);
		// Found word, get the list in anagrams and append
		if(aIter != anagrams.end()) {
			vector<string>& l = aIter->second;
			l.push_back(dictionary[i]);
		}
		// New word
		else {
			list<string> l;
			l.push_back(dictionary[i]);
			anagrams.insert(make_pair<sortedWord, l>);
		}
	}
	return SUCCESS;
}

vector<string> findAllAnagrams(map<string, vector<string>>& anagrams, string word) {

	if(word == NULL) return FALSE;

	string sortedWord = sortString(word);

	map<string, list>::iterator aIter;
	aIter = anagrams.find(sortedWord);
	if(aIter != anagrams.end())
		return aIter->second;
	else
		return NULL;
}
