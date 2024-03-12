#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;



struct NODE {
	map<string, NODE*> m;
};

NODE HEAD;

NODE a[100000];

int N, K;

void dfs(NODE *cur,int dep)
{
	
	
	for (auto i = (cur->m).begin(); i != (cur->m).end(); i++)
	{
		//printf("%d", dep);
		for (int j = 0; j < dep; j++)
		{
			printf("--");
		}
		cout << i->first<<"\n";

		dfs(i->second,dep+1);
	}
}


int main()
{
	string temp;
	int nct = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> K;
		NODE * tempnode = &HEAD;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			

			if ((tempnode->m).find(temp) == (tempnode->m).end()) //없다는 뜻
			{	
				NODE *newnode = &a[nct];
				nct++;
				(tempnode->m)[temp] = newnode;
			}
			
			tempnode = (tempnode->m)[temp];
			
		}
	}

	dfs(&HEAD,0);
}