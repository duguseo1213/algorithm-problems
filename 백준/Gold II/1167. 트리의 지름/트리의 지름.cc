#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> graph[100001];

int visit[100001];

int N;
long maxx=0;


int dfs(int r,long sum,long ret)
{
	long leng = 0;
	long maxreturn = 0;
	long maxleng1 = sum;
	long maxleng2 = 0;

	for (int i = 0; i < graph[r].size(); i++)
	{

		if (visit[graph[r][i].first] == 1)
		{
			if (maxx < sum)
			{
				maxx = sum;		
			}
		}
		else
		{
			//cout << graph[r][i].first << " ";
			visit[graph[r][i].first] = 1;
			leng=dfs(graph[r][i].first, sum + graph[r][i].second, graph[r][i].second);

			if (leng > maxreturn) maxreturn = leng;
			leng;

			if (leng > maxleng1)
			{
				maxleng2 = maxleng1;
				maxleng1 = leng;


			}
			else if(leng>maxleng2)
			{
				
				maxleng2 = leng;
				
			}
			else
			{ }


		}
	}
	
	if (maxx < maxleng1 + maxleng2) maxx = maxleng1 + maxleng2;
	
	//cout << r <<" "<<maxleng1 <<" "<<maxleng2 <<" "<< maxreturn + ret <<endl;
	//돌아오는것은 경로대로 와야함
	return maxreturn+ret;


}

int main()
{
	int a,b;
	cin >> N;
	cin.ignore();
	int vertex;

	for (int i = 0; i < N; i++)
	{
		cin >> vertex;
		while (1)
		{
			cin >> a;
			if (a == -1)
			{
				break;
			}
			cin >> b;
			graph[vertex].push_back(pair<int, int>(a, b));
			
		}

	}
	
	visit[1] = 1;
	dfs(1,0,0);
		
	cout << maxx;
}