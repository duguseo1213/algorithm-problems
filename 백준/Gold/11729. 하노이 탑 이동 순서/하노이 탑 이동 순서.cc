#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int K;
vector<pair<int,int>> a;
void hanoi(int start,int des,int level)
{
	//K++;
	if (level == 1)
	{	
		a.push_back({ start,des });
		return;
	}

	if ((start == 1 && des == 3) || (des == 1 && start == 3))
	{
		hanoi(start, 2, level - 1);
		
		a.push_back({ start,des });
		hanoi(2, des, level - 1);
	}
	else if ((start == 2 && des == 1) || (des == 2 && start == 1))
	{
		hanoi(start, 3, level - 1);
		
		a.push_back({ start,des });
		hanoi(3, des, level - 1);
	}
	else if ((start == 3 && des == 2) || (des == 3 && start == 2))
	{
		hanoi(start, 1, level - 1);
		
		a.push_back({ start,des });
		hanoi(1, des, level - 1);
	}
	
	return;

}


int main()
{
	
	cin >> N;
	hanoi(1, 3, N);
	cout << a.size()<<endl;
	for (int i = 0; i < a.size(); i++)
	{
		printf("%d %d\n", a[i].first, a[i].second);
	}
}