// Find the middle element in a stack

#include <iostream>
#include <stack>

int findMiddleElement(std::stack<int>& s, int& pos, int& depth, int& middle) {
	if(s.size() == 0) {
		depth = pos;
		return 1;
	}
	
	int val = s.top();
	s.pop();
	pos = pos + 1;
	findMiddleElement(s, pos, depth, middle);
	s.push(val);
	pos = pos - 1;
		
	if(pos == depth/2) {
		middle = val;
	}
	
	return 1;
}

int main() {
	std::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	int pos = 0;
	int depth = 0;
	int middle = 0;
	findMiddleElement(s, pos, depth, middle);
	std::cout << "Middle element is: " << middle << std::endl;
}