#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N,M; //변하지 않는 값은 전역 처리
int a[10] = { 0, };
int b[10] = { 0, };
void func(int dep,int s)
{
	if (dep == M)
	{
		for (int i = 0; i < dep; i++)
		{
			
			printf("%d ", b[i]);

		}
		printf("\n");
		return;
	}
	dep++;
	for (int j = s; j < N; j++)
	{

		if (a[j] == 0)
		{
			a[j] = 1;
			b[dep - 1] = j + 1;


			func( dep ,j);
			a[j] = 0;
		}



	}

}

int main(void)

{
	 
	
	char q[30];
	scanf("%d %d", &N, &M);
	int dep = 0;
	
	func( dep,0);


}