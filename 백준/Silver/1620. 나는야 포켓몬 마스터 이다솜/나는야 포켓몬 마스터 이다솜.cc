#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_VALUE 10007


typedef unsigned long long ull;

using namespace std;

int N, M;
int pcnt = 0;

struct pokemon {


	int number;
	pokemon* next;
	char name[21];

};

pokemon pool[200000];
pokemon HEAD[MAX_VALUE];

char reverses[100001][21];

ull hashfunc(const char* str) {

	ull hash = 5381;

	int c;

	while (c = *str++) {

		hash = (((hash << 5) + c) + hash) % MAX_VALUE;


	}




	return hash % MAX_VALUE;


}

int change(char* str)
{
	int i, len;
	int sum, mul;

	sum = 0;
	mul = 1;

	for (i = 0; str[i]; i++);
	len = i;

	for (i = len - 1; i >= 0; i--)
	{
		sum += (str[i] - '0') * mul;
		mul *= 10;
	}

	return sum;
}

int main(void)
{
	scanf("%d %d", &N, &M);
	char str[21];
	for (int i = 1; i <= N; i++) {
		
		pcnt++;
		pokemon* temp=&pool[pcnt];
		scanf("%s", temp->name);
		temp->number = pcnt;
		ull hashnum = hashfunc(temp->name);

		temp->next = HEAD[hashnum].next;
		HEAD[hashnum].next = temp;

		strcpy(reverses[pcnt], temp->name);

	}

	for (int i = 0; i < M; i++)
	{
		scanf("%s", str);

		if ('0' < str[0] && str[0] <= '9')
		{
			int index = change(str);

			printf("%s\n", reverses[index]); /* ARR에 순서대로 저장했기 때문에 그대로 출력 */
		}
		else
		{
			ull h = hashfunc(str);
			pokemon* nd = HEAD[h].next;

			while (nd)
			{
				if (!strcmp(nd->name, str))
				{
					printf("%d\n", nd->number);
					break;
				}

				nd = nd->next;
			}
		}
	}



}