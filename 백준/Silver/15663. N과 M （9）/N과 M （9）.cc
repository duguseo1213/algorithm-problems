#include <stdio.h>

int sort[10] = {0};
int tmp[10] = {0};
int exist[10] = {0};
int n = 0;
int m = 0;

void loop(int k) //그냥 순열 출력
{
	if(k==m)
	{
	for(int i = 0; i<m; i++) printf("%d ", tmp[i]);
	printf("\n");
	return;
	}
	
	int before = 0; 
	for(int i = 0; i<n; i++)
	{
		
		if(exist[i] == 0 && before != sort[i])
		{
			before = sort[i]; 
			exist[i] = 1;
			tmp[k] = sort[i];
			loop(k+1);
			exist[i] = 0;
			tmp[k] = 0;
		}
	}
}

int main(void)
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i<n; i++) scanf("%d", &sort[i]);
	
	int gap = n/2;
	int key = 0;
	int i, j;
	
	while(1==1)
	{
		if(gap%2==0) gap++;
		for(i = gap; i<n; i++)
		{
			key = sort[i];
			for(j=i-gap; j>=0; j=j-gap)
			{
				if(key<sort[j]) sort[j+gap] = sort[j];
				else break;
			}
			sort[j+gap] = key;
		}
		if(gap==1) break;
		gap /= 2;
	}
	
	loop(0);
	return 0;
}