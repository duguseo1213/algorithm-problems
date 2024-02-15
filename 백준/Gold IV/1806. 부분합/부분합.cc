#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstdlib>
#define INF 987654321

using namespace std;
vector<int> arr;

int N;
int S;
int dat[10001];
int minn = 2100000000;
int main()
{
	cin >> N;
	cin >> S;
	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	int i = 0;
	int j = -1;
	int sum = 0;
	while (j!=N-1 && sum<S)
	{
		j++;
		sum = sum + arr[j];
	}
	//cout << j;
	if (j == 0 && i == 0 && arr[i]>S)
	{
		cout << 1;
	}
	else
	{
		while (1)
		{
			if (j==N-1 && i==N-1)
			{
				if (sum >= S)
				{
					minn = min(j - i + 1, minn);
				}
				break;
			}

			
			if (sum >= S)
			{
				sum = sum - arr[i];
				minn = min(j - i + 1, minn);
				i++;
				
			}
			else
			{

				j++;
				if (j == N) break;
				sum = sum + arr[j];

			}



		}

		if (minn == 2100000000) minn = 0;
		cout << minn;
	}
}


