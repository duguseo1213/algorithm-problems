#include<iostream>
using namespace std;
int main()
{
    int dp[11] = {0, 1, 2, 4, 7};
    for (int i = 5; i < 11; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        printf("%d\n", dp[a]);
    }
}