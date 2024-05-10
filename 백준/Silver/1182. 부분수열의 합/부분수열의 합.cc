#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

int N, M;

int arr[20];



int main()
{
	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int answer = 0;
	for (int i = 1; i < (1 << N); i++)
	{
		int j = i;
		int cnt = 0;
		int ans = 0;
		while (1)
		{
			if (j == 0) break;

			if (j & 1)
			{
				ans += arr[cnt];
			}
			j=j >> 1;
			cnt++;


		}

		if (ans == M)
		{
			answer++;
		}



	}

	printf("%d", answer);

}
