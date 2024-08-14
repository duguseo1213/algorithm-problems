#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string str;

int dp[1001];

int main() {

	cin >> N;
	cin >> str;

	for (int i = 0; i <= 1000; i++) {
		dp[i] = 21e8;
	}

	dp[0] = 0;

	for (int i = 1; i < str.size(); i++) {
		if (str[i] == 'B') {
			for (int j = 0; j < i; j++) {
				if (str[j] == 'J') {
					dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
				}
			}
		}

		else if (str[i] == 'O') {
			for (int j = 0; j < i; j++) {
				if (str[j] == 'B') {
					dp[i] = min(dp[i], dp[j]+(i - j) * (i - j));
				}
			}
		}
		else {
			for (int j = 0; j < i; j++) {
				if (str[j] == 'O') {
					dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
				}
			}

		}

	}

	if (dp[str.size() - 1] == 21e8) {

		cout << -1;
		return 0;
	}

	cout << dp[str.size() - 1];

}