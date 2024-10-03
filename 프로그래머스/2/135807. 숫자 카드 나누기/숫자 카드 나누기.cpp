#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    
    if(a%b==0){
        return b;
    }
    
    int temp=a%b;
    
    return gcd(b,temp);
    
    
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    
    int temp1=arrayA[0];
    
    int temp2=arrayB[0];
    int state1=0;
    int state2=0;
    for(int i=1;i<arrayA.size();i++){
        
        temp1=gcd(arrayA[i],temp1);
    }
    
    for(int i=1;i<arrayB.size();i++){
        
        temp2=gcd(arrayB[i],temp2);
    }
    
    for(int i=0;i<arrayA.size();i++){
        if(arrayA[i]%temp2==0) {
            state1=1;
            break;
        }
    }
    
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%temp1==0) {
            state2=1;
            break;
        }
    }
    
    if(state1==1 && state2==1){
        return 0;
    }
    
    if(temp2>temp1){
        if(state1==0){
            return temp2;
        }
        else{
            return temp1;
        }
        
    }
    else{
        if(state2==0){
            return temp1;
        }
        else{
            return temp2;
        }
    }
    
    
    
    
    return answer;
}