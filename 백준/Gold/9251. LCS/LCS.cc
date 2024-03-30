#define _CRT_SECURE_NO_WARNINGS
#define P 
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int arr[1000][1000]; //a 가로 //b 세로


int main()
{
	string a, b;

	cin >> a >> b;

	for (int i = 0; i < a.length(); i++)
	{
		if (b[0] == a[i] || (i > 0 && arr[0][i - 1] == 1))
		{
			arr[0][i] = 1;
		}
	}

	for (int i = 0; i < b.length(); i++)
	{
		if (a[0] == b[i] || (i > 0 && arr[i - 1][0] == 1))
		{
			arr[i][0] = 1;
		}
	}



	for (int i = 1; i < b.length(); i++)
	{
		for (int j = 1; j < a.length(); j++)
		{
			if (a[j] == b[i])
			{
				arr[i][j] = max(arr[i - 1][j-1] + 1, arr[i][j - 1]);
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}


		}

	}
	int maxx = 0;
	for (int i = 0; i < b.length(); i++)
	{
		for (int j = 0; j < a.length(); j++)
		{
			maxx = max(maxx, arr[i][j]);
			P("%d ", arr[i][j]);
		}
		P("\n");
	}

	printf("%d", maxx);


}