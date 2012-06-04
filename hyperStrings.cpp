#include <iostream>
#include <tr1/unordered_map>
#include <queue>
#include <cstring>
#include <string>

int isSuperString(std::string str){
    int found=str.find_first_not_of("abcdefghij");
    
    if (found!=std::string::npos) {        
        return 0;
    }

    for(int i=0; i<str.size()-1; i++){
        if(strcmp(&str[i], &str[i+1]) > 0) {
            //std::cout << "Eliminating bad input" << str << std::endl;
            return 0;
        }
    }
    return 1;
}


int main(){
    // read input from cmd line
    int m, n = 0;
    std::vector<std::string> superStrings;
    std::tr1::unordered_map<std::string, int> hyperStrings;
    std::queue<std::string> tempQueue;
    
    std::cin >> n >> m ;

    // validate n, m
    if(n > 100 || m > 100 ) return -1;

    for(int i=0; i<n; i++){
        std::string str;
        std::cin >> str;
        if(isSuperString(str))
            superStrings.push_back(str);
    }        

    // generate hyper strings
    int count = 0;
    int queueSize = 0;
    tempQueue.push("");
    while(!tempQueue.empty()){
        std::string str = tempQueue.front();        
        tempQueue.pop();
        hyperStrings[str] = 1;
        count ++;
        //std::cout << "count: " << count << std::endl;
        if(str.size() <= m) {
         for(std::vector<std::string>::iterator i=superStrings.begin();
            i != superStrings.end() ; i++){

            std::string front, back;

            // append to front of existing string
            front = str + (*i);
            //std::cout << "front: " << front << std::endl;
            if(front.size() <= m) {
                if(hyperStrings.find(front) == hyperStrings.end())
                tempQueue.push(front);
            }

            // append to back of existing string
            back = (*i) + str;
            //std::cout << "back: " << back << std::endl;
            if(back.size() <= m){
                if(hyperStrings.find(back) == hyperStrings.end())
                tempQueue.push(back);
            }
         }
        }
    }

    //std::cout << "count: " << count << std::endl;
    std::cout << (hyperStrings.size()+queueSize) % 1000000007 << std::endl;        
}