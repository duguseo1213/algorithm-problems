#include <string>
#include <vector>

using namespace std;

int arr[1000001];


int solution(int n) {
    arr[1]=1;
    for(int i=2;i*i<=n;i++){
        
        if(arr[i]==0){
                    
            for(int j=i;j<=n;j=j+i){
                arr[j]=1;
            }
            arr[i]=0;
        }
    }
    int answer = 0;
    for(int i=1;i<=n;i++){
        //printf("%d ",arr[i]);
        if(arr[i]==0) answer++;
        
    }
    
    
    
    
    return answer;
}