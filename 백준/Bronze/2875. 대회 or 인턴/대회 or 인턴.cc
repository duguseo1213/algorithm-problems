#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>

using namespace std;

float N,M,K;


int main()
{
	cin >> N >> M >> K;

	int a = 0;
	float minn = 987654321;
	for (int i = 0; i <= K; i++)
	{
		if (minn >abs(2- (N - K + i) / (M - i)))
		{
			minn = abs(2 - (N - K + i) / (M - i));
			a = i;
		}
	}
	//cout << a;
	int qqq;
	qqq = (int)M;
	



	cout << min(qqq - a,(int)((N+a-K)/2));

}