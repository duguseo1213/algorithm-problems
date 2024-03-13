#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int heap[100000];
int hn;

bool cmp(int a,int b)
{
	return a <= b; //뒤에께 크면 true
}

void push(int num)
{
	hn++;
	heap[hn] = num;
	int temp;
	for (int i = hn; i > 1; i = i / 2)
	{
		if (cmp(heap[i], heap[i / 2])) break;

		temp = heap[i];
		heap[i] = heap[i / 2];
		heap[i / 2] = temp;
	}


}

int pop()
{
	int ret = heap[1];
	heap[1] = heap[hn];
	heap[hn] = -10000;

	int temp;
	hn--;
	for (int i = 1; i * 2 <= hn;)
	{
		if (!cmp(heap[i], heap[i * 2]) && !cmp(heap[i], heap[i * 2 + 1])) break;
		else if (cmp(heap[i*2+1], heap[i * 2]))
		{
			temp= heap[i];
			heap[i]= heap[i * 2];
			heap[i * 2]=temp;
			i = i * 2;
		}
		else
		{
			temp = heap[i];
			heap[i] = heap[i * 2+1];
			heap[i * 2+1] = temp;
			i = i * 2+1;
		}

		
	}
	
	return ret;

}


int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		if (num == 0)
		{
			if (hn == 0)
			{
				printf("0\n");
				continue;
			}

			printf("%d\n",pop());
		}
		else
		{
			push(num);
		}
	}
}