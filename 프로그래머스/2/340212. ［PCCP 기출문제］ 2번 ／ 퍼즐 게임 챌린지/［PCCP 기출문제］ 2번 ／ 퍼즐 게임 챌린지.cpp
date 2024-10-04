#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    long long answer = 0;
    
    long long left=1;
    long long right=300000;
    
    while(1){
        
        if(right<left) break;
        
        long long mid=(right+left)/2;
        
        long long sum=times[0];
        
        for(int i=1;i<diffs.size();i++){
            if(mid>=diffs[i]){
                sum+=times[i];
            }
            else{
                sum=sum+(diffs[i]-mid)*(times[i-1]+times[i])+times[i];
            }
        }
        
        if(sum>limit){
            left=mid+1;
            
        }
        else{
            right=mid-1;
            answer=mid;
            
        }
        
        
        
    }
    
    
    return answer;
}