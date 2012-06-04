#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	char id[100];
	gets(id);
	while(id[0] != '#') {
		if(next_permutation(id, id+strlen(id))) cout << id << std::endl;
		else cout << "No successor" << std::endl;
		gets(id);
	}
}