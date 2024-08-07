#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

unordered_map<string,pair<int,int>> um;


pair<int,int> dfs(string str){ //성공여부, 1인지
    
   
    
    if(str.size()==1){
        if(str[0]=='0'){
            return {1,0};
        }
        else{
            return {1,1};
        }
    }
    
    pair<int,int> a=dfs(str.substr(0,str.size()/2));
    pair<int,int> b=dfs(str.substr(str.size()/2+1,str.size()));
    
    if(a.first==1 && b.first==1){
        
        if(str[str.size()/2]=='1'){
            um[str]={1,1};
            return {1,1};
        }
        else if(str[str.size()/2]=='0' && (a.second==1 || b.second==1)){
            um[str]={0,0};
            return {0,0};
        }
        else{
            um[str]={1,0};
            return {1,0};
        }
    }
    else{
        
        um[str]={0,0};
        return {0,0};  
        
    }
    
    
    
}

vector<int> solution(vector<long long> numbers) {
   vector<int> answer;
    
    for(int i=0;i<numbers.size();i++){
        string temp="";
        int cnt=0;
        while(1){
            if(numbers[i]==0) break;
            char a=numbers[i]%2+'0';
            temp+=a;
            numbers[i]=numbers[i]/2;
            cnt++;
        }
        int b=1;
        
        while(1){
            b=b<<1;
            if(cnt<=b-1) break; 
        }
        
        for(int i=0;i<b-cnt-1;i++){
            temp+='0';
        }
        
        //cout<<temp<<" ";
        
        if(dfs(temp).first==1){
            answer.push_back(1);
        }
        else{
            answer.push_back(0);
        }
    }
    
    
    
    
    return answer;
}