// Population problem

string printCountry(vector<string, int> population) {

	vector<int> numberLine;
	numberLine.clear();

	int n = population.size();
	if(n <= 0) return "INVALID";
	
	// 1. Create a cumulative list of country/population
	int sum = 0;
	for(int i=0; i<n; i++) {
		numberLine.push_back(sum);
		sum += population[i]->second;
	}
	numberLine.push_back(sum);

	// 2. Generate random number and do binary search in numberLine
	int r = rand() % sum;

	int low = 0; 
	int high = n;
	int mid = 0;
	while(low < high) {
		mid = (low + high) / 2;
		if(r < numberLine[mid] && r > numberLine[mid -1]) {
			return population[mid-1];
		}
		else if(r > numberLine[mid] && r < numberLine[mid] + 1) {
			return population[mid+1];
		}
		else if(r == numberLine[mid]) {
			return population[mid];
		}
		else {
			if(r < population[mid]) high = mid - 1;
			else if (r > population[mid]) low = mid + 1;
		}
	}
}