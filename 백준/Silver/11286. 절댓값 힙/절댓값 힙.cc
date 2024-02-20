#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct cmp {

	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

priority_queue<int, vector<int>,cmp> pq;






int main()
{
	int N;
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);

		if (temp==0)
		{
			if (pq.size() > 0)
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			pq.push(temp);
		}


		
	}

}