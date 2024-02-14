#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#define INF 987654321



using namespace std;

struct edge{
	int a;
};

struct cmp {
	bool operator()(edge a,edge b)
	{
		return a.a < b.a;
	}
};


priority_queue<edge, vector<edge>, cmp> pq;


int main()
{
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);

		if (temp == 0)
		{
			if (!pq.empty())
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			pq.push({ temp });
		}
	}



}



