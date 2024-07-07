#define ll long long
#define P printf
#define MAX 102
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long facto[101];
long long inv[101];
long long dp[101][101];
/*
long long comb(int a,int b) {


	return facto[a] / facto[a - b] / facto[b];

}*/

const ll MOD = 1000000007; //반드시 소수여야 한다.

ll fac[MAX], fac_inv[MAX]; //fac, fac_inv %MOD
ll pw(ll x, ll y) {
	if (y == 0) return 1;

	ll ret;
	if (y % 2) ret = (x * pw(x, y - 1)) % MOD;
	else {
		ret = pw(x, y / 2);
		ret = (ret * ret) % MOD;
	}
	return ret;
}
void makeFac() {
	fac[0] = 1;
	for (int i = 1; i < MAX; i++)
		fac[i] = (fac[i - 1] * i) % MOD;

	fac_inv[MAX - 1] = pw(fac[MAX - 1], MOD - 2);
	for (int i = MAX - 2; i >= 0; i--)
		fac_inv[i] = (fac_inv[i + 1] * (i + 1)) % MOD;
}
ll comb(int x, int y) { // (x C y)%MOD 반환
	if (x == y) return 1;
	if (y == 1) return x;

	ll ret = (fac[x] * fac_inv[x - y]) % MOD;
	ret = (ret * fac_inv[y]) % MOD;
	return ret;
}

int N, L, R;

int main() {

	makeFac();
	long long temp = 1;
	facto[0] = 1;
	facto[1] = 1;
	for (int i = 1; i <= 100; i++) {
		temp = temp * i % 1000000007;
		facto[i] = temp;
	}
	dp[0][0] = 1;
	//printf("%lld", facto[10]);

	for (int i = 1; i <= 100; i++) {
		dp[1][i] = fac[i - 1];
	}

	for (int i = 2; i <= 100; i++) {
		for (int j = 1; j < 100; j++) {

			for (int k = 0; k <= j; k++) {
				dp[i][j + 1] = (dp[i][j + 1] + (dp[i - 1][k] * fac[j - k] % 1000000007) * comb(j, k) % 1000000007) % 1000000007;
			}

		}
	}

	/*
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			P("%lld ", dp[i][j]);
		}
		P("\n");
	}*/


	scanf("%d %d %d", &N, &L, &R);
	long long answer = 0;
	for (int i = 0; i < N; i++) {
		answer = (answer + (comb(N - 1, i) * dp[L - 1][i] % 1000000007) * dp[R - 1][N - 1 - i] % 1000000007) % 1000000007;
	}

	printf("%lld", answer);
}