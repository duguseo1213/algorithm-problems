#include <iostream>

using namespace std;

long long dp[50];

void solve(int n) {
    int a, b;
    a = n - 1, b = n - 2;
    if (dp[a] == 0 || dp[b] == 0) solve(n - 1);

    dp[n] = dp[a] + dp[b];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[2] = 1, dp[1] = 1;



    int N;
    cin >> N;

    if (N <= 2) {
        cout << dp[N];
        return 0;
    }

    solve(N);

    cout << dp[N];
    return 0;
}