// UVa 10258 - Contest Scoreboard

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_PROBLEMS = 100;

class Contestant {
public:
	int number;
	int problemsSolved;
	int penalty;
	bool problems[MAX_PROBLEMS];
	Contestant();
	void solveProblem(int, int);
	bool operator < (Contestant) const;
};

Contestant::Contestant(){
	number = 0;
	problemsSolved = 0;
	penalty = 0;
	for(int i=0; i < MAX_PROBLEMS; i++){
		problems[i] = false;
	}
}

void Contestant::solveProblem(int problemNumber, int time){
	if(!problems[problemNumber]) {
		problems[problemNumber] = true;
		problemsSolved += 1;
		penalty += time;
	}
}

bool Contestant::operator < (Contestant c) const {
	bool isLesser = false;
	if(problemsSolved < c.problemsSolved) isLesser = true;
	else if(problemsSolved == c.problemsSolved) {
		if(penalty < c.penalty) isLesser = true;
		else if(penalty == c.penalty) {
			if(number < c.number) isLesser = true;
		}
	}
	return isLesser;
}

int main(){ 
	int numCases = 0;
	int cid, pid, time = 0;
	char result;
	map<int, Contestant> contestantMap;
	cin >> numCases;
	
	for(int i=0; i<numCases; i++){
		// Read values
		cin >> cid >> pid >> time >> result; 
		Contestant c;
		if(contestantMap.find(cid) == contestantMap.end()) {
			c.number = cid;
			contestantMap[cid] = c;
		}
		else {
			c = contestantMap[cid];
		}
		switch(result) {
			case 'I':
				c.penalty += 20;
				break;
			case 'C':
				c.solveProblem(pid, time);
				break;
			default:
				break;
		}
	}
	
	sort(contestantMap.begin(), contestantMap.end());
}