#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <long long,long long> m;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    for(int i=0;i<weights.size();i++){
        m[weights[i]]++;
    }
    
    for(auto i=m.begin();i!=m.end();i++){
        
        answer=answer+ (i->second)*((i->second)-1)/2;
        
        if((i->first)%2==0){
            
            if(m.find((i->first/2)*3)!=m.end()){
                answer+= i->second*m[(i->first/2)*3];
            }
            
        }
        
        if((i->first)%3==0){
            
            if(m.find((i->first/3)*4)!=m.end()){
                answer+= i->second*m[(i->first/3)*4];
            }
            
        }
        
        if(m.find(i->first*2)!=m.end()){
            answer+= i->second*m[(i->first*2)];
        }
        //cout<<i->first<<" "<<answer<<"\n";
        
    }
    
    
    return answer;
}