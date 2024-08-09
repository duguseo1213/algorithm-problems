#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct cmp{
    
    bool operator()(pair<int,int> a,pair<int,int> b){
        
        if(a.second==b.second){
            return a.first>b.first;    
        }
        
        return a.second>b.second;
        
    }
    
    
};

priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq; 

int solution(vector<vector<int>> routes) {
    int answer = 0;
    for(int i=0;i<routes.size();i++){
        
        pq.push({routes[i][0],routes[i][1]});
        
    }
    int loc=pq.top().second;
    pq.pop();
    int cnt=0;
    cnt++;
    while(!pq.empty()){
        
        if(pq.top().first<= loc && loc<=pq.top().second){
            pq.pop();
        }
        else{
            cnt++;
            loc=pq.top().second;
            pq.pop();
        }
    }
    
   
    
    
    
    return cnt;
}