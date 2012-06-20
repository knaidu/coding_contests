// UVa 10226 Hardwood species

#include <iostream>
#include <iomanip>
#include <string>
#include <map>

int main(){
	std::map<std::string, int> treesMap;
	int totalCount = 0;
	std::string line;
	
	getline(std::cin, line);
	while(line.compare("0") != 0) {
		if(treesMap.find(line) != treesMap.end()) // Found
		{
			//std::cout << "Found, incrementing" << std::endl;
			treesMap[line] += 1;
		}
		else {
			//std::cout << "Not found, set value to 1" << std::endl;
			treesMap[line] = 1;
		}
		totalCount++;
		//std::cout << "totalCount: " << totalCount << std::endl;
		getline(std::cin, line);
	}
	for(std::map<std::string, int>::iterator i = treesMap.begin();
	i != treesMap.end(); i++){
		double frac = ((double)i->second/totalCount)*100;
		std::cout << i->first << " " << std::setprecision(4) 
				  << frac << std::endl;
	}
}