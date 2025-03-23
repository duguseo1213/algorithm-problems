#include <stdio.h>

#define MAX (10010)

typedef long long int ll;

#define NOTATION (100000000000000000)
#define NOT_COUNT (17) // ↑ 0의 개수

typedef struct st
{
	ll num[MAX]; // <-  // long 연산 때문에 MAX 보다 작은 값을 사용해도 된다.
	int len;
}BIG_NUMBER;

char A[MAX];
char B[MAX];
char ANSWER[MAX];

BIG_NUMBER bigPlus(BIG_NUMBER& a, BIG_NUMBER& b)
{
	BIG_NUMBER result = { 0 };
	int lenA, lenB, len;
	ll temp[MAX] = { 0 };

	lenA = a.len;
	lenB = b.len;
	len = (lenA > lenB) ? lenA : lenB;

	for (int i = 0; i < lenA; i++) temp[i] += a.num[i];
	for (int i = 0; i < lenB; i++) temp[i] += b.num[i];

	for (int i = 0; i < len; i++)
	{
		temp[i + 1] += (temp[i] / NOTATION);
		temp[i] %= NOTATION;
	}

	len++; // 자릿수가 오른 경우 체크
	while (len && temp[len] == 0) len--;
	len++;

	for (int i = 0; i < len; i++) result.num[i] = temp[i];

	result.len = len;

	return result;
}

void makeNumber(BIG_NUMBER& big, char number[MAX])
{
	char reverse[MAX] = { 0 };
	int len, nLen;

	for (len = 0; number[len]; len++);

	for (int i = 0; i < len; i++) reverse[i] = number[len - i - 1] - '0';

	nLen = 0;
	for (int i = 0; i < len; i += NOT_COUNT)
	{
		ll tmp = 0;
		for (int k = i + NOT_COUNT - 1; k >= i; k--) tmp = tmp * 10 + reverse[k];

		big.num[nLen++] = tmp;
	}

	big.len = nLen;
}

void changeIntToChar(BIG_NUMBER& big, char answer[MAX])
{
	char temp[MAX] = { 0 };

	int len = big.len;

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		for (int k = 0; k < NOT_COUNT; k++)
		{
			temp[count++] = (big.num[i] % 10);
			big.num[i] /= 10;
		}
	}

	while (count && temp[count] == 0) count--;
	count++;

	temp[count] = 0;

	int half = count / 2;
	for (int i = 0; i < half; i++)
	{
		char tmp = temp[i];
		temp[i] = temp[count - 1 - i];
		temp[count - 1 - i] = tmp;
	}

	for (int i = 0; i < count; i++) answer[i] = temp[i] + '0';

	answer[count] = 0;
}

int main()
{
	scanf("%s %s", A, B);

	BIG_NUMBER a, b, result;

	makeNumber(a, A);
	makeNumber(b, B);

	result = bigPlus(a, b);

	changeIntToChar(result, ANSWER);

	printf("%s\n", ANSWER);

	return 0;
}