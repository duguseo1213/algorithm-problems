#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_TABLE 100019

struct NODE {

	int key;
	int value;
	NODE* next;

};

NODE pool[200001];
NODE HEAD[MAX_TABLE];

int pcnt;

int N, M;

int hashfunc(int value) {
	
	return value % MAX_TABLE;

}



int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		NODE* nd = &pool[pcnt];
		pcnt++;

		scanf("%d", &temp);
		int h;
		if (temp < 0) {
			h = hashfunc(-temp);
		}
		else {
			h = hashfunc(temp);
		}
		nd->value = temp;
		
		nd->next = HEAD[h].next;
		HEAD[h].next = nd;
		
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int temp;
		scanf("%d", &temp);
		int h;

		if (temp < 0) {
			h = hashfunc(-temp);
		}
		else {
			h = hashfunc(temp);
		}

		NODE* nd = HEAD[h].next;
		int state = 0;
		while (nd) {

			
			if (nd->value == temp) {
				printf("1\n");
				state = 1;
				break;
			}


			nd = nd->next;

		}
		if (state == 0) {
			printf("0\n");
		}

	}



}