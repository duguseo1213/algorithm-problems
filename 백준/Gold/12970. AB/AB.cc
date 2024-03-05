#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int N,K;

vector<char> a;
int main()
{
	

	cin >> N >> K;
	int NN = N;
	int answer = 987654321;
	int state = 0;
	
	
	for (int i = 0; i < N; i++)
	{
		if ( (N - i) * i>= K)
		{
			state = (N - i) * i - K;
			answer = i;
			break;
		}
	}

	
		
	
	if (answer == 987654321) cout << -1;

	else
	{

		for (int i = 0; i < answer; i++)
		{
			a.push_back('A');
		}
		for (int i = 0; i < N - answer; i++)
		{
			a.push_back('B');
		}

		if (state > 0)
		{
			a[answer - 1] = 'B';
			a[answer + state-1] = 'A';
		}

		for (int i = 0; i < a.size(); i++)
		{
			printf("%c", a[i]);
		}
	}

}