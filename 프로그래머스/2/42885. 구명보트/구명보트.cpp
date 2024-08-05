#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;

int cmp(int a,int b){
    
    return a>b;
}

int solution(vector<int> people, int limit) {
    int i=0;
    int j=people.size()-1;
    
    sort(people.begin(),people.end(),cmp);
    
    int cnt=0;
    
    while(1){
        if(i>j) break;
        
        if(people[i]+people[j]>limit){
            i++;
        }
        else if(people[i]+people[j]<=limit){
            i++;
            j--;
        }
        cnt++;
    }
    
    
    //int answer = 0;
    return cnt;
}