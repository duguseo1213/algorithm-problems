#define _CRT_SECURE_NO_WARNINGS
#define P printf
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;


int N, M, L, K;
int maxx = 0;
vector<pair<int, int>> vec;

vector<pair<int, int>> cross;

void find_inter()
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec.size(); j++)
		{
			if (i == j) continue;

			cross.push_back({ vec[i].first,vec[j].second });
			cross.push_back({ vec[j].first,vec[i].second });

		}
	}
}


int main()
{
	scanf("%d %d %d %d", &N, &M, &L, &K);

	int a, b;

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &a, &b);
		vec.push_back({ a,b });
	}
	int sy;
	int sx;

	find_inter();

	for (int i = 0; i < vec.size();i++) //모든 점에 대해서
	{

		//4방향
		

		int y = vec[i].first;
		int x = vec[i].second;

		sy = vec[i].first + L * -1;
		sx = vec[i].second + L * -1;
		int cnt = 0;
		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first >= sy && vec[j].first <= y && vec[j].second >= sx && vec[j].second <= x)
			{
				cnt++;
			}


		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = vec[i].first + L * 1;
		sx = vec[i].second + L * -1;
		
		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first <= sy && vec[j].first >= y && vec[j].second >= sx && vec[j].second <= x)
			{
				cnt++;
			}


		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = vec[i].first + L * 1;
		sx = vec[i].second + L * 1;
		
		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first <= sy && vec[j].first >= y && vec[j].second <= sx && vec[j].second >= x)
			{
				cnt++;
			}

		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = vec[i].first + L * -1;
		sx = vec[i].second + L * 1;
		
		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first >= sy && vec[j].first <= y && vec[j].second <= sx && vec[j].second >= x)
			{
				cnt++;
			}

		}

		maxx = max(maxx, cnt);








	}

	for (int i = 0; i < cross.size(); i++) //모든 점에 대해서
	{

		//4방향


		int y = cross[i].first;
		int x = cross[i].second;

		sy = cross[i].first + L * -1;
		sx = cross[i].second + L * -1;
		int cnt = 0;
		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first >= sy && vec[j].first <= y && vec[j].second >= sx && vec[j].second <= x)
			{
				cnt++;
			}


		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = cross[i].first + L * 1;
		sx = cross[i].second + L * -1;

		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first <= sy && vec[j].first >= y && vec[j].second >= sx && vec[j].second <= x)
			{
				cnt++;
			}


		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = cross[i].first + L * 1;
		sx = cross[i].second + L * 1;

		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first <= sy && vec[j].first >= y && vec[j].second <= sx && vec[j].second >= x)
			{
				cnt++;
			}

		}

		maxx = max(maxx, cnt);

		cnt = 0;

		sy = cross[i].first + L * -1;
		sx = cross[i].second + L * 1;

		for (int j = 0; j < vec.size(); j++)
		{

			if (vec[j].first >= sy && vec[j].first <= y && vec[j].second <= sx && vec[j].second >= x)
			{
				cnt++;
			}

		}

		maxx = max(maxx, cnt);


	}

	printf("%d",K- maxx);
}