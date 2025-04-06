#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define INF 987654321

using namespace std;

int A[100000];

int B[100000];

int target;
int state = 0;
void func(int left, int right)
{
	//cout << left << " " << right << endl;
	if (right < left)
	{
		return;
	}

	int mid = (left + right) / 2;

	if (target == A[mid])
	{
		state = 1;
		printf("1\n");
		return;
	}

	else if (A[mid] > target)
	{
		func(left, mid-1);
	}
	
	else
	{
		func(mid+1, right );
	}


}


int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &B[i]);
		//cout << B[i] << endl;
	}
	sort(A,A+N);
	for (int i = 0; i < M; i++)
	{
		state = 0;
		target = B[i];
		
		func(0, N-1);
		if (state == 0) printf("0\n");
	}
}