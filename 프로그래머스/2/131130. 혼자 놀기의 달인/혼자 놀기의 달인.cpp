#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int team[101];

int tcnt=0;

int solution(vector<int> cards) {
    int answer = 0;
    
    for(int i=0;i<cards.size();i++){
        
        int temp=i;
        if(cards[temp]==-1) continue;
        
        team[tcnt]++;
        
        while(1){
            
            int a=cards[temp]-1;
             cards[temp]=-1;
            temp=a;
            
           
            
            if(cards[temp]==-1) break;
            
            team[tcnt]++;
            
        }
        
        tcnt++;
        
        
    }
    
    sort(&team[0],&team[0]+100,greater<int>());
    
    
    
    
    return team[0]*team[1];
}