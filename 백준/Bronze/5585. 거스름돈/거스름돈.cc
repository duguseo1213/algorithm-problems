
#define _CRT_SECURE_NO_WARNINGS
#define P 

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

int N;

int main()
{
	scanf("%d", &N);

	int a = 1000 - N;

	int answer = 0;

	answer += a / 500;
	a = a % 500;

	answer += a / 100;
	a = a % 100;

	answer += a / 50;
	a = a % 50;

	answer += a / 10;
	a = a % 10;

	answer += a / 5;
	a = a % 5;

	answer += a / 1;
	a = a % 1;

	printf("%d", answer);




}
