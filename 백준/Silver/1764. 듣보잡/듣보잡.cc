#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

map<string, int> m1;

int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> M;
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		m1[temp] = 1;
	}

	for (int j = 0; j < M; j++)
	{
		cin >> temp;
	
		m1[temp]++;
	}

	int answer = 0;

	for (auto i = m1.begin(); i != m1.end(); i++)
	{
		if (i->second == 2)
		{

			answer++;
		}
	}
	cout << answer << "\n";
	for (auto i = m1.begin(); i != m1.end(); i++)
	{
		if (i->second == 2)
		{
			
			cout << i->first << "\n";
		}
	}



}