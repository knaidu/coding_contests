// Design an cache with the following eviction policy
// 1. Time to live
// 2. LRU
// Solution: 
// 1. Use hash table for lookups
// 2. For the eviction policy use a linked list for TTL
// 3. For secondary eviction policy use another linked list for LRU

class Node {
	Node next;
	Node prev;
	int timestamp;
}

class listNode {
	Node ttlPtr;
	Node lruPtr;
	int value;
}

class Cache {
	private:
		unordered_map<int, listNode> map;
		List<Node> ttl;
		List<Node> LRU;
		const int ttl = 100;

	public:
		int get(int key);
		void set(int key, value);
}

int Cache::get(int key) {
	unordered_map<int, int>::iterator iter;
	iter = map.find(key);
	if(iter == map.end())
		return FALSE;
	else {
		moveToFront(iter->second.lruPtr);
		return iter->second.value();
	}
}

void Cache::set(int key, int value) {
	
	if(map.size() != MAX) {
		map.insert(mape_pair<key, value>);
		return;
	}

	// Evict based on ttl
	Node t = ttl.last();
	if(t.timestamp - time.current() > 100)
		ttl.remove(list.last());
	// Evict based on LRU
	else {
		lru.remove(lru.last());
	}

}