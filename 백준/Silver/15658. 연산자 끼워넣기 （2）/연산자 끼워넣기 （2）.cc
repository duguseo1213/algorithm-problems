#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
using namespace std;

int cnt;

int N;
int arr[20];
int oper[50];

int visit[20];
int ans[20];

long minn = 2000000000;
long maxx = -2000000000;
void func(int dep)
{
	int check[4] = { 0, };



	if (dep == N-1)
	{
		long result = arr[0];
		for (int i = 0; i <N-1; i++)
		{
			if (ans[i] == 0)
			{
				result = result + arr[i + 1];
			}
			else if (ans[i] == 1)
			{
				result = result - arr[i + 1];
			}
			else if (ans[i] == 2)
			{
				result = result * arr[i + 1];
			}
			else if (ans[i] == 3)
			{
				result = result / arr[i + 1];
			}
		}
		/*
		for (int i = 0; i < N - 1; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;*/
		if (result < minn) minn = result;
		if (result > maxx) maxx = result;

		return;
	}

	for (int i = 0; i < cnt; i++)
	{
		if (visit[i] == 0 && check[oper[i]] == 0)
		{


			visit[i] = 1;
			ans[dep] = oper[i];
			func(dep + 1);
			visit[i] = 0;
			check[oper[i]] = 1;
		}

	}


}

int main()
{
	cin >> N;

	int temp;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}


	for (int i = 0; i < 4; i++)
	{
		cin >> temp;
		cnt += temp;
		while (temp != 0)
		{
			oper[j] = i;
			j++;
			temp--;
		}
	}

	//cout << cnt;

	func(0);
	cout << maxx << endl << minn;
}