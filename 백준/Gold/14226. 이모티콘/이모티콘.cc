#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>
#include <map>

using namespace std;

int S;

queue<tuple<int, int,int>> q; //현재 개수, 클립보드, 시간
map<tuple<int, int, int>,int> m;

void bfs()
{
	q.push({ 1, 0 ,0});
	//m[{1, 0,0}] = 1;

	while (!q.empty())
	{
		tuple<int, int,int> temp = q.front();

		q.pop();

		if (get<0>(temp) == S)
		{
			printf("%d", get<2>(temp));
			return;
		}

		if (get<0>(temp) < 1)
		{

			continue;
		}


		if (m[temp] == 1)
		{
			continue;
		}
		m[temp] = 1;

		q.push({ get<0>(temp), get<0>(temp) ,get<2>(temp)+1 });

		q.push({ get<0>(temp)-1, get<1>(temp) ,get<2>(temp) + 1 });

		q.push({ get<0>(temp)+ get<1>(temp), get<1>(temp) ,get<2>(temp) + 1 });


	}


	


}


int main()
{
	scanf("%d", &S);
	bfs();
	
}