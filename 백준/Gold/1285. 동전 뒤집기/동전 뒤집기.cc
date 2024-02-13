#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> str;
vector<string> str1;


int N;
int minn = 987654321;

int visit[20];

void func(int dep)
{
	
	if (dep == N) //1이면 바꾸기 2면 안바꾸기
	{
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == 1)
			{
				for (int j = 0; j < N; j++)
				{
					if (str[i][j] == 'T') str[i][j] = 'H';
					else str[i][j] = 'T';
				}
			}
		}
	

		
		for (int i = 0; i < N; i++)
		{
			int c = 0;
			for (int j = 0; j < N; j++)
			{
				if (str[j][i] == 'T') c++;
			}
			if (c * 2 >= N)
			{
				for (int j = 0; j < N; j++)
				{
					if (str[j][i] == 'T') str[j][i] = 'H';
					else str[j][i] = 'T';
				}
			}
		}


		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				
				if (str[i][j] == 'T') cnt++;
			}
		}
		minn = min(minn, cnt);

		str = str1;
		return;
	}

	for (int i = 1; i <= 2; i++)
	{
		
		visit[dep] = i;
		func(dep + 1);
		
	}

}

int main()
{
	cin >> N;
	
	string temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		str.push_back(temp);
	}
	
	str1 = str;

	func(0);

	cout << minn;




}
