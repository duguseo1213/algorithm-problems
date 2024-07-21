#define P printf
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <ctime>
#include <set>
#include <unordered_map>
using namespace std;

unordered_map<string, string> um;


//int arr[1001][1001];

int N;
int M;



int main() {

	ios_base::sync_with_stdio(0);

	cout.tie(0);
	cin.tie(0);


	cin >> N >> M;


	for (int i = 0; i < N; i++) {

		string temp1,temp2;

		cin >> temp1>>temp2;

		um[temp1] = temp2;



	}

	for (int i = 0; i < M; i++) {

		string temp1;

		cin >> temp1;

		cout << um[temp1] << "\n";



	}
	
	
}