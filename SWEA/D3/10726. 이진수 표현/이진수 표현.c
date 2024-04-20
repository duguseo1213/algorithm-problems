#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int N;



int main() {


	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{

		int bit, target;
		scanf("%d %d", &bit, &target);

		int num = (1 << bit) - 1;

		//printf("%d\n", num & target);
		if ((num & target) == num)
		{
			printf("#%d ON\n",t);
		}
		else
		{
			printf("#%d OFF\n",t);
		}
	}
	
}
