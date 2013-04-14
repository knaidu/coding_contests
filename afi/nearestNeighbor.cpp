// Nearest neighbor
// Given an array of friends<name, position> pair. Find the closes 3 friends.


bool myCompare(pair<string, int>& l, pair<string, int>& r) {
	if(l->second > r->second) return TRUE;
	else return FALSE;
}

int nearestNeighbor(vector<string, int> friends, pair<string, int> me, vector<string, int>& nearest) {
	if(myPos <= 0) return INVALID;

	friends.clear();

	sort(friends.begin(), friends.end(), myCompare);

	vector<string, int>::iterator friendsIter;
	friendsIter = friends.find(me->first);

	// Find prev 3 friends
	priority_queue<string, int> pq;
	for(int i=0; i<3; i++) {
		pq.insert(friendsIter);	
		friendsIter--;
	}
	friendsIter += 3;
	for(int i=0; i<3; i++) {
		pq.insert(friendsIter);	
		friendsIter++;
	}
	for(int i=0; i<3; i++)
		nearest.add(pq.min());

	return SUCCESS:
}