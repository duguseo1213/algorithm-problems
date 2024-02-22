#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

vector<int> course;
vector<int> temp;

int map[101][101];

int main()
{
	int N;
	cin >> N;
	int answer = 0;
	for (int k = 0; k < N; k++)
	{
		temp.clear();
		course.clear();

		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);
		course.push_back(d);

		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < course.size(); j++)
			{
				temp.push_back(course[j]);
			}

			for (int j = 0; j < temp.size(); j++)
			{
				course.push_back((temp[temp.size() - 1 - j] +1) % 4);
			}
			temp.clear();

			

		}
		map[y][x] = 1;
		for (int i = 0; i < course.size(); i++)
		{
			
			
			x = x + dx[course[i]];
			y = y + dy[course[i]];
			map[y][x] = 1;
		}
		

	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
			{
				answer++;
			}
		}

	}
	cout << answer;



}