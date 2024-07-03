#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10001];

int arr[21];
int T, N,value;
int main(){
    
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            
        }
        scanf("%d", &value);

        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= value; j++) {

                if (j >= arr[i]) {
                    dp[j] = dp[j - arr[i]] + dp[j];
                }

            }
        }
        
        printf("%d\n", dp[value]);






    }




}