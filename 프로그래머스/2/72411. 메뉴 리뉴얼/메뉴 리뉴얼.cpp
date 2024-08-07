#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

unordered_map<string,int> um;
vector<string> good;

vector<string> dat[11];
int maxx[11];

void dfs(int dep,int N,int ii,string temp,int s){
    
    
    //cout<<temp<<" ";
    um[temp]++;
    if(dep==N){
        return;
    }
    
    
    for(int i=s;i<N;i++){
        
        temp+=good[ii][i];
        dfs(dep+1,N,ii,temp,i+1);
        temp.pop_back();
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    good=orders;
    for(int i=0;i<orders.size();i++){
        sort(orders[i].begin(),orders[i].end());
        good[i]=orders[i];
        dfs(0,orders[i].size(),i,"",0);

    }
    
    for(auto i=um.begin();i!=um.end();i++){
        if(i->second<=1) continue;
        
        if(maxx[(i->first).size()]<i->second){
            dat[(i->first).size()].clear();
            
            maxx[(i->first).size()]=i->second;            
            dat[(i->first).size()].push_back(i->first);
        }
        else if(maxx[(i->first).size()]==i->second){
            dat[(i->first).size()].push_back(i->first);
        }
        
    }
    vector<string> answer;
    for(int i=0;i<course.size();i++){
        for(int j=0;j<dat[course[i]].size();j++){
            answer.push_back(dat[course[i]][j]);
        }
       
    }
    sort(answer.begin(),answer.end());
    
    
    return answer;
}