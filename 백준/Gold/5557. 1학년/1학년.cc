#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int N;

long long arr[100];
long long dp[1001][101];

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    dp[arr[0]][0] = 1;

    for (int j = 0; j < 100; j++) {

        for (int i = 0; i < 1000; i++) {

            if (dp[i][j] != 0) {

                if (i - arr[j + 1] < 0) {
                    dp[i + arr[j + 1]][j + 1] += dp[i][j];
                }
                else if (i + arr[j + 1] > 20) {
                    dp[i - arr[j + 1]][j + 1] += dp[i][j];
                }
                else {
                    dp[i + arr[j + 1]][j + 1] += dp[i][j];
                    dp[i - arr[j + 1]][j + 1] += dp[i][j];
                }
            }
        }
    }

    long long answer = 0;

   

    

    cout << dp[arr[N-1]][N-2];

}