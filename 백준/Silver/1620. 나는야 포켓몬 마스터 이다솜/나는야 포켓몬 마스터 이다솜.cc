#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

map<string, string> m1;

map<string, string> m2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string temp;
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> temp;
		m1[temp] = to_string(i);
		m1[to_string(i)] = temp;
		//cout << to_string(i);
		
	}
	

	for (int j = 0; j < M; j++)
	{
		cin >> temp;

		cout << m1[temp]<<"\n";
	}

}