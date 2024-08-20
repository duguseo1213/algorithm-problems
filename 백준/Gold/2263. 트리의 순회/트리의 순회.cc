#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;

vector<int> inorder;
vector<int> postorder;


int dat[100010];

void dfs(int ileft,int iright,int pleft,int pright) {

	if (iright <= ileft) {
		return;
	}

	printf("%d ", postorder[pright - 1]);

	


	int temp = dat[postorder[pright - 1]];

	dfs(ileft,temp,pleft,pleft+temp-ileft); //왼쪽

	dfs(temp+1,iright,pleft+temp-ileft,pright-1); //오른쪽

}

int main() {
	scanf("%d", &N);
	int temp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		inorder.push_back(temp);

		dat[temp] = inorder.size() - 1;
		//printf("%d %d\n", temp, inorder.size() - 1);
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		postorder.push_back(temp);
	}

	dfs(0, inorder.size(), 0, inorder.size());

}