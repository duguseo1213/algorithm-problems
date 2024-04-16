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

int N, C;

struct prob {

	int start;
	int des;
	int cnt;

};

vector<prob> probs;

int dat[10000];
int sum;


bool cmp(prob a, prob b)
{
	return a.des - a.start < b.des - b.start;
}

int main()
{
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++)
	{
		dat[i] = C;
	}


	int good;
	int answer = 0;

	scanf("%d", &good);

	for (int i = 0; i < good; i++)
	{
		prob p;
		scanf("%d %d %d", &p.start, &p.des, &p.cnt);
		probs.push_back(p);

	}
	sort(probs.begin(), probs.end(), cmp);


	for (int i = 0; i < probs.size(); i++)
	{
		int tempmin=987654321;
		for (int j = probs[i].start; j < probs[i].des; j++)
		{
			tempmin = min(tempmin, dat[j]);
		}

		tempmin=min(tempmin, probs[i].cnt);
		answer = answer + tempmin;
		for (int j = probs[i].start; j < probs[i].des; j++)
		{
			
			dat[j] -= tempmin;
			

		}
	}

	for (int i = 1; i <= N; i++)
	{
		//P("%d ", dat[i]);
	}
	printf("%d", answer);

	   	 
}