#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

map<string, int> m;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	string name;
	string state;

	for (int i = 0; i < N; i++)
	{
		cin >> name;
		cin >> state;

		if (state == "enter")
		{
			m[name] = 1;
		}
		else
		{
			m.erase(name);
		}
	}
	auto i = m.end();
	i--;

	while (1)
	{
		cout << i->first << "\n";
		if (i == m.begin()) break;
		i--;
	}

}