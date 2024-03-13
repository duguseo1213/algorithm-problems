#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

string voca[100001];

unordered_map<string, int> um;

unordered_map<string, int> voindex;

int vn;


bool cmp(string a,string b)
{
	if (um[a] == um[b])
	{
		if (a.size() == b.size())
		{
			return a > b;
		}

		return a.size() < b.size();
	}

	return um[a] < um[b];
}

void push(string a)
{
	vn++;
	voca[vn]=a;
	voindex[a] = vn;

	string temp;

	for (int i = vn; i > 1; i = i / 2)
	{
		if (cmp(voca[i], voca[i / 2])) break;

		temp = voca[i / 2];
		voca[i / 2] = voca[i];
		voca[i] = temp;

		voindex[voca[i / 2]] = i / 2;
		voindex[voca[i]] = i;
	}
}

string pop()
{
	string ret = voca[1];
	voca[1] = voca[vn];
	voca[vn] = "";
	string temp;
	vn--;
	for (int i = 1; i * 2 <= vn;)
	{
		if (!cmp(voca[i], voca[i * 2]) && !cmp(voca[i], voca[i * 2 + 1])) break;

		else if (cmp(voca[i * 2], voca[i * 2 + 1]))
		{
			temp = voca[i * 2 + 1];
			voca[i * 2 + 1] = voca[i];
			voca[i] = temp;

			voindex[voca[i * 2 + 1]] = i * 2 + 1;
			voindex[voca[i]] = i;

			i = i * 2 + 1;
		}
		else
		{
			temp = voca[i * 2];
			voca[i * 2 ] = voca[i];
			voca[i] = temp;

			voindex[voca[i * 2 ]] = i * 2 ;
			voindex[voca[i]] = i;

			i = i * 2 ;
		}

	}

	return ret;
}

void update(string a)
{
	int upvn = voindex[a];

	string temp;

	for (int i = upvn; i > 1; i = i / 2)
	{
		if (cmp(voca[i], voca[i / 2])) break;

		temp = voca[i / 2];
		voca[i / 2] = voca[i];
		voca[i] = temp;

		voindex[voca[i / 2]] = i / 2;
		voindex[voca[i]] = i;
	}

	for (int i = 1; i * 2 <= upvn;)
	{
		if (!cmp(voca[i], voca[i * 2]) && !cmp(voca[i], voca[i * 2 + 1])) break;

		else if (cmp(voca[i * 2], voca[i * 2 + 1]))
		{
			temp = voca[i * 2 + 1];
			voca[i * 2 + 1] = voca[i];
			voca[i] = temp;

			voindex[voca[i * 2 + 1]] = i * 2 + 1;
			voindex[voca[i]] = i;

			i = i * 2 + 1;
		}
		else
		{
			temp = voca[i * 2];
			voca[i * 2] = voca[i];
			voca[i] = temp;

			voindex[voca[i * 2]] = i * 2;
			voindex[voca[i]] = i;

			i = i * 2;
		}

	}


}
int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string temp;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		if (temp.size() < M)
		{
			continue;
		}

		if (voindex.find(temp)!=voindex.end())
		{
			um[temp]++;
			update(temp);
		}
		else
		{
			um[temp];
			push(temp);
		}
	}

	for (int i = 0; i < voindex.size(); i++)
	{
		cout << pop() << "\n";
	}


	
}