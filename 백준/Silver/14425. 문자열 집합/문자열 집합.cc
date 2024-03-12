#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;


struct NODE {
	int yes;
	unordered_map<char, NODE*> m;
};

NODE HEAD;

NODE DATAS[10000];

int N, M;
int state = 0;
string str_input;
void dfs(NODE* cur,int dep)
{
	if (dep == str_input.size() && cur->yes==1)
	{

		state = 1;
		return;
	}
	
	if (cur->m.find(str_input[dep]) != cur->m.end())
	{
		cur = cur->m[str_input[dep]];
		dfs(cur, dep + 1);
	}
	else
	{
		return;
	}

}


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	
	int dcnt = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> str_input;
		NODE* cur = &HEAD;

		for (int j = 0; j < str_input.size(); j++)
		{
			
			if (cur->m.find(str_input[j]) == cur->m.end())
			{
				
				NODE *newnode = new NODE;
				dcnt++;
				cur->m[str_input[j]] = newnode;
			}

			cur = cur->m[str_input[j]];

		}
		cur->yes = 1;

	}

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		state = 0;
		cin >> str_input;
		dfs(&HEAD,  0);
		if (state == 1)
		{
			cnt++;
			
		}
	}
	cout << cnt;
	

	

}