#define _CRT_SECURE_NO_WARNINGS
#define P printf

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>

using namespace std;

struct Dis{
	int a;
	int b;
	int dis;

};

int N;
int quantity;

int arr[10001];

vector<Dis> diss;

bool cmp(Dis a, Dis b)
{
	return a.dis > b.dis;
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &quantity);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	
	if (quantity > N)
	{
		printf("0");
		return 0;
	}


	sort(&arr[0], &arr[0] + N);

	for (int i = 0; i < N; i++)
	{
		//printf("%d ", arr[i]);
	}

	for (int i = 0; i < N - 1; i++)
	{
		Dis temp;
		temp.a = arr[i];
		temp.b = arr[i+1];
		temp.dis = arr[i + 1] - arr[i];
		diss.push_back(temp);
	}

	sort(diss.begin(), diss.end(), cmp);

	int answer = arr[N - 1] - arr[0];

	for (int i = 0; i < quantity - 1; i++)
	{
		answer = answer - diss[i].dis;
	}
	printf("%d", answer);





	   	 
}