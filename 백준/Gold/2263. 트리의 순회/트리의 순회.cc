#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
vector<int> arr;

int inorder[100000];
int postorder[100000];

int tree[100000][2];


void maketree(int start,int end,int pe)
{
    if (start > end)
    {
	    return;
    }
	if (start == end)
	{
		printf("%d ",inorder[end]);
		return;
	}
	int root = postorder[end-pe];

	printf("%d ",root);


	int inorder_root;

	for (int i = start; i <= end; i++)
	{
		if (inorder[i] == root)
		{
			inorder_root = i;
			maketree(start, inorder_root-1,pe);
			maketree(inorder_root+1,end,pe+1);


		}
	}




}


int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &inorder[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &postorder[i]);
	}

	maketree(0,N-1,0);




}