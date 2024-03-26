#include<iostream>


using namespace std;

int dp[15][15];

int main()
{
    for(int i=1;i<15;i++)
    {
        dp[0][i]=i;
    }
    
    for(int i=0;i<15;i++)
    {
        dp[i][1]=1;
    }

    for(int i=1;i<15;i++){
        for(int j=2;j<15;j++){

            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            
        }
        
    }
    for(int i=0;i<15;i++){
        for(int j=1;j<15;j++){

            //printf("%d ",dp[i][j]);
            
        }
        //printf("\n");
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++) {
        
    int k,n;
    scanf("%d %d",&k,&n);
        printf("%d\n",dp[k][n]);
    }

    
   return 0;
}