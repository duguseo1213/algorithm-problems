#include <string>
#include <vector>

using namespace std;

int dp[101][101];
int arr[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++){
        arr[puddles[i][1]-1][puddles[i][0]-1]=1;
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            
            if(arr[i][j]==1) continue;
            
            if(i==0 && j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=dp[i][j-1];
            }
            else if(j==0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007;
            }
            
        }
    }
    
    
    return dp[n-1][m-1]%1000000007;
}