// Use a coin to simulate a dice
// Problem: Given a coin that has 2 outcomes heads and tails, simulate a 6 sided dice

#include <cstdlib>

int simulateDice() {
	// Roll dice 3 times
	string result += rand() % 2;
	result += rand() % 2;
	result += rand() % 2;

	if(result.compare("000") == 0) {
		return 1;
	}
	else if(result.compare("001") == 0) {
		return 2;
	}
	else if(result.compare("010") == 0) {
		return 3;
	}
	else if(result.compare("011") == 0) {
		return 4;
	}
	else if(result.compare("100") == 0) {
		return 5;
	}
	else if(result.compare("101") == 0) {
		return 6;
	}
	// For any other results repeat the experiment
	else return simulateDice();
}

int main () {
	cout << "Dice value = " << simulateDice() << endl;
}
