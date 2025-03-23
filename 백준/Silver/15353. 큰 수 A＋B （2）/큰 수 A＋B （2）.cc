#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char tb[1000000];

char ta[1000000];

char a[1000000];
char b[1000000];

char sum[100000];


int N;


int main() {

	scanf("%s %s", ta, tb);
	int i = 0;
	int alen=0;
	int blen=0;

	while (1) {
		if (ta[alen] == '\0') break;
		alen++;

	}
	while (1) {
		if (tb[blen] == '\0') break;
		blen++;
	}

	//printf("%d %d\n", alen, blen);

	for (int i = 0; i < alen; i++) {
		a[i] = ta[alen - 1 - i];
	}

	for (int i = 0; i < blen; i++) {
		b[i] = tb[blen - 1 - i];
	}

	
	int len;
	if (blen > alen) {
		len = blen;
	}
	else {
		len = alen;
	}

	for (int i = alen; i < len; i++) {
		a[i] = '0';
	}
	for (int i = blen; i < len; i++) {
		b[i] = '0';
	}

	for (int i = 0; i < len; i++) {

		sum[i] = a[i] + b[i]-'0'+sum[i];

		if (sum[i] > '9') {
			sum[i] -= 10;
			sum[i + 1] = 1;
		}


	}
	
	for (int i = 0; i < len; i++) {
		b[i] = sum[len - 1 - i];
	}
	if (sum[len] == 1) {
		printf("1%s", b);
	}
	else {


		printf("%s", b);
	}
}