#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;


unordered_map<long long, long long> um;


struct val {
	int A;
	int B;
	int C;
};

queue<val> q;

int state = 0;

void bfs()
{
	while (!q.empty())
	{

		val now = q.front();
		q.pop();
		//printf("%d %d %d\n", now.A, now.B, now.C);
		if (now.A == now.B && now.A == now.C && now.B == now.C)
		{
			state = 1;
			return;
		}

		if (um[now.A * 100000000 + now.B * 10000 + now.C] == 1)
		{
			continue;
		}

		um[now.A * 100000000 + now.B * 10000 + now.C] = 1;

		if (now.A != now.B)
		{
			if (now.A > now.B)
			{
				q.push({ now.A-now.B,now.B*2,now.C });

				//um[(now.A - now.B) * 100000000 + now.B * 2 * 10000 + now.C] = 1;


			}
			else if(now.B > now.A)
			{
				q.push({ now.A *2,now.B -now.A,now.C });

				//um[now.A * 2 * 100000000 + (now.B - now.A) * 10000 + now.C] = 1;


			}
		}

		if (now.A != now.C)
		{
			if (now.A > now.C)
			{
				q.push({ now.A - now.C,now.B,now.C*2 });

				//um[(now.A - now.C) * 100000000 + now.B * 10000 + now.C*2] = 1;


			}
			else if (now.C > now.A)
			{
				q.push({ now.A*2,now.B,now.C -now.A });

				//um[now.A * 2 * 100000000 + now.B * 10000 + (now.C-now.A)] = 1;


			}
		}


		if (now.B != now.C)
		{
			if (now.B > now.C)
			{
				q.push({ now.A,now.B-now.C,now.C * 2 });

				//um[now.A * 100000000 + (now.B - now.C) * 10000 + now.C * 2] = 1;


			}
			else if (now.C > now.B)
			{
				q.push({ now.A,now.B*2,now.C - now.B });

				//um[now.A * 100000000 + now.B*2 * 10000 + (now.C - now.B)] = 1;


			}
		}










	}
}


int main()
{
	int A, B, C;

	scanf("%d %d %d", &A, &B, &C);

	q.push({ A,B,C });
	
	bfs();
	
	if (state == 1)
	{
		printf("1");
	}
	else
	{
		printf("0");
	}

}