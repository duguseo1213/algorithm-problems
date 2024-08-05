#define P 
#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(long long i=1;i<r2;i++){ //마지막에 1
        
        long long left=0;
        long long right=r1;
        long long low=0;
        long long high;
        while(1){
            if(left>right) break;
            long long mid=(left+right)/2;
            if(i*i+mid*mid>=(long long)r1*r1){
                low=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        P("%lld ",low);
        
        left=0;
        right=r2;
        while(1){
            if(left>right) break;
            long long mid=(left+right)/2;
            if(i*i+mid*mid>(long long)r2*r2){
                right=mid-1;
            }
            else{
                high=mid;
                left=mid+1;
            }
        }
        answer=answer+(high-low+1);
        P("%lld \n",high);
    }
    answer=(answer+1)*4;
    
    return answer;
}