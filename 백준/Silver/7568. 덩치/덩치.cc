#define _CRT_SECURE_NO_WARNINGS
#define P 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct human
{
	
	int a;
	int b;
	int num;
};


bool cmp(human a, human b)
{
	return a.a > b.a;
}
vector<human> vec;




int N;
int dat[500];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back({a, b,i});
	}

	sort(vec.begin(), vec.end(),cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vec[i].b < vec[j].b && vec[i].a < vec[j].a)
			{
				dat[vec[i].num]++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", dat[i]+1);
	}


}
