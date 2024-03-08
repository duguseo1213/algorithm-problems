#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int, vector<int>> pq1; //max heap
priority_queue<int, vector<int>,greater<int>> pq2;//min heap

//현재 중앙값보다 크면 minheap // 작으면 maxheap으로 넣어주기

int main()
{
	int N;
	cin >> N;

	int center = 0;

	int temp;
	scanf("%d", &temp);
	pq1.push(temp);

	center = temp;
	
	cout << center<<endl;

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &temp);

		if (pq1.size() == pq2.size())
		{
			if (temp > center)
			{
				pq2.push(temp);
				center = pq2.top();
			}
			else
			{
				pq1.push(temp);
				center = pq1.top();
			}
		}
		else if (pq1.size() > pq2.size())
		{
			if (temp > center)
			{
				pq2.push(temp);
			}
			else
			{
				pq2.push(pq1.top());
				pq1.pop();
				pq1.push(temp);
			}
			center = pq1.top();
		}
		else
		{
			if (temp > center)
			{
				pq1.push(pq2.top());
				pq2.pop();
				pq2.push(temp);
			}
			else
			{
				pq1.push(temp);
			}
			center = pq1.top();
		}
		

		printf("%d\n", center);
	
	}
}