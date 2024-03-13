#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

struct NODE {

	int id;
	int value;
};

NODE nd[100001];
int index[100001];
int hn;

bool cmp(NODE a, NODE b)
{
	if (a.value == b.value)
	{
		return a.id > b.id;
	}

	return a.value > b.value;
}

void push(NODE a)
{
	hn++;
	nd[hn] = a;
	index[a.id] = hn;
	NODE temp;
	for (int i = hn; i > 1; i = i / 2)
	{
		if (cmp(nd[i], nd[i / 2])) break;

		temp = nd[i];
		nd[i] = nd[i / 2];
		nd[i / 2] = temp;

		index[nd[i].id] = i;
		index[nd[i/2].id] = i/2;
	}

}

NODE pop()
{
	NODE ret, temp;
	ret = nd[1];
	nd[1] = nd[hn];
	nd[hn].value = 2000000000;

	hn--;
	for (int i = 1; i * 2 <= hn;)
	{
		if (!cmp(nd[i], nd[i * 2]) && !cmp(nd[i], nd[i * 2 + 1]))
		{
			break;
		}

		else if (cmp(nd[i * 2+1], nd[i * 2]))
		{
			temp = nd[i * 2];
			nd[i * 2] = nd[i];
			nd[i] = temp;

			index[nd[i].id] = i;
			index[nd[i * 2].id] = i * 2;

			i = i * 2;

		}
		else
		{
			temp = nd[i * 2+1];
			nd[i * 2+1] = nd[i];
			nd[i] = temp;

			index[nd[i].id] = i;
			index[nd[i * 2+1].id] = i * 2+1;

			i = i * 2+1;

		}

	}

	return ret;

}

void update(NODE a)
{
	int udhn=index[a.id];

	nd[udhn].value = a.value;

	NODE temp;
	for (int i = udhn; i > 1; i = i / 2)
	{
		if (cmp(nd[i], nd[i / 2])) break;

		temp = nd[i];
		nd[i] = nd[i / 2];
		nd[i / 2] = temp;

		index[nd[i].id] = i;
		index[nd[i / 2].id] = i / 2;
	}

	for (int i = udhn; i * 2 <=hn ;)
	{
		if (!cmp(nd[i], nd[i * 2]) && !cmp(nd[i], nd[i * 2 + 1]))
		{
			break;
		}

		else if (cmp(nd[i * 2 + 1], nd[i * 2]))
		{
			temp = nd[i * 2];
			nd[i * 2] = nd[i];
			nd[i] = temp;

			index[nd[i].id] = i;
			index[nd[i * 2].id] = i * 2;

			i = i * 2;

		}
		else
		{
			temp = nd[i * 2 + 1];
			nd[i * 2 + 1] = nd[i];
			nd[i] = temp;

			index[nd[i].id] = i;
			index[nd[i * 2 + 1].id] = i * 2 + 1;

			i = i * 2 + 1;

		}

	}

}


int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= 100000; i++)
	{
		nd[i].value = 2000000000;
	}


	for (int i = 1; i <= N; i++)
	{
		int temp;
		scanf("%d", &temp);
		push({i, temp });
	}
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);

		if (temp == 2)
		{
			printf("%d\n", nd[1].id);
		}
		else
		{
			int a, b;
			scanf("%d %d", &a, &b);

			update({ a,b });
		}
	}
	
}