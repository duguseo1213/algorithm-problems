#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> vec;
int prime[4000002];

int main()
{
	prime[0] = 1;
	prime[1] = 1;
	int N;
	cin >> N;

	int sqr = sqrt(N);

	for (int i = 2; i <= sqr; i++)
	{
		if (prime[i] == 1) continue;
		for (int j = 2; j*i <= N; j++)
		{
			prime[j * i] = 1;
		}
	}

	for (int i = 0; i <= N; i++)
	{
		if (prime[i] == 0)
		{
			vec.push_back(i);
		}
	}

	



	int i = 0;
	int j = 0;
	int answer=0;
	
	if (vec.size() == 0)
	{
		cout << 0;
	}
	
	else
	{
		int sum = vec[i];
		while (1)
		{

			if (sum > N)
			{
				if (i == j)
				{
					break;
				}
				sum = sum - vec[i];
				i++;

			}
			else if (sum < N)
			{
				if (j == vec.size() - 1)
				{
					break;
				}
				j++;
				sum = sum + vec[j];
			}
			else
			{
				//cout << i << " " << j << sum<<endl;
				answer++;
				if (j == vec.size() - 1)
				{
					break;
				}
				j++;
				sum = sum + vec[j];
			}


		}

		cout << answer;

	}


}