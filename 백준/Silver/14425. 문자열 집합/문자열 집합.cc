#define P printf
#define _CRT_SECURE_NO_WARNINGS



#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> s;

int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;

		cin >> temp;
		s.insert(temp);


	}
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		string temp;

		cin >> temp;

		if (s.find(temp) != s.end()) {
			cnt++;
		}


	}

	cout << cnt;
}