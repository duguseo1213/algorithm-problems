#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
map<string, string> map_;
int cnt;
string find(string tar)
{
	if (map_[tar] == tar)
	{
		return tar;
	}

	string root = find(map_[tar]);
	map_[tar] = root;
	return root;

}

void setunion(string a, string b)
{
	string t1 = find(a);
	string t2 = find(b);

	if (t1 == t2) return;

	map_[t2] = t1;
	m[t1] += m[t2];
}


int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cnt = 0;
		map_.clear();
		int N;
		cin >> N;
		string a, b;

		for (int i = 0; i < N; i++)
		{
			cin >> a >> b;
			if (map_.find(a) == map_.end())
			{
				map_[a] = a;
				m[a] = 1;
			}
			if (map_.find(b) == map_.end())
			{
				map_[b] = b;
				m[b] = 1;
			}

			setunion(a, b);
			

			
			printf("%d\n", m[find(a)]);

		}
	}
}