#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> um;

int dp[1000001];
int rdp[1000001];

int solution(vector<int> topping) {
    
    for(int i=0;i<topping.size();i++){
        
        um[topping[i]];
        
        dp[i]=um.size();
    }
    um.clear();
    for(int i=topping.size()-1;i>=0;i--){
        
        um[topping[i]];
        
        rdp[i]=um.size();
    }
    int answer=0;
    for(int i=0;i<topping.size()-1;i++){
        
        if(dp[i]==rdp[i+1]){
            answer++;
        }
        
    }
    
    
    return answer;
}