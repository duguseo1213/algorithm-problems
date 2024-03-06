#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

struct student {
	string name;
	int a;
	int b;
	int c;
};
student qqq[100000];
bool cmp(student a, student b)
{
	if (a.a == b.a)
	{
		if (a.b == b.b)
		{
			if (a.c == b.c)
			{
				return a.name < b.name;
			}
			return a.c > b.c;
		}
		return a.b < b.b;
	}

	return a.a > b.a;
}


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> qqq[i].name >> qqq[i].a >> qqq[i].b >> qqq[i].c;

	}

	sort(qqq, qqq + N, cmp);
	for (int i = 0; i < N; i++)
	{
		cout << qqq[i].name << "\n";

	}
}