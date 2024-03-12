#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

int minheap[100010];
int hn;

void push(int num)
{
	hn++;
	minheap[hn] = num;
	int temp;
	for (register int i = hn; i > 1; i = i / 2)
	{
		if (minheap[i / 2] <= minheap[i]) break;

		temp = minheap[i / 2];
		minheap[i / 2] = minheap[i];
		minheap[i] = temp;

	}

}

int del(int num)
{
	int ret = minheap[1];
	minheap[1] = minheap[hn];
	minheap[hn] = 21e7;
	hn--;
	int temp;
	for (int i = 1; i*2 <= hn;)
	{
		if (minheap[i] < minheap[i * 2] && minheap[i] < minheap[i * 2 + 1]) break;
		else if (minheap[i * 2 + 1] > minheap[i * 2])
		{
			temp = minheap[i * 2];
			minheap[i * 2] = minheap[i];
			minheap[i] = temp;
			i = i * 2;
		}
		else
		{
			temp = minheap[i * 2+1];
			minheap[i * 2+1] = minheap[i];
			minheap[i] = temp;
			i = i * 2+1;
		}
	}
	
	return ret;

}




int main()
{
	int N;
	cin >> N;
	int num;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			if (hn == 0) printf("0\n");
			else printf("%d\n",del(num));
		}
		else
		{
			push(num);
		}
	}
	

	

}